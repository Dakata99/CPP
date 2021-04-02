#pragma once
#include "BTree.h"

template <class T>
class Position
{
private:
    typename BTree<T>::Node *&current;

public:
    Position(typename BTree<T>::Node *&);
    Position left() const;
    Position right() const;
    T operator*() const;
    bool empty() const;
    T get()const;
    void set(const T&);
};

#include "Position.cpp"