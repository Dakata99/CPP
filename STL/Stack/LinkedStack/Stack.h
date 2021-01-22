#pragma once

template<class T>
class Stack
{
private:
    struct StackBox
    {
        T data;
        StackBox* next;
        StackBox(const T& _data, StackBox* _next):data(_data), next(_next){}
    };

    StackBox* topPtr; 
private:
    void copy(const Stack<T>&);
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
