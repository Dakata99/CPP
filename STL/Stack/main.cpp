#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int> s;
    for (size_t i = 0; i < 10; i++)
    {
        s.push(i);
    }
    for (size_t i = 0; i < 7; i++)
    {
        s.pop();
    }
    
    std::cout << s.top() << std::endl;

    return 0;
}