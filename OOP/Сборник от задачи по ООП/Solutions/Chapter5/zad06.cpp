#include <iostream.h>

int main()
{
    unsigned int count = 0;
    int number;
    int sum = 0;
    cin.clear();   // �������� �� ����� ������� ��������� �� cin
    cin >> number;
    while(cin.good())
    {
        sum += number;
        ++count;
        cin >> number;
    }
    cin.clear();  // �������������� �� ����� ��������� �� ������
    if(count)
    {
        cout << "������ ������������� �� ���������� ����� � "
             << (double)sum/count << endl;
    }
    else
    {
        cout << "�� �� �������� �����." << endl;
    }
    return 0;
}
