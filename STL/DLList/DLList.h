#pragma once

template<class T>
class Iterator;

template<class T>
class DLList
{
private:
    friend class Iterator<T>;
    struct Node
    {
        T data;
        Node* previous, *next;
        Node(Node* = nullptr, const T = T(), Node* = nullptr);
    };
    
    Node* head, *tail;
private:
    void copy(const DLList<T>&);
    void clear();

public:
    DLList();
    DLList(const DLList<T>&);
    ~DLList();

    DLList& operator=(const DLList<T>&);

    bool empty()const;

    const T& front()const;
    const T& back()const;

    void push_front(const T&);
    void pop_front();
    void push_back(const T&);
    void pop_back();

    void print()const;

    Iterator<T> begin();
    Iterator<T> end();
};

#include "DLList.cpp"
#include "Iterator.cpp"