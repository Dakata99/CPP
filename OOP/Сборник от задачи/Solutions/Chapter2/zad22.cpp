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

////�)
void Input(int n, Point3 a[])
{
    for(int i = 0; i < n; i++)
    {
        int p;
        cout << "x= "; cin >> p;
        a[i].setX(p);
        cout << "y= "; cin >> p;
        a[i].setY(p);
        cout << "z= "; cin >> p;
        a[i].setZ(p);
    }
}

////�)
void Symmetry(int n, Point3 a[])
{
    for(int i = 0; i < n; i++)
    {
        a[i].setX(-a[i].getX());
        a[i].setY(-a[i].getY());
        a[i].setZ(-a[i].getZ());
    }
}

////�)
void Output(int n, Point3 a[])
{
    for(int i = 0; i < n; i++)
    {
        cout << "Point3("
             << a[i].getX() << ", "
             << a[i].getY() << ", "
             << a[i].getZ() << ")\n";
    }
}

int main()
{
    const int n = 5;
    Point3 arr[n];
    Input(n, arr);
    Symmetry(n, arr);
    Output(n, arr);
    return 0;
}
