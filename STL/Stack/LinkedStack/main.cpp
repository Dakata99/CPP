#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int> s;
    for (size_t i = 0; i < 10; i++)
        s.push(i);
        
    s.print();
    for (size_t i = 0; i < 11; i++)
        s.pop();
    
    std::cout << s.top() << std::endl;
    s.print();
    return 0;
}