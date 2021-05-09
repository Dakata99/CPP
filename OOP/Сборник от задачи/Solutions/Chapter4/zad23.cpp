#include <iostream.h>

class Points
{
public:
    virtual void Print() const = 0;
};

// ���������� �� ����, �������� �� ����� �� ���� �����
class Point1 : public Points
{
public:
    Point1(int a = 0)
    {
        x = a;
    }

    void Print() const
    {
        cout << x << endl;
    }

private:
    int x;
};

// ���������� �� ����, �������� �� ����� ��
// ����� �� ��������� � ���� ����������
class Point2 : public Points
{
public:
    Point2(int a = 0, int o = 0)
    {
        x = a;
        y = o;
    }

    void Print() const
    {
        cout << "(" << x << ", " << y << ")\n";
    }

private:
    int x, y;
};

// ���������� �� ����, �������� �� ����� ��
// ����� �� �������������� � ���� ����������
class Point3 : public Points
{
public:
    Point3(int a, int o, int b)
    {
        x = a;
        y = o;
        z = b;
    }

    void Print() const
    {
        cout << "(" << x << ", " << y 
            << ", " << z << ")\n";
    }

private:
    int x, y, z;
};

int main()
{
    // ���������� �� ����������� ��������� ����� � 6 ��������
    Points* a[6];
    // ���������� �� ������, ����������� ���� �����
    Point1 p1(1), p2(2);
    // ���������� �� ������, ����������� ����� �� ���������
    Point2 p3(3,4), p4(5, 6);
    // ���������� �� ������, ����������� ����� �� ��������������
    Point3 p5(7, 8, 9), p6(10, 11, 12);
    // ��������� �� ����������� ��������� ����� �� ����
    // ����� � ����� �� ��������� � ��������������
    a[0] = &p1; a[1] = &p3; a[2] = &p5;
    a[3] = &p6; a[4] = &p4; a[5] = &p2;
    Points *ptr;
    // ��������� �� ����������� ������
    for(int i = 0; i < 6; i++)
    {
        ptr = a[i];
        ptr->Print();
    }
    return 0; 
}
