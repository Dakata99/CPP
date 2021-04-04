#include <iostream.h>

const int MAX = 20;

class differ
{
public:
    // ����������� � ���������, ������� ��������� �� ������
    differ(int m)
    { 
        n = m;
        for(int i = 0; i < m; i++)
            cin >> a[i];
    }

    // �������, ����� �������� ���� ��������������
    // �� ������ �� ������ �� �������� �����
    bool diff() const
    { 
        if(n == 1) return true;
        int i = -1;
        bool b; int j;
        do
        { 
            i++; j = i;
            do
            { 
                j++;
                b = a[i] != a[j];
            } while (b && j < n-1);
        } while (b && i < n-2);
        return b;
    }

private:
    int n;                       // ���� �������� �� ������
    int a[MAX];                  // ������� �� ������
};

int main()
{ 
    // ��������� �� ������
    int n;
    do
    { 
        cout << "n= "; 
        cin >> n;
    } while (n < 1);

    // ��������� �� ����� t �� ����� differ,
    // ������� �������� ������ �� ���� �����
    differ t(n);
    // �������� ���� ���������� �� ��������,
    // �������� ���� ������ t �� ��������
    cout << "���������� �� �������� " 
         << (t.diff()? "�� ��������.\n" : "�� �� ��������.\n");
    return 0;
}
