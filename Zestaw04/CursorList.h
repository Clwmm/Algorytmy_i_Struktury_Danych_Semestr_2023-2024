// Mateusz Kałwa

#ifndef CURSOR_LIST
#define CURSOR_LIST

#include <stdexcept>


template <class T, int N>
class CursorList {
private:
    struct Node
    {
        T value;
        int next;
    };
    Node* arr = nullptr;
    int head;
    int tail;
    int array_size = N;
    int spare;

public:

    struct Iterator
    {
        int current;
        Node* arr;
        Iterator(const int& idx, Node* arr) : current(idx), arr(arr) {}

        T& operator*() { return this->arr[current].value; }
        Iterator& operator++()
        {
            this->current = this->arr[current].next;
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

    CursorList() // DEFAULT CONSTRUCTOR
    {
        arr = new Node[N];
        this->clear();
    }

    CursorList(CursorList& other) // COPY CONSTRUCTOR
        : CursorList()
    {
        auto it = other.begin();
        for (; it != other.end(); ++it)
            this->push_back(*it);
    }

    CursorList(CursorList&& other) // MOVE CONSTRUCTOR
        : arr(other.arr), head(other.head), tail(other.tail), array_size(other.array_size), spare(other.spare) {}

    template <class U>
    void push_front(U&& x) // Dołącza element na początek listy
    {
        if (this->array_size == N)
            throw std::overflow_error("List is full");

        arr[spare].value = std::forward<U>(x);
        int sec = head;
        head = spare;
        spare = arr[spare].next;
        arr[head].next = sec;
        if (array_size == 0)
            tail = head;
        ++array_size;
    }
    T pop_front() // Usuwa i zwraca element z początku listy
    {
        if (this->array_size <= 0)
            throw std::out_of_range("List is empty");

        T x = arr[head].value;
        int new_spare = head;
        head = arr[head].next;
        arr[new_spare].next = spare;
        spare = new_spare;
        --array_size;
        if (this->array_size == 0)
        {
            head = -1;
            tail = -1;
        }
        return x;
    }

    template <class U>
    void push_back(U&& x) // Dołącza element na koniec listy
    {
        if (this->array_size == N)
            throw std::overflow_error("List is full");

        arr[spare].value = std::forward<U>(x);
        arr[tail].next = spare;
        tail = spare;
        spare = arr[spare].next;
        arr[tail].next = -1;
        if (array_size == 0)
            head = tail;
        ++array_size;
    }
    T pop_back() // Usuwa i zwraca element z końca listy
    {
        if (this->array_size <= 0)
            throw std::out_of_range("List is empty");

        T x = arr[tail].value;
        int new_spare = tail;
        int n = head;

        if (n == tail)
        {
            arr[new_spare].next = spare;
            spare = new_spare;
            head = -1;
            tail = -1;
        }
        else
        {
            while (arr[n].next != tail)
                n = arr[n].next;
            tail = n;
            arr[new_spare].next = spare;
            arr[tail].next = -1;
            spare = new_spare;
        }
        --array_size;

        return x;
    }
    int size() // Zwraca liczbę elementów w liście
    {
        return this->array_size;
    }
    bool empty() // Zwraca `true` gdy lista jest pusta
    {
        return array_size == 0;
    }
    void clear() // Czyści listę
    {
        this->head = -1;
        this->tail = -1;
        this->array_size = 0;
        this->spare = 0;

        for (int i = 0; i < N - 1; ++i)
        {
            arr[i].value = 0;
            arr[i].next = i + 1;
        }
        arr[N - 1].value = 0;
        arr[N - 1].next = -1;
    }
    Iterator find(int x) // Zwraca pozycję pierwszego elementu o wartości x
    {
        Iterator it = this->begin();
        for (; it != this->end(); ++it)
            if (*it == x)
                return it;
        throw std::out_of_range("Element not found");
    }
    Iterator erase(Iterator it) // Usuwa it zwraca element na pozycji `it`
    {
        if (this->array_size <= 0)
            throw std::out_of_range("List is empty");

        if (it == this->begin)
        {
            this->pop_front();
            return this->begin();
        }
        else
        {
            int n = this->head;
            while (arr[n].next != it.current)
                n = arr[n].next;
            arr[n].next = arr[it.current].next;

            int new_spare = it.current;
            arr[new_spare].next = spare;
            spare = new_spare;

            --array_size;

            return Iterator(this->arr[n].next, this->arr);
        }
    }

    template <class U>
    Iterator insert(Iterator it, U&& x) // Wstawia element `x` przed pozycję `it`
    {
        if (this->array_size == N)
            throw std::overflow_error("List is full");

        if (it == this->begin())
        {
            this->push_front(std::forward<U>(x));
            return this->begin();
        }
        else
        {
            int n = this->head;
            while (arr[n].next != it.current)
                n = arr[n].next;
            int node = spare;
            spare = arr[spare].next;

            arr[node].value = std::forward<U>(x);
            arr[node].next = it.current;
            arr[n].next = node;
            ++array_size;
            return Iterator(node, this->arr);
        }
            
    }
    int remove(int x) // Usuwa wystąpienia `x` i zwraca ich liczbę
    {
        int number = 0;
        CursorList<T, N>::Iterator it = this->begin();
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

    Iterator begin() { return Iterator(this->head, this->arr); }
    Iterator end() { return Iterator(-1, this->arr); }

};


#endif // !CURSOR_LIST