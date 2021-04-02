#pragma once

template<class T>
class Iterator;

template<class T>
class SLList
{
private:
    friend Iterator<T>;

    struct Node
    {
        T data;
        Node* next;
        Node(const T& = T(), Node* = nullptr);
    };
    
    Node *head;
private:
    void copy(const SLList<T>&);
    void clear();
public:
    SLList();
    SLList(const SLList<T>&);
    ~SLList();

    SLList& operator=(const SLList<T>&);

    bool empty()const;

    void push_front(const T&);
    void pop_front();

    const T& front()const;
    void reverse();

    void print()const;

    Iterator<T> begin();
    Iterator<T> end();
};

#include "SLList.cpp"
