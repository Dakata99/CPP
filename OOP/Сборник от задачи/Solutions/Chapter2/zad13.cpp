#include <iostream.h>

class gcd
{
public:
    // �����������
    gcd(int a, int b)
    {
        x = a; 
        y = b;
    }

    // �������� �� ���-������� ��� ������� �� x � y
    int value() const
    { 
        if(y == 0)
        {
            return x;
        }
        else
        { 
            gcd t(y, x%y);
            return t.value();
        }
    }

private:
    int x, y;
};

int main()
{
    int a, b;
    do
    {
        cout << "a= "; cin >> a;
        cout << "b= "; cin >> b;
    } while(a < 0 || b < 0 || a == 0 && b == 0);

    // ��������� �� ����� �� ���� gcd
    gcd t(a,b);
    // �������� � ��������� �� ���-�������
    // ��� ������� �� a � b
    cout << t.value() << endl;
    return 0;
}
