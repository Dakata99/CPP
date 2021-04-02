#pragma once
#include "BST.h"

template <class T>
class Position
{
private:
    typename BST<T>::Node *&current;

public:
    Position(typename BST<T>::Node *&);
    Position left() const;
    Position right() const;
    T operator*() const;
    bool empty() const;
    T get()const;
    void set(const T&);
};

#include "Position.cpp"