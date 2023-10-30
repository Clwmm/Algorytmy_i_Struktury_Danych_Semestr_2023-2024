// Mateusz Kałwa

#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include <stdexcept>

template<class T>
class ArrayQueue {
private:
    T* data = nullptr;
    int head = 0; // indeks tablicy w którym znajduje się najstarszy element
    int tail = 0; // indeks tablicy pod którym zostanie dodany kolejny element
    int no_elements = 0; // liczba elementów
    int max_size = 0;
public:
    ArrayQueue(int max_size) {
        this->max_size = max_size;
        data = new T[this->max_size];
    }
    ~ArrayQueue() { delete[] data; } // Destruktor
    template <class U>
    void push(U&& x) // Wstawia element x do kolejki (także enqueue)
    {
        if (no_elements == max_size)
            throw std::overflow_error("Queue is full");
        data[tail++] = std::forward<U>(x);
        tail = tail % max_size;
        ++no_elements;
    }
    T pop() // Usuwa element z kolejki i zwraca jego wartość (dequeue)
    {
        if (no_elements == 0)
            throw std::underflow_error("Queue is empty");
        T x = data[head++];

        head = head % max_size;

        --no_elements;
        return x;
    }
    int size() // Zwraca liczbę elementów w kolejce
    {
        return no_elements;
    }
    bool empty() // Sprawdza czy kolejka jest pusta
    {
        return no_elements == 0;
    }
    void clear() // Czyści kolejke
    {
        head = 0;
        tail = 0;
        no_elements = 0;
    }
};

#endif // !ARRAY_QUEUE