#include <iostream>
#include "Vector.h"
#include <vector>
#include <cmath>

void defCons()
{
    Vector<int> vec;
    for (size_t i = 0; i < 5; i++)
        vec.push_back(i);
    
    vec.print();
    vec.pop_back();
    std::cout << vec;
    std::cout << vec.sizeVec() << std::endl;
}

void paramCons()
{
    Vector<int> vec(5);
    vec.print();
    std::cout << vec.sizeVec() << std::endl;
}

void paramCons2()
{
    Vector<int> vec(5, 99);
    vec.print();
    std::cout << vec.sizeVec() << std::endl;
}

void copyCons()
{
    Vector<int> vec(6, 77);
    Vector<int> vec2(vec);
    vec2.print();
    std::cout << vec2.sizeVec() << std::endl;
}

void rangeCons()
{

}

void assignment()
{
    Vector<int> vec(3, 55);
    Vector<int> vec2 = vec;
    vec2.print();
    vec2.pop_back();
    vec2.print();
    vec.print();
}

void index()
{
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(9);
    std::cout << vec[1] << std::endl << vec.at(4) << std::endl;
    std::cout << vec.front() << std::endl << vec.back() << std::endl;   
}

void iterators()
{
    Vector<int> vec;
    for (size_t i = 0; i < 10; i++)
        vec.push_back(i);
    
    for (Iterator<int> it = vec.begin();it != vec.end();it++)
    {
        std::cout << *it << std::endl;
    }

    Vector<int> vec2(vec.begin(), vec.end());
    vec2.print();    
}

void run()
{
    //defCons();
    //paramCons();
    //paramCons2();
    //copyCons();
    //rangeCons();   //TODO
    //assignment(); //???
    //index();
    iterators();
}

int main()
{
    run();
//     Vector(const Iterator, const Iterator);

//     Iterator begin();
//     Iterator end();
//     Iterator rbegin();
//     Iterator rend();
//     Iterator cbegin();
//     Iterator cend();
//     Iterator crbegin();
//     Iterator crend();

//     void resize(const size_t);
//     void resize(const size_t, const T);
//     void reserve();
//     void shrink_to_fit();

// //modifiers
//     void assign();
//     void insert();
//     void erase();
//     void swap();
//     void clear();
//     void emplace();
//     void emplace_back();

//     void get_allocator();

//     bool operator>=(const Vector&)const;
//     bool operator>(const Vector&)const;
//     bool operator<=(const Vector&)const;
//     bool operator<(const Vector&)const;

    return 0;
}