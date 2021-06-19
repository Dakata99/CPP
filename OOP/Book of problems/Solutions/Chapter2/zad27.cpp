#include <iostream.h>

class M
{
private:
    int a;
    double b;

public:
    M(int = 5, double = 2.5);
    void set(int, double);
    void display() const;
};

// �����������
M::M(int x, double y)
{
    a = x;
    b = y;
}

// �������
void M::set(int x, double y)
{
    a = x;
    b = y;
}

// ����-������� �� ��������� �� ����� �� �����
void M::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    M *p;
    // �������� �� ����� �� ����� �� 5 ������
    p = new M[5];
    if(!p)
    {
        cout << "������ ��� �������� �� �����!\n";
        return 1;
    }

    int i;
    // ��������� �� ������, ������� ���������
    for(i = 0; i < 5; i++)
        p[i].display();
    
    // ��������� �� ������������ �� ��������
    // �� ������, ������� ���������
    for(i = 0; i < 5; i++)
        p[i].set(i, i+1.5);
    
    // ��������� �� ������
    for(i = 0; i < 5; i++)
        p[i].display();
    
    // ������������� �� ���������� �� ������ �����
    delete [] p;
    return 0;
}
