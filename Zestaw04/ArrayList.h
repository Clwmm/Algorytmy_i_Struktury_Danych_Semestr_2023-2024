// Mateusz Kałwa

#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <iostream>

template <class T, int N>
class ArrayList {
private:
	int array_size = 0;
	T *arr = nullptr;

public:

	ArrayList() // DEFAULT CONSTRUCTOR
	{
		arr = new T[N];
	}

	ArrayList(ArrayList& other) // COPY CONSTRUCTOR
		: ArrayList()
	{
		auto it = other.begin();
		for (; it != other.end(); ++it)
			this->push_back(*it);
	}

	ArrayList(ArrayList&& other) // MOVE CONSTRUCTOR
		: arr(other.arr), array_size(other.array_size) {}


	struct Iterator
	{
		int current;
		T* arr;
		Iterator(const int& idx, T* arr) : current(idx), arr(arr) {}

		T& operator*() { return this->arr[this->current]; }
		Iterator& operator++()
		{
			++current;
			return *this;
		}
		bool operator==(const Iterator& other) const
		{
			return this->current == other.current;
		}
		bool operator!=(const Iterator& other) const
		{
			return this->current != other.current;
		}
	};

	template <class U>
	void push_front(U&& x) // Dołącza element na początek listy
	{
		if (this->array_size == N)
			throw std::overflow_error("List is full");

		++array_size;

		for (int i = array_size - 1; i > 0; --i)
			arr[i] = arr[i - 1];

		arr[0] = std::forward<U>(x);
	}
	T pop_front() // Usuwa i zwraca element z początku listy
	{
		if (this->array_size <= 0)
			throw std::out_of_range("List is empty");
		T x = arr[0];

		--array_size;

		for (int i = 0; i < array_size; ++i)
			arr[i] = arr[i + 1];

		return x;
	}

	template <class U>
	void push_back(U&& x) // Dołącza element na koniec listy
	{
		if (this->array_size == N)
			throw std::overflow_error("List is full");

		arr[array_size++] = std::forward<U>(x);
	}
	T pop_back() // Usuwa i zwraca element z końca listy
	{
		if (this->array_size <= 0)
			throw std::out_of_range("List is empty");

		return arr[array_size-- - 1];
	}
	int size() // Zwraca liczbę elementów w liście
	{
		return array_size;
	}
	bool empty() // Zwraca `true` gdy lista jest pusta
	{
		return array_size == 0;
	}
	void clear() // Czyści listę
	{
		array_size = 0;
	}
	Iterator find(int x) // Zwraca pozycję pierwszego elementu o wartości x
	{
		Iterator it = this->begin();
		Iterator end_ = this->end();
		for (; it != end_; ++it)
			if (*it == x)
				return it;
		throw std::out_of_range("Element not found");
	}
	Iterator erase(Iterator it) // Usuwa i zwraca element na pozycji `it` i zwraca iterator do kolejnego elementu
	{
		--array_size;
		for (int i = it.current; i < array_size; ++i)
			arr[i] = arr[i + 1];

		return ++it;
	}

	template <class U>
	Iterator insert(Iterator it, U&& x) // Wstawia element `x` przed pozycję `i`
	{
		if (this->array_size == N)
			throw std::overflow_error("List is full");

		++array_size;
		for (int i = array_size - 1; i > it.current; --i)
			arr[i] = arr[i - 1];

		arr[it.current] = std::forward<U>(x);
		return it;
	}
	int remove(int x) // Usuwa wystąpienia `x` i zwraca ich liczbę
	{
		int number = 0;
		auto it = this->begin();
		auto end_ = this->end();
		for (; it != this->end();)
		{
			if (*it == x)
			{
				++number;
				it = this->erase(it);
			}
			else
				++it;
		}
		return number;
	}

	Iterator begin() { return Iterator(0, this->arr); }
	Iterator end() { return Iterator(this->array_size, this->arr); }

};


#endif // !ARRAY_LIST
