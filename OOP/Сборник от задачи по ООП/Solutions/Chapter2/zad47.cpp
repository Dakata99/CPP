#include <iostream.h>
#include <iomanip.h>
#include <math.h>

class Expr
{ 
public:
    // �����������
    Expr(int, double);
    // ����-������� �� �������� �� S1
    double Ex1() const;
    // ����-������� �� �������� �� S2
    double Ex2() const;
    // ����-������� �� �������� �� S3
    double Ex3() const;

private:
    int n;
    double x;
};

Expr::Expr(int m, double y)
{ 
    n = m;
    x = y;
}

double Expr::Ex1() const
{ 
    double S = 1, x1 = 1;
    for(int i = 1; i <= n; i++)
    { 
        x1 = x1*x/i;
        S += x1;
    }
    return S;
}

double Expr::Ex2() const
{ 
    double S = 1, x1 = 1;
    for(int i = 1; i <= 2*n; i = i+2)
    { 
        x1 = -x1*x*x/(i*(i+1));
        S += x1;
    }
    return S;
}

double Expr::Ex3() const
{ 
    double S = x, x1 = x;
    for(int i = 2; i <= 2*n; i = i+2)
    { 
        x1 = -x1*x*x/(i*(i+1));
        S += x1;
    }
    return S;
}

int main()
{
    int n;
    // ��������� �� �������� �� n
    do
    {
        cout << "n= ";
        cin >> n;
    } while (n < 0);

    double x;
    // ��������� �� �������� �� x
    do
    {
        cout << "x= ";
        cin >> x;
    } while(fabs(x) > 1);

    // ���������� �� ����� t �� ����� Expr
    Expr t(n, x);

    cout << setiosflags(ios::fixed) << setprecision(6);
    // ���������� �� �������� ���
    // ����-������� �� ����� Expr
    double (Expr::*ptr)() const;
    char ch;
    cout << "�������� �������, ����� �������� \n"
         << "������� �� ���� �����������: \n"
         <<  "exp --> a \n"
             "cos --> b \n"
             "sin --> c \n";
    cin >> ch;

    // ����� �� ����-������� �� ����������
    switch (ch)
    { 
    case 'a': ptr = &Expr::Ex1;
        cout << "exp(" << x << ")= ";
        break;
    case 'b': ptr = &Expr::Ex2;
        cout << "cos(" << x << ")= ";
        break;
    case 'c': ptr = &Expr::Ex3;
        cout << "sin(" << x << ")= ";
    }

    // �������� � ��������� �� ����������
    // �� ����������� ����-�������
    cout << (t.*ptr)() << endl;
    return 0;
}
