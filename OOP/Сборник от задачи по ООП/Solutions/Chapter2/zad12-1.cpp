#include <iostream.h>

class fact
{ 
public:
    // �����������
    fact(int a)
    {
        x = a;
    }
    // �������� �� x!
    unsigned int value() const
    { 
        int y = 1;
        for(int i = 1; i <= x; i++)
            y *= i;
        return y;
    }

private:
    int x;
};

int main()
{ 
    int a;
    do
    { 
        cout << "a= "; 
        cin >> a;
    } while(a <= 0);

    // ��������� �� ����� t �� ���� fact
    fact t(a);
    // �������� � ��������� �� a!
    cout << t.value() << endl; 
    return 0;
}
