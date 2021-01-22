#include <iostream>
#include "SLList.h"
#include "Iterator.h"

void run()
{
    SLList<int> list;
    std::cout << std::boolalpha << list.empty() << std::endl;

    for (size_t i = 0; i < 10; i++) list.push_front(i);

    list.print();
    list.reverse();
    list.print();
    std::cout << list.front() << std::endl;
    std::cout << std::boolalpha << list.empty() << std::endl;

    list.pop_front();
    list.pop_front();
    list.pop_front();

    list.print();

    for (Iterator<int> it = list.begin(); it != list.end(); it++)
        std::cout << *it << std::endl;

    SLList<int> l2(list);
    l2.print();

    list.print();
    for (size_t i = 0; i < 7; i++)
        list.pop_front();

    list.print();
    std::cout << std::boolalpha << list.empty() << std::endl;
}

int main()
{
    run();

    return 0;
}