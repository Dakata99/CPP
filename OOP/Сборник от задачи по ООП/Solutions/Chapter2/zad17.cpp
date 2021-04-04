#include <iostream.h>
#include <string.h>

const int MAX_NAME = 24;
const int MAX_NUM = 16;

class BankAccount
{
private:
    char name[MAX_NAME];            // ��� �� ������
    char accountnum[MAX_NUM];       // ����� �� ������� ������
    double balance;                 // ������

public:
    // �����������
    BankAccount(const char * = "", const char * = "0", double = 0.0);
    // ����-�������, ����� ������� ������� ������
    void print() const;
    // ����-�������, ����� ��������� �������
    // �� ���� � ������� ������
    void put_in(double);
    // ����-�������, ����� ��������� �������
    // �� ���� �� ������� ������
    void draw(double);
};

BankAccount::BankAccount(const char * cl, const char * n, double b)
{
    strncpy(name, cl, MAX_NAME-1);
    name[MAX_NAME-1] = '\0';
    strncpy(accountnum, n, MAX_NUM);
    accountnum[MAX_NUM] = '\0';
    balance = b;
}

void BankAccount::print() const
{
    cout << "��� �� ������: " << name << endl;
    cout << "����� �� ������: " << accountnum << endl;
    cout << "������: " << balance << endl;
}

void BankAccount::put_in(double cash)
{
    if(cash >= 0)
        balance = balance + cash;
    else
        cout << "���������� ���� �� ������� �� ����.\n";
}

void BankAccount::draw(double cash)
{
    if(cash < 0)
    {
        cout << " ���������� ���� �� ������� �� ����.\n ";
    }
    else
    {
        if(cash <= balance)
            balance = balance - cash;
        else
            cout << "�������� �� ������� ���������� ����.\n";
    }
}

int main()
{
    // ��������� �� ������� ������ x, y � z �
    // ��������� �� ��������� ������
    BankAccount x;
    x.print();
    BankAccount y("Peter Ivanov", "PIvanov1923", 6123.65);
    y.print();
    BankAccount z = BankAccount("Georgi Petrov", "GPetrov3917", 819.60);
    z.print();

    // ������� �� ���� � ������� ������
    // x � ��������� �� ��������
    x.put_in(20);
    x.print();
    
    // ������� �� ���� �� ������� ������ y � z
    // � ��������� �� ��������
    y.draw(250);
    y.print();
    z.draw(50);
    z.print();
    return 0;
}
