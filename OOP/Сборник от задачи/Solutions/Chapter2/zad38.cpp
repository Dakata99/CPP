#include <iostream.h>
#include <math.h>

// ������ ���-����� ��� ������� �� x � y
int gcd(int x, int y)
{ 
    if(y == 0) return x;
    return gcd(y, x % y);
}

class Rat
{ 
public:
    // ������������
    Rat(int = 0, int = 1);
    Rat(const Rat&);
    // ������� �� ��������� �� ���������� �����
    void print() const;
    // ���������� ������� �� �������������
    // �� ���������� � ������ �����
    operator double() const;
    // ����������-������� �� ����������-������� ����������
    // �� ��� ���������� �����
    Rat operator+(const Rat&) const;
    Rat operator-(const Rat&) const;
    Rat operator*(const Rat&) const;
    Rat operator/(const Rat&) const;
    // ����������-������� �� ����������-������� ����������
    // �� ���������� � ���� �����
    Rat operator+(int) const;
    Rat operator-(int) const;
    Rat operator*(int) const;
    Rat operator/(int) const;
    // ���������� �������, ����������� ����������-�������
    // ���������� �� ���� ����� � ���������� �����
    friend Rat operator+(int, const Rat&);
    friend Rat operator-(int, const Rat&);
    friend Rat operator*(int, const Rat&);
    friend Rat operator/(int, const Rat&);
    // ������� �� ������ �� ������������
    int numer() const;
    int denom() const;
    // ��������
    void setNum(int);
    void setDen(int);

private:
    int num;                         // ��������
    int den;                           // ����������
};

Rat::Rat(int n, int d)
{ 
    if(d == 0)
    { 
        cout << "���������� ����������: 0!"
             << "������ �� � 1.\n";
        num = n;
        den = 1;
    }
    else
    { 
        if(n == 0)
        { 
            num = 0;
            den = 1;
        }
        else
        { 
            int g = gcd(abs(n), abs(d));
            if(n > 0 && d > 0 || n < 0 && d < 0)
            { 
                num = abs(n)/g;
                den = abs(d)/g;
            }
            else
            { 
                num = -abs(n)/g;
                den =  abs(d)/g;
            }
        }
    }
}

int Rat::numer() const
{ 
    return num;
}

int Rat::denom() const
{
    return den;
}
void Rat::setNum(int n)
{ 
    num = n;
}

void Rat::setDen(int d)
{ 
    if(d != 0)
    {
        den = d;
    }
    else
    { 
        cout << "���������� ����������: 0!"
             << "������ �� � 1." << endl;
        den = 1;
    }
}

void Rat::print() const
{ 
    cout << num << "/" << den;
}

////�)
// �������� �� ������������� �� ���������� � ������ �����
Rat::operator double() const
{ 
    return (double)num/den;
}

////�)
// �������� �� ���������� �����
Rat Rat::operator+(const Rat& r) const
{ 
    return Rat(num*r.den + den*r.num, den*r.den);
}

// ��������� �� ���������� �����
Rat Rat::operator-(const Rat& r) const
{ 
    return Rat(num*r.den - den*r.num, den*r.den);
}

// ��������� �� ���������� �����
Rat Rat::operator*(const Rat& r) const
{ 
    return Rat(num*r.num, den*r.den);
}

// ������� �� ���������� �����
Rat Rat::operator/(const Rat& r) const
{ 
    return Rat(num*r.den, den*r.num);
}

////�)
// �������� �� ���������� � ���� �����
Rat Rat::operator+(int x) const
{ 
    return Rat(num + den*x, den);
}

// ��������� �� ���� ����� �� ���������� �����
Rat Rat::operator-(int x) const
{
    return Rat(num - den*x, den);
}
// ��������� �� ���������� � ���� �����
Rat Rat::operator*(int x) const
{ 
    return Rat(num*x, den);
}

// ������� �� ���������� �� ���� �����
Rat Rat::operator/(int x) const
{ 
    return Rat(num, den*x);
}

// �������� �� ���� � ���������� �����
Rat operator+(int x, const Rat& r)
{ 
    return Rat(x*r.den + r.num, r.den);
}

// ��������� �� ���������� �� ���� �����
Rat operator-(int x, const Rat& r)
{ 
    return Rat(x*r.den - r.num, r.den);
}

// ��������� �� ���� � ���������� �����
Rat operator*(int x, const Rat& r)
{ 
    return Rat(x*r.num, r.den);
}

// ������� �� ���� �� ���������� �����
Rat operator/(int x, const Rat& r)
{ 
    return Rat(x*r.den, r.num);
}

int main()
{ 
    // ��������� �� ������������ ����� r
    int a, b;
    cout << "a, b= "; cin >> a >> b;
    Rat r(a, b);
    // ������������� �� r � ������ ����� � ���������
    cout << r << endl;
    // ��������� �� ���������� �� 0 ���������� ����� s
    int c, d;
    do
    { 
        cout << "c, d = "; 
        cin >> c >> d;
    } while(c == 0 || d == 0);
    Rat s(c, d);

    // ��������� �� �������� �� 0 ���� �����
    int x; 
    do
    {
        cout << "�������� �������� �� 0 ���� �����: "; 
        cin >> x;
    } while(x == 0);

    // �������� �� ������, ���������, ��������������
    // � �������� �� ������������ ����� r � s
    Rat sum  = r + s;
    Rat sub  = r - s;
    Rat mult = r * s;
    Rat div  = r / s;

    // ��������� �� ������, ���������, ��������������
    // � �������� �� ������������ ����� r � s
    r.print(); cout << " + "; s.print();
    cout << " = "; sum.print(); cout << endl;
    r.print(); cout << " - "; s.print();
    cout << " = "; sub.print(); cout << endl;
    r.print(); cout << " * "; s.print();
    cout << " = "; mult.print(); cout << endl;
    r.print(); cout << " / "; s.print();
    cout << " = "; div.print(); cout << endl;

    // �������� �� ������, ���������, �������������� �
    // �������� �� ���������o�� ����� r � ������ ����� x
    Rat sum1  = r + x;
    Rat sub1  = r - x;
    Rat mult1 = r * x;
    Rat div1  = r / x;

    // ��������� �� ������, ���������, �������������� �
    // �������� �� ���������o�� ����� r � ������ ����� x
    r.print(); cout << " + " << x << " = ";
    sum1.print(); cout << endl;
    r.print(); cout << " - " << x << " = ";
    sub1.print(); cout << endl;
    r.print(); cout << " * " << x << " = ";
    mult1.print(); cout << endl;
    r.print(); cout << " / " << x << " = ";
    div1.print(); cout << endl;

    // �������� �� ������, ���������, �������������� �
    // �������� �� ������ ����� x � ���������o�� ����� s
    Rat sum2  = x + s;
    Rat sub2  = x - s;
    Rat mult2 = x * s;
    Rat div2  = x / s;

    // ��������� �� ������, ���������, �������������� �
    // �������� �� ������ ����� x � ���������o�� ����� s
    cout << x << " + "; s.print(); cout << " = ";
    sum2.print(); cout << endl;
    cout << x << " - "; s.print(); cout << " = ";
    sub2.print(); cout << endl;
    cout << x << " * "; s.print(); cout << " = ";
    mult2.print(); cout << endl;
    cout << x << " / "; s.print(); cout << " = ";
    div2.print(); cout << endl;

    return 0;
}
