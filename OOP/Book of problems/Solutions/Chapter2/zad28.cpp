#include <iostream.h>
#include <math.h>

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

double Distance(const Point3& p)
{ 
    return sqrt((double)(p.getX() * p.getX() +
                p.getY() * p.getY() +
                p.getZ() * p.getZ()));
}

int main()
{ 
    // �������� �� ����� �� ����� �� 10 ���������
    Point3 ** array = new Point3*[10];
    if(!array)
    { 
        cout << "������ ��� �������� �� �����!\n";
        return 1;
    }

    int i;
    // ��������� �� ������ �� ���������
    for(i = 0; i < 10; i++)
    { 
        int x, y, z;
        cout << "*array[" << i << "](x, y, z)= ";
        cin >> x >> y >> z;
        array[i] = new Point3(x, y, z);
        if(!array[i])
        { 
            cout << "������ ��� �������� �� �����!\n";
            return 1;
        }
    }

    // �������� �� ����������� � �� ������������
    // ���������� �� �������, ������ �� �����������
    // �� ������ �� ������������� ������
    double min = Distance(*array[0]), 
           max = Distance(*array[0]);
    for(i = 1; i < 10; i++)
    { 
        double d = Distance(*array[i]);
        if(d < min) min = d;
        if(d > max) max = d;
    }

    // �������� � ��������� �� ������� �� ���-�����
    // ���������� �� ������������� ������
    cout << "����� �� ���-����� ���������� (" << min
        << ") �� ������������� ������\n";
    for(i = 0; i < 10; i++)
    { 
        if(fabs(Distance(*array[i]) - min) < 1E-14)
            cout << "Point(" << array[i]->getX() << ", "
                 << array[i]->getY() << ", "
                 << array[i]->getZ() << ")\n";
    }

    // �������� � ��������� �� ������� �� ���-������
    // ���������� �� ������������� ������
    cout << "����� �� ���-������ ���������� (" << max
        << ") �� ������������� ������\n";
    for(i = 0; i < 10; i++)
    { 
        if(fabs(Distance(*array[i]) - max) < 1E-14)
            cout << "Point(" << array[i]->getX() << ", "
                 << array[i]->getY() << ", "
                 << array[i]->getZ() << ")\n";
    }

    // ������������� �� ���������� � ����� �����
    for(i = 0; i < 10; i++)
        delete array[i];
    delete [] array;
    return 0;
}
