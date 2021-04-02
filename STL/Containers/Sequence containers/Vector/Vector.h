#pragma once

template<class T>
class Iterator;

template<class T>
class Vector
{
private:
    friend Iterator<T>;
    T* data;
    size_t size, capacity;

private:
    void copy(const Vector&);
    void del();
    void init(const size_t, const T);

public:
//member functions
    Vector();
    Vector(const size_t);
    Vector(const size_t, const T);
    Vector(const Vector&);
    Vector(const Iterator<T>&, const Iterator<T>&);
    ~Vector();
    Vector& operator=(const Vector&);

//Iterators
    Iterator<T> begin();
    Iterator<T> end();
    // Iterator rbegin();
    // Iterator rend();
    // Iterator cbegin();
    // Iterator cend();
    // Iterator crbegin();
    // Iterator crend();

//capacity
    size_t sizeVec()const;
    size_t max_sizeVec()const;
    void resize(const size_t);
    void resize(const size_t, const T);
    size_t capacityVec()const;
    bool empty()const;
    void reserve();
    void shrink_to_fit();

//element access
    T& operator[](size_t);
    T& at(size_t);
    T& front();
    T& back();
    T* data2();

//modifiers
    void assign();
    void push_back(const T);
    void pop_back();
    void insert();
    void erase();
    void swap();
    void clear();
    void emplace();
    void emplace_back();

//allocator
    void get_allocator();

//non-member function overloads
    bool operator==(const Vector&)const;
    bool operator!=(const Vector&)const;
    bool operator>=(const Vector&)const;
    bool operator>(const Vector&)const;
    bool operator<=(const Vector&)const;
    bool operator<(const Vector&)const;

//printing funcs
    template<class E>
    friend std::ostream& operator<<(std::ostream&, const Vector<E>&);
    
    void print()const;
};

#include "Iterator.cpp"
#include "Vector.cpp"
