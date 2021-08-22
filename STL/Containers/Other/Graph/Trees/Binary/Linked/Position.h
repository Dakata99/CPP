#ifndef _POSITION_H_
#define _POSITION_H_

#include "BTree.h"

template <class T>
class Position
{
private:
    typename BTree<T>::Node*& current;

public:
    Position(typename BTree<T>::Node*&);

    Position left(void) const;
    Position right(void) const;

    const T& operator* (void) const;

    bool empty(void) const;

    const T& get(void) const;
    void set(const T&);
};

#include "Position.cpp"

#endif