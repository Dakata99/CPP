#include "Stack.h"
#include <cassert>

template<class T>
void Stack<T>::copy(const Stack<T>& other)
{
    StackBox* temp = other.topPtr;
}

template<class T>
Stack<T>::Stack():topPtr(nullptr){}

template<class T>
Stack<T>::Stack(const Stack<T>& other)
{
    copy(other);
}

template<class T>
Stack<T>::~Stack(){}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other)
    {
        copy(other);
    }
    return *this;
}

template<class T>
void Stack<T>::push(const T& element)
{
    StackBox* newEl = new StackBox(element, nullptr);
    newEl->next = topPtr;
    topPtr = newEl;   
}

template<class T>
void Stack<T>::pop()
{
    if(topPtr != nullptr)
        topPtr = topPtr->next;
}

template<class T>
bool Stack<T>::empty()const
{
    return topPtr == nullptr;
}

template<class T>
const T& Stack<T>::top()const
{
    assert(topPtr != nullptr);
    return topPtr->data;
}

template<class T>
void Stack<T>::print()const
{
    StackBox* curr = topPtr;
    std::cout << "[ ";
    while (curr != nullptr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << "]\n";
}