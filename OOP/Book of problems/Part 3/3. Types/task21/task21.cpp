#include <iostream>

class base
{
protected:
    int a;
public:
    base(int x = 2)
    {
        a = x;
    }
    int get()const
    {
        return a;
    }
};

class der:public base
{
private:
    int b;
public:
    der(int y = 8)
    {
        b = y;
    }
    int get()const
    {
        return b;
    }
};

int main()
{
    base *ptr;
    der d;
    ptr = &d;
    std::cout << ptr->get() << std::endl;

    return 0;
}