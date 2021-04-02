#include "Iterator.h"

template<class T>
Iterator<T>::Iterator():pointer(nullptr){}

template<class T>
Iterator<T>::Iterator(T* ptr):pointer(ptr){}

template<class T>
Iterator<T>& Iterator<T>::operator++()
{
    this->pointer++;
    return *this;
}

template<class T>
Iterator<T>& Iterator<T>::operator--()
{
    this->pointer--;
    return *this;
}

template<class T>
Iterator<T>& Iterator<T>::operator++(int)
{
    this->pointer++;
    return *this;
}

template<class T>
Iterator<T>& Iterator<T>::operator--(int)
{
    this->pointer--;
    return *this;
}

template<class T>
bool operator==(const Iterator<T>& first, const Iterator<T>& second)
{
    return (first.pointer == second.pointer);
}

template<class T>
bool operator!=(const Iterator<T>& first, const Iterator<T>& second)
{
    return (first.pointer != second.pointer);
}

template<class T>
bool Iterator<T>::operator==(const Iterator& other)
{
    return pointer == other.pointer;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator& other)
{
    return pointer != other.pointer;
}

template<class T>
T& Iterator<T>::operator*()
{
    return *pointer;
}