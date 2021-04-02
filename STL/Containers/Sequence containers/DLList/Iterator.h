#pragma once
#include "DLList.h"

template<class T>
class Iterator
{
private:
    typename DLList<T>::Node* iter;
public:
    Iterator(typename DLList<T>::Node* = nullptr);

    Iterator<T>& operator++();
    Iterator<T> operator++(int);
    Iterator<T>& operator--();
    Iterator<T> operator--(int);

    bool operator==(const Iterator<T>&)const;
    bool operator!=(const Iterator<T>&)const;

    T& operator*()const;
};
