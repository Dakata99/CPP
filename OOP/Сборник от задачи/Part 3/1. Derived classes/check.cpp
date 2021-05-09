#include <iostream>

class Check
{
private:
    int a;
protected:
    int b, c;
    void set_a(int x)
    {
        a = x;
    }
public:
    void set_b(int x)
    {
        b = x;
    }
    void set_c(int x)
    {
        c = x;
    }
};

//class Quiz:private Check{}; //a, b, c, set_a - will be private; set_b, set_c will be public

//class Quiz:protected Check{}; //a, b, c, set_a - will be private; set_b, set_c will be public 

class Quiz:public Check{}; //a is private, b, c, set_a will be protected, set_b, set_c - public

//class Quiz:Check{};

void func()
{
    Quiz q;
    q.set_b(2);
}

int main()
{
    func();

    return 0;
}