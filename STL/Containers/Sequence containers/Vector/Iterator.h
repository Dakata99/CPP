#pragma once

template<class T>
class Iterator
{
private:
    T* pointer;

public:
    Iterator();
    Iterator(T*);
    
    Iterator& operator++();
    Iterator& operator--();
    Iterator& operator++(int);
    Iterator& operator--(int);

    template<class E>
    friend bool operator==(const Iterator<E>&, const Iterator<E>&);
    template<class E>
    friend bool operator!=(const Iterator<E>&, const Iterator<E>&);

    bool operator==(const Iterator& other);
    bool operator!=(const Iterator& other);
    T& operator*();
};
