#include "Stack.h"

template<class T>
void Stack<T>::copy(const Stack<T>& other)
{
    topIndex = other.topIndex;
    size = other.size;
    for(size_t i = 0; i < topIndex; i++)
        data[i] = other.data[i];
}

template<class T>
void Stack<T>::clear()
{
    delete[]data;
}

template<class T>
void Stack<T>::resize(const size_t newSize)
{
    T* temp = new T[topIndex];
    for (size_t i = 0; i < topIndex; i++)
        temp[i] = data[i];

    size = newSize;
    delete[]data;
    data = new T[size];
    for(size_t i = 0; i < topIndex; i++)
        data[i] = temp[i];

    delete[]temp;
}

template<class T>
Stack<T>::Stack():data(nullptr), topIndex(0), size(0){}

template<class T>
Stack<T>::Stack(const Stack<T>& other)
{
    copy(other);
}

template<class T>
Stack<T>::~Stack()
{
    clear();
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

template<class T>
void Stack<T>::push(const T& element)
{
    if(data == nullptr)
    {
        size = 1;
        data = new T[size];
        data[topIndex++] = element;
    }
    else if(topIndex >= size)
    {
        resize(size + 1);
    }
    else
    {
        data[topIndex++] = element;
    }
}

template<class T>
void Stack<T>::pop()
{
    if(data != nullptr)
        resize(size - 1);
    if(size == 0)
        data = nullptr;    
}

template<class T>
bool Stack<T>::empty()const
{
    return data == nullptr;
}

template<class T>
const T& Stack<T>::top()const
{
    return data[topIndex];
}

template<class T>
void Stack<T>::print()const
{
    std::cout << "[ ";
    for (size_t i = 0; i < topIndex; i++)
        std::cout << data[i] << " ";
    std::cout << "]\n";
}