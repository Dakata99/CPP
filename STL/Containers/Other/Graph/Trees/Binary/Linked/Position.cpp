#include "Position.h"

template <class T>
Position<T>::Position(typename BTree<T>::Node*&root):current(root) {}

template <class T>
Position<T> Position<T>::left() const { assert(current != nullptr); return Position<T>(current->left); }

template <class T>
Position<T> Position<T>::right() const { assert(current != nullptr); return Position<T>(current->right); }

template <class T>
T Position<T>::operator*() const { assert(current != nullptr); return current->value; }

template <class T>
bool Position<T>::empty() const { return current == nullptr; }

template <class T>
T Position<T>::get()const { assert(current != nullptr); return current->value; }

template <class T>
void Position<T>::set(const T& x) 
{ 
    if(current == nullptr) current = new typename BTree<T>::Node(nullptr, x, nullptr);
    else current->value = x; 
}
