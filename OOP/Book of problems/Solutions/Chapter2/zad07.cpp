#include <iostream.h>
#include <iomanip.h>

class Employee
{ 
public:
    void read();              // ��������� �� ����� �� ��������
    void print() const;       // ��������� �� ����� �� ��������

private:
    struct
    { 
        char first[16];       // ��������� ���
        char last[16];        // ������� ���
    } name;
    struct
    { 
        double hours;         // ������ �� ������
        double salary;        // ������� �� 1 ���
    } work;
};

void Employee::read()
{
    cout << "��������� ���: ";
    cin >> name.first;
    cout << "������� ���: ";
    cin >> name.last;
    cout << "������ �� ������: ";
    cin >> work.hours;
    cout << "��������� �� 1 ���: ";
    cin >> work.salary;
    cin.ignore();    // ���������� �� ������� �� ���� �� ���
}

void Employee::print() const
{
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << name.first << " " << name.last << " "
         << work.hours * work.salary << endl;
}

int main()
{
    // ���������� �� ��������
    Employee e; 
    e.read();
    // ��������� �� ����� � ��������� �� ��������
    e.print();
    return 0;
}
