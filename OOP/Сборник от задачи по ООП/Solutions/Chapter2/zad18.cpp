#include <iostream.h>

class H
{
private:
    int a, b;

public:
    // ����������� � ������������ �� ���������
    H(int = 1, int = 1);
    // ����������� �� �����������
    H(H const &);
    // ����-������� �� ��������� �� ����-������� �� �����
    void display() const;
};

H::H(int x, int y)
{
    a = x;
    b = y;
}

H::H(H const &r)
{
    a = r.a;
    b = r.b;
}

void H::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    // ��������� ��  �������� e1, e2 � e3 ����
    // ������������ � ������������ �� ���������
    H e1, e2(6), e3(3, 8);

    // ��������� �� ��������
    e1.display();
    e2.display();
    e3.display();

    // ��������� �� ����� e4 ���� ������������ �� �����������
    H e4 = e3;

    // ��������� �� ������ e4
    e4.display();
    return 0;
}
