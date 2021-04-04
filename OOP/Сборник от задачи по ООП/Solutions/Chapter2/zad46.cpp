#include <iostream.h>

class Q
{
public:
    void f();
    void g();
    int x;
};

void Q::f()
{ 
    cout << "f()\n" << "x= " << x << endl;
}

void Q::g()
{ 
    --x;
    cout << "g()\n" << "x= " << x << endl;
}

int main()
{ 
    Q obj;
    // ���������� �� �������� px ��� ������
    // ���������� x �� ����� Q
    int Q::*px = & Q::x;
    // ��������� ��� x ���� ��������� px
    obj.*px = 25;
    cout << obj.*px << endl;
    // ���������� �� �������� ptr ��� ����-��������� f
    void (Q::*ptr)() = &Q::f;
    // ��������� ��� f ���� ��������� ��� ���
    (obj.*ptr)();
    // ��������� �� ptr � ����-��������� g
    ptr = &Q::g;
    // ��������� ��� g ���� ��������� ptr
    (obj.*ptr)();
    return 0;
}
