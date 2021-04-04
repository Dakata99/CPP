#include <iostream.h>

class SquarePyramid;               // ������������� ����������

// ��������� �� ����� Cylinder
class Cylinder
{
private:
    double radius;                 // ������ �� ��������
    double height;                 // ��������

public:
    Cylinder(double, double);      // �����������
    double getRadius() const;      // ������ �� �������
    double getHeight() const;      // ������ �� ����������
    // ���������� �� ������������ �������
    friend bool IsHigher(const Cylinder&, const SquarePyramid &);
};

Cylinder::Cylinder(double r, double h)
{
    radius = r;
    height = h;
}

double Cylinder::getRadius() const
{
    return radius;
}

double Cylinder::getHeight() const
{
    return height;
}

// ��������� �� ����� SquarePyramid
class SquarePyramid
{
private:
    double side;                     // ������
    double height;                   // ��������

public:
    SquarePyramid (double, double);  // �����������
    double getSide() const;          // ������ �� ��������
    double getHeight() const;        // ������ �� ����������
    // ���������� �� ������������ �������
    friend bool IsHigher(const Cylinder&, const SquarePyramid &);
};

SquarePyramid::SquarePyramid(double s, double h)
{
    side = s;
    height = h;
}

double SquarePyramid::getSide() const
{
    return side;
}

double SquarePyramid::getHeight() const
{
    return height;
}

// ��������� �� ������������ �� ����� ����� �������
bool IsHigher(const Cylinder& c, const SquarePyramid & s)
{
    return c.height > s.height;
}

int main()
{
    // ���������� �� ��������
    Cylinder c(12.5, 8.0);
    // ���������� �� ��������� ��������
    SquarePyramid s(5.2, 10.5);
    if(IsHigher(c, s))
        cout << "���������� � ��-����� �� ����������.\n";
    else 
        cout << "���������� �� � ��-����� �� ����������.\n";
    return 0;
}
