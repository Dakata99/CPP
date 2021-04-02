#pragma once

template<class T>
class Iterator
{
private:
    typename SLList<T>::Node* iter;
public:
    Iterator(typename SLList<T>::Node* = nullptr);

    Iterator& operator++();
    Iterator operator++(int);

    bool operator==(const Iterator<T>&)const;
    bool operator!=(const Iterator<T>&)const;

    T& operator*()const;
};

#include "Iterator.cpp"
