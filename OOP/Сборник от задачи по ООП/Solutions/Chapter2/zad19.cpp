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

int main()
{ 
    // ��������� �� ������� P � P1 ����
    // ������������ � ������������ �� ���������
    Point3 P, P1(1, 1, 1);
    // ��������� �� ������� P � P1
    cout << "P = (" << P.getX() << "," << P.getY()
         << "," << P.getZ() << ")" << endl;
    cout << "P1 = (" << P1.getX() << "," << P1.getY()
         << "," << P1.getZ() << ")" << endl;

    // ��������� �� ������� P2 ����
    // ������������ �� �����������
    Point3 P2 = P1;
    // ��������� �� ������� P2
    cout << "P2 = (" << P2.getX() << "," << P2.getY() << ","
         << P2.getZ() << ")" << endl;

    // ������� �� ������������ �� ������� P2
    P2.setX(5); P2.setY(10); P2.setZ(15);
    // ��������� �� ������� P2
    cout << "P2 = (" << P2.getX() << "," << P2.getY() << ","
         << P2.getZ() << ")" << endl;
    return 0;
}
