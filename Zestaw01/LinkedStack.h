// Mateusz Kałwa

#ifndef LINKED_STACK
#define LINKED_STACK

#include <stdexcept>

template <class T>
struct Node
{
    T data;
    Node* next;
    Node(T data) : data(data), next(nullptr) {}
};


template <class T, int N>
class LinkedStack {
private:
    Node<T>* top_;
    int size_ = 0;

public:
    LinkedStack() : top_(nullptr) {}

    template <class U> // Uniwersalne referencje
    void push(U&& x) // Wstawia element x na stos
    {
        if (size_ == N)
            throw std::overflow_error("Stack is full");
        Node<T>* ptr = new Node<T>(std::forward<U>(x));
        ptr->next = top_;
        top_ = ptr;
        ++size_;
    }

    T pop() // Usuwa element ze stosu i zwraca jego wartość
    {
        Node<T>* ptr;
        if (top_ == nullptr)
            throw std::underflow_error("Stack is empty");

        T data = top_->data;

        ptr = top_;
        top_ = top_->next;

        --size_;
        delete ptr;
        return data;
    }

    T& top() // Zwraca referencję do najmłodszego elementu
    {
        if (!empty())
            return top_->data;
        else
            throw std::underflow_error("Stack is empty");
    }

    int size() // Zwraca liczbę elementów na stosie
    {
        return size_;
    }

    bool empty() // Sprawdza czy stos jest pusty
    {
        return size_ > 0 ? false : true;
    }
};

#endif // !LINKED_STACK