#include <iostream>
#include <list>
#include "DLList.h"

void test()
{
    DLList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.print();
    
    Iterator<int> it;
    std::cout << "-----------------------------------\n";
    for (it = list.begin(); it != list.end(); it++)
        std::cout << *it << std::endl;

    //std::cout << *it << std::endl;

    std::cout << "-----------------------------------\n";
    for (it = list.end(); it != list.begin(); it--)
        std::cout << *it << std::endl;

    //std::cout << *it << std::endl;

    std::list<int> l;
    for (size_t i = 0; i < 10; i++)
        l.push_back(i);
    
    std::cout << "-----------------------------------\n";
    for(std::list<int>::iterator iter = l.begin(); iter != l.end(); iter++)
        std::cout << *iter << std::endl;
}

void run()
{
    DLList<int> list;
    std::cout << std::boolalpha << list.empty() << std::endl;

    for (int i = 10; i < 21; i++)
        list.push_back(i);
    
    list.print();

    for(int i = 9; i >= 0; i--)
        list.push_front(i);

    list.print();

    std::cout << std::boolalpha << list.empty() << std::endl;
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;

    list.pop_front();
    list.pop_back();
    list.print();

    DLList<int> l2(list);
    l2.print();

    for (size_t i = 1; i <= 19; i++)
        list.pop_back();

    list.print();
    std::cout << std::boolalpha << list.empty() << std::endl;
}

int main()
{
    run();
    test();

    return 0;
}