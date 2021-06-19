#include <iostream.h>

class Fraction
{
private:
    int n, d;

public:
    // �����������
    Fraction(int x, int y);
    // ������� �� ������ �� ������������
    int getN() const;
    int getD() const;
    // ���������� �� ������� ������� �� �����
    friend bool IsFraction(const Fraction& obj);
};

Fraction::Fraction(int x, int y)
{
    n = x;
    d = y;
}

int Fraction::getN() const
{ 
    return n;
}

int Fraction::getD() const
{ 
    return d;
}

// ������ �������, ������� �� ����� Fraction
bool IsFraction(const Fraction& obj)
{ 
    return obj.n % obj.d != 0;
}

int main()
{ 
    // ���������� �� ����� �� ����� Fraction
    int a, b;
    do
    { 
        cout << "a, b (b �������� �� 0): ";
        cin >> a >> b;
    } while(b == 0);

    Fraction f(a, b);
    // �������� ���� ������� ���� ����� �� ������ f1
    // �� �� ���� �� ������� ���� �����
    if(IsFraction(f))
        cout << f.getN() << " �� �� ���� �� " << f.getD() << endl;
    else
        cout << f.getN() << " �� ���� �� " << f.getD() << endl;
    return 0;
}
