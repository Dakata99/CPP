#include <iostream>
#include "Stack.h"

void run()
{
    Stack<int> st;
    st.print();
    st.push(1);
    std::cout << std::boolalpha << st.empty() << std::endl;
    st.print();

    for(size_t i = 11; i <= 20; i++)
        st.push(i);

    st.print();
}

int main()
{
    run();

    return 0;
}