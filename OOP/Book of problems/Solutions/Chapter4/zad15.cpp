#include <iostream.h>

class Base
{
public:
    int x;

    Base(int a)
    {
        x = a;
    }

    virtual void f() const
    {
        cout << "Base::f()\n"
             << "Base::x " << x << endl;
    }
};

class Der1 : public Base
{
public:
    Der1(int a) : Base(a)
    {}

    void f() const
    {
        cout << "Der1::f() " << x*x+x+1 << endl;
    }
};

class Der2 : public Base
{
public:
    Der2(int a) : Base(a)
    {}

    void f() const
    {
        cout << "Der2::f() " << 2*x+1 << endl;
    }
};

int main()
{
    Base b(1); Der1 d1(5); Der2 d2(10);
    Base &ps = b; ps.f();
    Base &ps1 = d1; ps1.f();
    Base &ps2 = d2; ps2.f();
    return 0;
}
