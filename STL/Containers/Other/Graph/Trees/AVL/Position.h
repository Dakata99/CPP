#ifndef _POSITION_H_
#define _POSITION_H_

#include "AVL.h"

template <class T>
class Position
{
private:
    //typedef typename AVL<T>::N
    typename AVL<T>::Node *&current;

public:
    Position(typename AVL<T>::Node *&);

    Position left(void) const;
    Position right() const;

    const T& operator* (void) const;
    
    bool empty(void) const;

    const T& get(void) const;
    void set(const T&);
};

#include "Position.cpp"

#endif