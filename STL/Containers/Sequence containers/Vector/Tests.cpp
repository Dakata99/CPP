#include "Tests.h"

void def_cons(void)
{
    Vector<int> vec;
    
    for (size_t i = 0; i < 5; i++) vec.push_back(i);
    
    vec.pop_back();
    std::cout << vec;
    std::cout << vec.get_size() << std::endl;
}

void param_cons(void)
{
    Vector<int> vec(5);
    std::cout << vec.get_size() << std::endl;
    
    Vector<int> vec(5, 99);
    std::cout << vec.get_size() << std::endl;
}

void copy_cons(void)
{
    Vector<int> vec(6, 77);
    Vector<int> vec2(vec);
    std::cout << vec2.get_size() << std::endl;
}

void range_cons(void) {}

void assignment(void)
{
    Vector<int> vec(3, 55);
    Vector<int> vec2 = vec;
    vec2.pop_back();
}

void index(void)
{
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(9);
    std::cout << vec[1] << std::endl << vec.at(3) << std::endl;
    std::cout << vec.front() << std::endl << vec.back() << std::endl;   
}

void iterators(void)
{
    Vector<int> vec;
    for (size_t i = 0; i < 10; i++) vec.push_back(i);
    
    for (Iterator<int> it = vec.begin(); it != vec.end(); it++) std::cout << *it << ' ';
    
    std::cout << std::endl;

    //Vector<int> vec2(vec.begin(), vec.end());
}

void run(void);
{
    def_cons();
    param_cons();
    param_cons2();
    copy_cons();
    range_cons();   //TODO
    assignment(); //???
    index();
    iterators();
}


