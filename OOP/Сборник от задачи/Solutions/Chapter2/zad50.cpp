#include <iostream.h>

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
    cout << "~BankAccount()\n";
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

template <class T>
void swap(T & x, T & y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    //// �)
    int a = 4, b = 9;
    swap(a, b);    // �������� ��������� swap(int&, int&)
    cout << a << " " << b << endl;

    //// �)
    double p = 1.5, q = -5.6;
    swap(p, q);     // �������� ��������� swap(double&, double&)
    cout << p << " " << q << endl;

    //// �)
    char c = 'a', d = 'd';
    swap(c, d);    // �������� ��������� swap(char&, char&)
    cout << c << " " << d << endl;

    //// �)
    BankAccount bacc_1("������ ��������","jd100", 1500),
        bacc_2("������ ������", "sp504", 2000);
    swap(bacc_1, bacc_2); // �������� ��������� swap(BankAccount&, BankAccount&)
    bacc_1.print(); bacc_2.print();
    return 0;
}
