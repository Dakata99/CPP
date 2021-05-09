#include <iostream.h>
#include <string.h>
#include <stdlib.h>

const int MAX = 100;         // ���������� ������� �� ��� �
const int MAXSIZE = 100;
char temp[MAXSIZE];          // ������� ���


// ����� �� ������� ������
class BankAccount
{
private:
    char* name;              // ��� �� ������
    char* accountnum;        // ����� �� ������� ������
    double balance;          // ������

public:
    // ��������� �����������
    // ����������� � ������������ �� ���������
    BankAccount(const char* = "", const char* = "",
                double = 0.0);
    // ����������� �� �����������
    BankAccount(const BankAccount&);
    // ����������
    ~BankAccount();
    // ���������� ������� �� �����������
    BankAccount& operator=(const BankAccount&);

    // ��������� �� ������� ������
    void print() const;
    // ������� �� ���� � ������� ������
    void put_in(double);
    // ������� �� ���� �� ������� ������
    void draw(double);
};

// ����������� � ������������ �� ���������
BankAccount::BankAccount(const char* n, const char* an, double b)
{
    name = new char[strlen(n)+1];
    if(!name)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(name, n);
    accountnum = new char[strlen(an)+1];
    if(!accountnum)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(accountnum, an);
    balance = b;
}

// ����������� �� �����������
BankAccount::BankAccount(const BankAccount& b)
{ 
    name = new char[strlen(b.name)+1];
    if(!name)
    { 
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(name, b.name);
    accountnum = new char[strlen(b.accountnum)+1];
    if(!accountnum)
    { 
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(accountnum, b.accountnum);
    balance = b.balance;
}

// ����������
BankAccount::~BankAccount()
{ 
    delete [] accountnum;
    delete [] name;
}

// ���������� ������� �� �����������
BankAccount& BankAccount::operator=(const BankAccount& b)
{ 
    if(this != &b)
    { 
        delete [] accountnum;
        delete [] name;
        name = new char[strlen(b.name)+1];
        if(!name)
        { 
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        strcpy(name, b.name);
        accountnum = new char[strlen(b.accountnum)+1];
        if(!accountnum)
        { 
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        strcpy(accountnum, b.accountnum);
        balance = b.balance;
    }
    return *this;
}

// ��������� �� ������ �� ������
void BankAccount::print() const
{ 
    cout << "��� �� ������: " << name << endl;
    cout << "����� �� ������: " << accountnum << endl;
    cout << "������: " << balance << endl;
}

// ������� �� ���� � ������� ������
void BankAccount::put_in(double cash)
{ 
    if(cash >= 0)
        balance = balance + cash;
    else
        cout << "���������� ���� �� ������� �� ����.\n";
}

// ������� �� ���� �� ������� ������
void BankAccount::draw(double cash)
{ 
    if(cash < 0)
    {
        cout << "���������� ���� �� ������� �� ����.\n ";
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
    cout << "��� �� ������: ";
    char n1[MAX]; cin.getline(n1, MAX);
    cout << "����� �� ������: ";
    char an1[MAX]; cin.getline(an1, MAX);
    double b1;
    cout << "������: "; cin >> b1;

    cin.ignore();        // ���������� �� ����� �� ���� �� ���
    // ��������� �� ������� ������
    BankAccount x(n1, an1, b1);
    // ��������� �� ��������� ������
    x.print();
    // ������� �� ���� � ������� ������
    // � ��������� �� ��������
    x.put_in(200);
    x.print();
    cout << "��� �� ������: ";
    char n2[MAX]; cin.getline(n2, MAX);
    cout << "����� �� ������: ";
    char an2[MAX]; cin.getline(an2, MAX);
    double b2;
    cout << "������: "; cin >> b2;
    cin.ignore();        // ���������� �� ����� �� ���� �� ���
    // ��������� �� ���� ������� ������
    BankAccount y(n2, an2, b2);
    // ��������� �� ��������� ������
    y.print();
    // ������� �� ���� �� ��������� ������
    // � ��������� �� ��������
    y.draw(250);
    y.print();
    return 0;
}
