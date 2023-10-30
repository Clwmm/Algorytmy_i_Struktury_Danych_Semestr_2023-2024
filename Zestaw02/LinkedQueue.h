// Mateusz Kałwa

#ifndef LINKED_QUEUE
#define LINKED_QUEUE

#include <stdexcept>

template<class T>
struct Node {
    Node(T data)
    {
        val = data;
    }
    T val;
    Node* next = nullptr;
};

template<class T>
class LinkedQueue {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int no_elements = 0; // liczba elementów
    int max_size = 0;
public:
    LinkedQueue(int max_size) { this->max_size = max_size; }
    ~LinkedQueue() { clear(); } // Destruktor
    template <class U>
    void push(U&& x) // Wstawia element x do kolejki (także enqueue)
    {
        if (no_elements == max_size)
            throw std::overflow_error("Stack is full");

        Node<T>* ptr = new Node<T>(x);

        if (tail == nullptr)
            head = tail = ptr;

        tail->next = ptr;
        tail = ptr;
        ++no_elements;
    }
    T pop() // Usuwa element z kolejki i zwraca jego wartość (dequeue)
    {
        if (head == nullptr)
            throw std::underflow_error("Stack is empty");

        T x = head->val;
        Node<T>* ptr = head;
        head = head->next;
        delete ptr;

        if (head == nullptr)
            tail = nullptr;

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
        while (!empty()) {
            pop();
        }
    }
};


#endif // !LINKED_QUEUE
