#pragma once
#include <stack>
#include "BTree.h"
#include "Position.h"

template<class T>
class Iterator
{
private:
    friend Position<T>;
    std::stack<Position<T>> st;  

public:
    Iterator(Position<T>, bool);
    T operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator&) const;
};

#include "Iterator.cpp"