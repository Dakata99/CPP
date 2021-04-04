#include <iostream.h>

class N
{
private:
    int a;
    double b;

public:
    // �����������
    N(int = 5, double = 2.5);
    // ����������
    ~N();
    // ����-������� �� ��������� �� �����
    void display() const;
};

N::N(int x, double y)
{
    a = x;
    b = y;
}

N::~N()
{
    cout << "~N()\n";
}

void N::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    N *p = NULL;
    p = new N(8);               // �������� �� ����� �� �����

    if(!p)                      // �������� ���� ����� � ��������
    {
        cout << "������ ��� �������� �� �����!\n";
        return 1;
    }
    p -> display();             // ��������� �� ������, ����� �� ��������� p
    delete p;                   // ������������� �� �������
    p = new N(1, 3.5);          // �������� �� ����� �� ��� �����
    if(!p)                      // �������� ���� ����� � ��������
    {
        cout << "������ ��� �������� �� �����!\n";
        return 1;
    }
    p -> display();              // ��������� �� ������, ����� �� ��������� p
    delete p;                    // ������������� �� �������
    return 0;
}
