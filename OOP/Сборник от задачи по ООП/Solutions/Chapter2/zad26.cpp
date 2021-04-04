#include <iostream.h>

class L
{
private:
    int a;
    double b;

public:
    L(int = 5, double = 2.5);
    void display() const;
};

L::L(int x, double y)
{
    a = x;
    b = y;
}

void L::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    L *p;
    p = new L(8);            // �������� �� ����� �� ������
    if(!p)                   // �������� ���� � �������� �����
    {
        cout << "������ ��� �������� �� �����!\n";
        return 1;
    }
    p -> display();          // ��������� �� ������, ����� �� p
    delete p;                // ������������� �� �������
    p = new L(1, 3.5);       // �������� �� ����� �� ��� �����
    if(!p)                   // �������� ���� � �������� �����
    {
        cout << "������ ��� �������� �� �����!\n";
        return 1;
    }
    p -> display();          // ��������� �� ������, ����� �� p
    delete p;                // ������������� �� �������
    return 0;
}
