#include "Vector.h"
#include <cmath>
#include <assert.h>

//private funcs
template<class T>
void Vector<T>::copy(const Vector<T>& other)
{
    size = other.size;
    capacity = other.capacity;
    data = new T[size];
    for (size_t i = 0; i < size; i++)
        data[i] = other.data[i];
}

template<class T>
void Vector<T>::del()
{
    delete[]data;
}

template<class T>
void Vector<T>::init(const size_t num, const T val)
{
    size = capacity = num;
    data = new T[size];
    for (size_t i = 0; i < size; i++)
        data[i] = val;
}

//public funcs
template<class T>
Vector<T>::Vector():data(nullptr), size(0), capacity(0){}

template<class T>
Vector<T>::Vector(const size_t size)
{
    init(size, T());
}

template<class T>
Vector<T>::Vector(const size_t size, const T val)
{
    init(size, val);
}

template<class T>
Vector<T>::Vector(const Vector<T>& other)
{
    copy(other);
}

template<class T>
Vector<T>::Vector(const Iterator<T>& begin, const Iterator<T>& end)
{
    
}

template<class T>
Vector<T>::~Vector()
{
    del();
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }
    return *this;
}

//Iterators
template<class T>
Iterator<T> Vector<T>::begin()
{
    return Iterator<T>(this->data);
}
template<class T>
Iterator<T> Vector<T>::end()
{
    return Iterator<T>(this->data + size);
}
// template<class T>
// Iterator<T>::Iterator rbegin()
// {
    
// }
// template<class T>
// Iterator<T>::Iterator rend()
// {
    
// }
// template<class T>
// Iterator<T>::Iterator cbegin()
// {
    
// }
// template<class T>
// Iterator<T>::Iterator cend()
// {
    
// }
// template<class T>
// Iterator<T>::Iterator crbegin()
// {
    
// }
// template<class T>
// Iterator<T>::Iterator crend()
// {
    
// }

//capacity
template<class T>
size_t Vector<T>::sizeVec()const
{
    return size;
}

template<class T>
size_t Vector<T>::max_sizeVec()const
{
    return pow(2, 64) / sizeof(T) - 1;
}

template<class T>
void Vector<T>::resize(const size_t num)
{
    const T* temp = new T[num];
    for (size_t i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }
    delete[]data;
    size = num;
    data = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = temp[i];
    }
    delete[]temp;
}

template<class T>
void Vector<T>::resize(const size_t num, const T val)
{
    const T* temp = new T[num];
    for (size_t i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }
    delete[]data;
    size = num;
    data = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = temp[i];
    }
    delete[]temp;
}

template<class T>
size_t Vector<T>::capacityVec()const
{
    return capacity;
}

template<class T>
bool Vector<T>::empty()const
{
    return size == 0;
}

template<class T>
void Vector<T>::reserve()
{

}

template<class T>
void Vector<T>::shrink_to_fit()
{

}

//element access
template<class T>
T& Vector<T>::operator[](size_t index)
{
    assert(index >= 1 && index <= size);
    return data[index - 1];
}

template<class T>
T& Vector<T>::at(size_t index)
{
    assert(index >= 1 && index <= size);
    return data[index - 1];
}

template<class T>
T& Vector<T>::front()
{
    assert(data != nullptr);
    return data[0];
}

template<class T>
T& Vector<T>::back()
{
    assert(data != nullptr);
    return data[size - 1];
}

template<class T>
T* Vector<T>::data2()
{
    return data;
}

//modifiers
template<class T>
void Vector<T>::assign()
{

}

template<class T>
void Vector<T>::push_back(const T element)
{
    if (data == nullptr)
    {
        capacity = 1;
        data = new T[capacity];
    }
    else if (size >= capacity)
    {
        capacity++;
        T* temp = new T[size];
        for (size_t i = 0; i < size; i++)
            temp[i] = data[i];

        delete[]data;
        data = new T[capacity];
        for (size_t i = 0; i < size; i++)
            data[i] = temp[i];
        
        delete[]temp;
    }
    data[size++] = element;    
}

template<class T>
void Vector<T>::pop_back()
{
    if (size == 0)
    {
        return;
    }
    T* temp = new T[size - 1];
    for (size_t i = 0; i < size - 1; i++)
        temp[i] = data[i];

    delete[]data;
    size--;
    data = new T[size];
    for (size_t i = 0; i < size; i++)
        data[i] = temp[i];
    
    delete[]temp;
}

template<class T>
void Vector<T>::insert()
{

}

template<class T>
void Vector<T>::erase()
{

}

template<class T>
void Vector<T>::swap()
{

}

template<class T>
void Vector<T>::clear()
{

}

template<class T>
void Vector<T>::emplace()
{

}

template<class T>
void Vector<T>::emplace_back()
{

}

//allocator
template<class T>
void Vector<T>::get_allocator()
{

}

//non-member function overloads
template<class T>
bool Vector<T>::operator==(const Vector<T>& other)const
{
    assert(size == other.size());
    for (size_t i = 0; i < size; i++)
        if (data[i] != other.data[i])
            return false;
        
    return true;
}

template<class T>
bool Vector<T>::operator!=(const Vector<T>& other)const
{
    return !(*this == other);
}

template<class T>
bool Vector<T>::operator>=(const Vector<T>& other)const
{
    return false;
}

template<class T>
bool Vector<T>::operator>(const Vector<T>& other)const
{
    return false;
}

template<class T>
bool Vector<T>::operator<=(const Vector<T>& other)const
{
    return false;
}

template<class T>
bool Vector<T>::operator<(const Vector<T>& other)const
{
    return false;
}

//printing funcs
template<class T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector)
{
    std::cout << "( ";
    for (size_t i = 0; i < vector.size; i++)
        os << vector.data[i] << " ";
    std::cout << ")\n";

    return os;
}

template<class T>
void Vector<T>::print()const
{
    std::cout << "( ";
    for (size_t i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << ")\n";
}
