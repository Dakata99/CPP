#include "SLList.h"
#include <cassert>

template<class T>
SLList<T>::Node::Node(const T& _data, Node* _next):data(_data), next(_next){}

template<class T>
void SLList<T>::copy(const SLList<T>& other)
{
    Node* otherCurr = other.head;
    head = new Node(otherCurr->data, nullptr);
    otherCurr = otherCurr->next;
    Node* curr = head;
    while(otherCurr != nullptr)
    {
        curr->next = new Node(otherCurr->data, nullptr);
        otherCurr = otherCurr->next;
        curr = curr->next;
    }
}

template<class T>
void SLList<T>::clear()
{
    Node* curr = head;
    while (head != nullptr)
    {
        head = head->next;
        delete curr;
        curr = head;
    }
}

template<class T>
SLList<T>::SLList():head(nullptr){}

template<class T>
SLList<T>::SLList(const SLList<T>& other):head(nullptr) { copy(other); }

template<class T>
SLList<T>::~SLList() { clear(); }

template<class T>
SLList<T>& SLList<T>::operator=(const SLList<T>& other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

template<class T>
bool SLList<T>::empty()const { return head == nullptr; }

template<class T>
void SLList<T>::push_front(const T& element)
{
    if(head == nullptr) head = new Node(element, nullptr);
    else { Node* newNode = new Node(element, head); head = newNode; }
}

template<class T>
void SLList<T>::pop_front()
{
    assert(head != nullptr);

    Node* curr = head;
    head = head->next;
    delete curr;
}

template<class T>
const T& SLList<T>::front()const { return head->data; }

template<class T>
void SLList<T>::reverse()
{
    if(head == nullptr) return;

    Node *prev = nullptr, *curr, *curr_head = head;
    while (curr_head != nullptr)
    {
        curr = curr_head;
        curr_head = curr_head->next;
        curr->next = prev;
        prev = curr;
    }
    head = curr;
}

template<class T>
void SLList<T>::print()const
{
    Node* curr = head;
    std::cout << "[ ";
    while (curr != nullptr)
    {
        std::cout << curr->data << ' ';
        curr = curr->next;
    }
    std::cout << "]\n";
}

template<class T>
Iterator<T> SLList<T>::begin() { return Iterator<T>(head); }

template<class T>
Iterator<T> SLList<T>::end() { return Iterator<T>(); }