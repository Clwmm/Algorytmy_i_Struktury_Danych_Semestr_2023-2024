// Mateusz Kałwa

#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdexcept>

template<class T>
class LinkedList {
    struct Node {
        Node(T& val = 0, Node* left = nullptr, Node* right = nullptr)
            : val(val), prev(left), next(right) {}
        Node(T&& val = 0, Node* left = nullptr, Node* right = nullptr)
            : val(val), prev(left), next(right) {}
        T val;
        Node* prev;
        Node* next;
    };

    Node* guard;
    size_t listSize = 0;

    template <class U>
    void insertBetween(Node* left, U&& x, Node* right)
    {
        Node* node = new Node(std::forward<U>(x), left, right);
        left->next = node;
        right->prev = node;
        ++this->listSize;
    }

    T popBetween(Node* left, Node* right)
    {
        --this->listSize;
        Node* center = left->next;
        T val = center->val;
        delete center;
        left->next = right;
        right->prev = left;
        return val;
    }


public:
    struct Iterator
    {
        Node* current;
        Iterator(Node* node) : current(node) {}

        T& operator*() { return this->current->val; }
        Iterator& operator++()
        {
            this->current = this->current->next;
            return *this;
        }
        Iterator& operator--()
        {
            this->current = this->current->prev;
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

    LinkedList()
    {
        this->guard = new Node(0, nullptr, nullptr);
        this->guard->next = this->guard;
        this->guard->prev = this->guard;
    }

    LinkedList(LinkedList& other) // COPY CONSTRUCTOR
        : LinkedList()
    {
        LinkedList<T>::Iterator it = other.begin();
        for (; it != other.end(); ++it)
            this->push_back(*it);
    }

    LinkedList(LinkedList&& other) // MOVE CONSTRUCTOR
        : guard(other.guard), listSize(other.listSize) { }

    // FRONT METHODS
    template <class U>
    void push_front(U&& x) // Dołącza element na początek listy
    {
        this->insertBetween(guard, std::forward<U>(x), guard->next);
    }
    T pop_front() // Usuwa i zwraca element z początku listy
    {
        if (this->listSize == 0)
            throw std::underflow_error("Stack is empty");
        return popBetween(guard, guard->next->next);
    }

    // BACK METHODS
    template <class U>
    void push_back(U&& x) // Dołącza element na koniec listy
    {
        this->insertBetween(guard->prev, std::forward<U>(x), guard);
    }
    T pop_back() // Usuwa i zwraca element z końca listy
    {
        if (this->listSize == 0)
            throw std::underflow_error("Stack is empty");
        return this->popBetween(guard->prev->prev, guard);
    }

    Iterator find(const T& x)// Wyszukuje element o wartości `x`
                             // i zwraca jego pozycję
    {
        LinkedList<T>::Iterator it = this->begin();
        for (; it != this->end(); ++it)
            if (*it == x)
                return it;
        throw std::out_of_range("Element not found");
    }

    Iterator erase(Iterator it)// Usuwa element wskazywany przez iterator 
                               // i zwraca iterator do kolejnego elementu

    {
        LinkedList<T>::Iterator next = it.current->next;
        this->popBetween(it.current->prev, it.current->next);
        return next;
    }

    template <class U>
    Iterator insert(Iterator it, U&& x)// Wstawia element x przed pozycję it 
                                       // i zwraca pozycję x
    {
        this->insertBetween(it.current->prev, std::forward<U>(x), it.current);
        return Iterator(it.current->prev);
    }

    int remove(const T& x) // Usuwa wystąpienia x i zwraca ich liczbę
    {
        int number = 0;
        LinkedList<T>::Iterator it = this->begin();
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

    int size() // Zwraca liczbę elementów w liście
    {
        return this->listSize;
    }

    bool empty() // Zwraca 'true' gdy lista jest pusta
    {
        return this->size() == 0;
    }
    void clear() // Czyści listę
    {
        while (!this->empty())
            this->pop_back();
    }

    Iterator begin() { return Iterator(guard->next); } // Zwraca iterator na pierwszy element
    Iterator end() { return Iterator(guard); } // Zwraca iterator na koniec listy,
                                               // czyli za ostatnim elementem

};


#endif // !LINKED_LIST
