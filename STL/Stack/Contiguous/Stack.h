#pragma once

template<class T>
class Stack
{
private:
    T* data;
    size_t topIndex, size;
private:
    void copy(const Stack<T>&);
    void clear();
    void resize(const size_t);
public:
    Stack();
    Stack(const Stack<T>&);
    ~Stack();

    Stack& operator=(const Stack<T>&);

    void push(const T&);
    void pop();
    bool empty()const;
    const T& top()const;

    void print()const;
};

#include "Stack.cpp"
