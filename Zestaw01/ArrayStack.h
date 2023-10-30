// Mateusz Kałwa

#ifndef ARRAY_STACK
#define ARRAY_STACK

#include <stdexcept>

template <class T, int N>
class ArrayStack {
private:
    T *data = nullptr;
    int stack_top = 0;

public:
    ArrayStack() : data(new T[N]) {}
    ~ArrayStack() {
        delete[] data;
    }
    template <class U> // Uniwersalne referencje
    void push(U&& x) // Wstawia element x na stos
    {
        if (stack_top < N)
            *(data + stack_top++) = std::forward<U>(x);
        else 
            throw std::overflow_error("Stack is full");
    } 

    T pop() // Usuwa element ze stosu i zwraca jego wartość
    {
        if (!empty()) 
            return *(data + --stack_top);
        else 
            throw std::underflow_error("Stack is empty");
    } 

    T& top() // Zwraca referencję do najmłodszego elementu
    {
        if (!empty()) 
            return *(data + stack_top - 1);
        else 
            throw std::underflow_error("Stack is empty");
    } 

    int size() // Zwraca liczbę elementów na stosie
    {
        return stack_top;
    } 

    bool empty() // Sprawdza czy stos jest pusty
    {
        return stack_top > 0 ? false : true;
    } 
};

#endif // !ARRAY_STACK