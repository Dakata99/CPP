#include <iostream.h>

class P
{
private:
    int a;
    double b;

public:
    P(int = 5, double = 2.5);
    ~P();
    void display() const;
};

P::P(int x, double y)
{
    a = x;
    b = y;
}

P::~P()
{
    cout << "~P()\n";
}

void P::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    P *p;
    // �������� �� ����� �� ����� �� 5 ������ �� ���� P
    p = new P[5];
    if(!p)
    {
        cout << "������ ��� �������� �� �����!\n";
        return 1;
    }
    int i;
    // ��������� �� ������, ������� ���������
    for(i = 0; i < 5; i++)
        p[i].display();
    // ������������� �� ���������� �� ������ �����
    delete [] p;
    return 0;
}
