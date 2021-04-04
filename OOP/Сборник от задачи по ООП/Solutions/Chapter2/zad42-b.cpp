#include <iostream.h>

class Point3
{ 

public:
    // ����������� � ������������ �� ���������
    Point3(int = 0, int = 0, int = 0);
    // ����������� �� �����������
    Point3(const Point3 &);
    // ����-������� �� ������ �� ������������ �� �����
    int getX() const;
    int getY() const;
    int getZ() const;
    // �������� �� ������������ �� �����
    void setX(int);
    void setY(int);
    void setZ(int);

    friend Point3& operator++(Point3&);
    friend Point3 operator++(Point3&, int);
    friend Point3& operator--(Point3&);
    friend Point3 operator--(Point3&, int);

private:
    int x;                // �������
    int y;                // ��������
    int z;                // ��������
};

Point3::Point3(int _x, int _y, int _z) 
{
    x = _x;
    y = _y;
    z = _z;
}

Point3::Point3(const Point3& p)
{
    x = p.x;
    y = p.y;
    z = p.z;
}

int Point3::getX() const
{
    return x;
}

int Point3::getY() const 
{
    return y;
}

int Point3::getZ() const
{
    return z;
}

void Point3::setX(int _x)
{
    x = _x;
}

void Point3::setY(int _y)
{
    y = _y;
}

void Point3::setZ(int _z)
{
    z = _z;
}

// ������������� �� ��������� �������� ++
Point3& operator++(Point3& p)
{ 
    ++p.x;
    ++p.y;
    ++p.z;
    return p;
}

// ������������� �� ���������� �������� ++
Point3 operator++(Point3& p, int notused)
{ 
    Point3 temp(p);
    p.x++;
    p.y++;
    p.z++;
    return temp;
}

// ������������� �� ��������� �������� --
Point3& operator--(Point3& p)
{ 
    --p.x;
    --p.y;
    --p.z;
    return p;
}

// ������������� �� ���������� �������� --
Point3 operator--(Point3& p, int notused)
{ 
    Point3 temp(p);
    p.x--;
    p.y--;
    p.z--;
    return temp;
}

int main()
{
    Point3 p(1, 2, 3);
    ++p;
    cout << '(' << p.getX() << ", " 
         << p.getY() << ", " << p.getZ() 
         << ")" << endl;

    Point3 q = p--;
    cout << '(' << p.getX() << ", " 
         << p.getY() << ", " << p.getZ() 
         << ")" << endl;
    cout << '(' << q.getX() << ", " 
         << q.getY() << ", " << q.getZ() 
         << ")" << endl;
    return 0;
}
