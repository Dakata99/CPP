#include <iostream.h>
#include <math.h>

const int MAX = 20;

class Vector
{
private:
    double x;                       // �������
    double y;                       // ��������
    double mag;                     // ������
    double ang;                     // ���� (� �������)
    char regime;                    // �����:'r' - �����������,
                                    //       'p' - �������

public:
    // ������������
    Vector();
    Vector(double, double, char = 'r');
    // ������� �� ������
    double xval() const             // ������ ���������
    {
        return x;
    }
    double yval() const             // ������ ����������
    {
        return y;
    }
    double rval() const             // ������ �������
    {
        return mag;
    }
    double aval() const             // ������ �����
    {
        return ang;
    }

    // ������� �� �������
    // �� �������� ������ � ����, ������ ���������
    void set_x(double r, double a)
    { 
        x = r * cos(a);
    }

    // ������� �� ��������
    // �� �������� ������ � ����, ������ ����������
    void set_y(double r, double a)
    { 
        y = r * sin(a);
    }

    // ������� �� ������
    // �� �������� ������� � ��������, ������ �������
    void set_mag(double x, double y)
    { 
        mag = sqrt(x*x + y*y);
    }

    // ������� �� ����
    // �� �������� ������� � ��������, ������ �����
    void set_ang(double x, double y)
    {
        ang = atan2(y, x);
    }

    // �������, ��������� ������� �����
    void polar_regime()
    {
        regime = 'p';
    }

    // �������, ��������� ����� �� ����������� ����������
    void rect_regime()
    { 
        regime = 'r';
    }

    // ������� �� ����� � ����������
    void set(double, double, char = 'r');
    
    // ���������� ����-������� �� ��������
    // � ��������� �� ��� �������
    Vector operator+(const Vector &) const;
    Vector operator-(const Vector &) const;
    
    // ���������� ����-������� �� ���������
    // �� ������ � ������ �����
    Vector operator*(double) const;
    
    // ���������� ��������� �������� ��
    // ��������� �� ������ ����� � ������
    friend Vector operator*(double, const Vector &);
    
    // ��������� �� ������
    void print() const;
};

// ����������� �� ������������
// ������ 0-� ������ � ����� �� ����������� ����������
Vector::Vector()
{ 
    x = y = mag = ang = 0.0;
    regime = 'r';
}

// ����������� � ��� ����������
// ���������� ������ � ����������� ����������
// ��� �������, ������� ���� ���������� m � �r�;
// ���������� ������ � ������� ����������,
// ��� �������, ������� ���� ���������� m � �p�
// � 0-� ������, ��� m �� � ���� �r�, ���� �p�.
Vector::Vector(double a, double b, char m)
{ 
    set(a, b, m);
}

// ������� �� ����� � ����������
// ������ ������ � ����������� ����������,
// ��� �������, ������ ���� ���������� m � �r�;
// ������ ������ � ������� ����������,
// ��� �������, ������ ���� ���������� m � �p�
// � 0-� ������, ��� m �� � ���� �r�, ���� �p�
void Vector::set(double a, double b, char m)
{ 
    regime = m;
    if(m == 'r')
    {
        x = a;
        y = b;
        set_mag(x, y);
        set_ang(x, y);
    }
    else if(m == 'p')
    { 
        mag = a;
        ang = b;
        set_x(a, b);
        set_y(a, b);
    }
    else
    { 
        cout << " ���������� �����.\n";
        x = y = 0.0;
        regime = 'r';
    }
}

// �������� �� ��� �������
Vector Vector::operator+(const Vector & b) const
{ 
    Vector r(x + b.x, y + b.y);
    if(regime == 'p') r.polar_regime();
    return r;
}

// ��������� �� ��� �������
Vector Vector::operator-(const Vector & b) const
{
    Vector r(x - b.x, y - b.y);
    if(regime == 'p') r.polar_regime();
    return r;
}

// ��������� �� ������ � ������ �����
Vector Vector::operator*(double n) const
{
    Vector r(n * x, n * y);
    if(regime == 'p') r.polar_regime();
    return r;
}

// �������-������� �� ��������� �� ������ ����� � ������
Vector operator*(double n, const Vector & a)
{
    return a * n;
}

// ��������� �� ������������� ���������� ��
// ������,��� ������� � �r�, ��� �� ���������
// �� ����������, ��� ������� � �p�.
void Vector::print() const
{
    if(regime == 'r')
    {
        cout << "(x, y) = (" << x << ", " << y << ")\n";
    }
    else //if(regime == 'p')
    {
        cout << "(m, a) = (" << mag << ", " << ang << ")\n";
    }
}

int main()
{
    Vector v[MAX];            // ������ �� �������
    int n;                    // ������� �� ��������
    do
    {
        cout << "n �� 1 �� " << MAX  << ": ";
        cin >> n;
    } while(n < 1 || n > MAX);

    // ��������� �� ������������� ����������
    // �� ��������� �� ��������
    int i;
    for(i = 0; i < n; i++)
    {
        double x, y;
        cout << "�������� ������������� ���������� �� "
             << i << " ���� ������: ";
        cin >> x >> y;
        v[i].set(x, y);
    }

    // ��������� �� �������� �� �������
    for(i = 0; i < n; i++)
        v[i].print();

    // �������� �� ������ �� ��������� �� ��������
    Vector S = v[0];
    for(i = 1; i < n; i++)
        S = S + v[i];

    // ��������� �� ������ �� ��������� �� ��������
    cout << "������ �� ��������� �� �������� �: ";
    S.print();

    // �������� �� ��������� �� ��������� �� ��������
    Vector R = v[0];
    for(i = 1; i < n; i++)
        R = R - v[i];

    // ��������� �� ��������� �� ��������� �� ��������
    cout << "��������� �� ��������� �� �������� �: ";
    R.print();

    // ��������� �� �������� �����,
    // � ����� �� �� �������� �������� S
    double t; cout << "t= "; cin >> t;

    // ��������� �� ������ �� ��������� � t � ���������
    cout << "�������������� �� ������ �� ��������� "
            "�� �������� � t �: ";
    (S*t).print();

    // ��������� �� t ��� ������ �� ��������� � ���������
    cout << "�������������� �� t ��� ������ �� "
            "��������� �� �������� �: ";
    (t*S).print();

    // ��������� �� ��������� ���������� ��
    // ��������� �� ��������
    cout << "��������� �� �������� � ������� ����������: \n";
    for(i = 0; i < n; i++)
    {
        v[i]. polar_regime();
        v[i].print();
    }
    return 0;
}
