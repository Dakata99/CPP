#pragma once
#include "AVL.h"

template <class T>
class Position
{
private:
    typename AVL<T>::Node *&current;

public:
    Position(typename AVL<T>::Node *&);
    Position left() const;
    Position right() const;
    T operator*() const;
    bool empty() const;
    T get()const;
    void set(const T&);
};

#include "Position.cpp"