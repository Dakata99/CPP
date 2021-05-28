#include <iostream.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip.h>

const int MAXSIZE = 50;           // ���������� ������� �� ��� � �� ��� ������
// ��������� �� ���� Worker, ���������
// �������� �� ��� � ��������� �� 1 ���
class Worker
{
public:
    // ��������� ����������� �� �����
    Worker(const char* = "", double = 0.0);
    Worker(const Worker&);
    ~Worker();
    Worker& operator=(const Worker&);
    // ��������� �� ������� �� ��������
    void print() const;
    // ������� �� ������ �� ����-������� salary
    double get_Salary() const;

private:
    char* name;              // ��� �� ��������
    double salary;           // ��������� �� 1 ��� �� ��������
};

// �����������
Worker::Worker(const char* n, double s)
{
    name = new char[strlen(n)+1];
    if(!name)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(name, n);
    salary = s;
}

// ����������� �� �����������
Worker::Worker(const Worker& w)
{
    name = new char[strlen(w.name)+1];
    if(!name)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(name, w.name);
    salary = w.salary;
}

// ����������
Worker::~Worker()
{ 
    delete [] name;
}

// ������������� �� ��������� =
Worker& Worker::operator=(const Worker& w)
{
    if(this != &w)
    {
        delete [] name;
        name = new char[strlen(w.name)+1];
        if(!name)
        {
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        strcpy(name, w.name);
        salary = w.salary;
    }
    return *this;
}

// ��������� �� ������� �� ��������
void Worker::print() const
{
    cout << setw(20) << name 
         << setw(12) << salary;
}

// ����-������� �� ������ �� ����������� �� 1 ���
double Worker::get_Salary() const
{
    return salary;
}

// ��������� �� ����� HourlyWorker, ���������
// ������� �������� ���� ��������, ��������� ����
// ��� ������ ���������� ���������� ������
class HourlyWorker : public Worker
{
public:
    // ��������� ����������� �� �����
    HourlyWorker(const char* = "", double = 0.0, const char* = "", int = 0);
    HourlyWorker(const HourlyWorker&);
    ~HourlyWorker();
    HourlyWorker& operator=(const HourlyWorker&);
    // �������� �� ���������� ������� �� ������� ��������
    double WeekSalary() const;
    // ��������� �� ����-������� � ���������� ������� �� ������� ��������
    void print() const;
private:
    char* work;         // ��� ���������� ������
    int hours;          // ���� ���������� ������
};

// �����������
HourlyWorker::HourlyWorker(const char* n, double s,
                           const char* w, int h) : Worker(n, s)
{
    work = new char[strlen(w)+1];
    if(!work)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(work, w);
    hours = h;
}

// ����������� �� �����������
HourlyWorker::HourlyWorker(const HourlyWorker& p) : Worker(p)
{
    hours = p.hours;
    work = new char[strlen(p.work)+1];
    if(!work)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(work, p.work);
}

// ����������
HourlyWorker::~HourlyWorker()
{
    delete [] work;
}

// ������������� �� ��������� =
HourlyWorker& HourlyWorker::operator=(const HourlyWorker& p)
{
    if(this != &p)
    {
        Worker::operator=(p);
        delete [] work;
        hours = p.hours;
        work = new char[strlen(p.work)+1];
        if(!work)
        {
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        strcpy(work, p.work);
    }
    return *this;
}

// �������� �� ���������� ������� �� ������� ��������
double HourlyWorker::WeekSalary() const
{
    double x, y = get_Salary();
    if(hours <= 40)
        x = hours*y; 
    else if(hours <= 60) 
        x = 40*y + (hours-40)*1.5*y;
    else 
        x = 40*y + 20*1.5*y + (hours-60)*2*y;
    return x;
}

// ��������� �� ����-������� � ���������� ������� �� ������� ��������
void HourlyWorker::print() const
{
    Worker::print();
    cout << setw(10) << hours
         << setw(20) << work
         << setw(10) << WeekSalary() << endl;
}

// ��������� �� ����� SalariedWorker, ���������
// ����� �������� ���� ��������, ��������� ����
// ��� ������ ���������� ���������� ������
class SalariedWorker : public Worker
{
public:
    // ��������� ����������� �� �����
    SalariedWorker(const char* = "", double = 0.0, const char* = "", int = 0);
    SalariedWorker(const SalariedWorker&);
    ~ SalariedWorker();
    SalariedWorker& operator=(const SalariedWorker&);
    // �������� �� ���������� ������� �� ����� ��������
    double WeekSalary() const;
    // ��������� �� ����-������� � ���������� ������� �� ����� ��������
    void print() const;

private:
    char* work;         // ��� ���������� ������
    int hours;          // ���� ���������� ������
};

// ����������� �� ������������
SalariedWorker::SalariedWorker(const char* n, double s,
                               const char* w, int h)
                               : Worker(n, s)
{
    work = new char[strlen(w)+1];
    if(!work)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(work, w);
    hours = h;
}

// ����������� �� �����������
SalariedWorker::SalariedWorker(const SalariedWorker& p) 
                               : Worker(p)
{
    hours = p.hours;
    work = new char[strlen(p.work)+1];
    if(!work)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(work, p.work);
}

// ����������
SalariedWorker::~SalariedWorker()
{
    delete [] work;
}

// ������������� �� ��������� =
SalariedWorker& SalariedWorker::operator=(const SalariedWorker& p)
{
    if(this != &p)
    {
        Worker::operator=(p);
        delete [] work;
        work = new char[strlen(p.work)+1];
        if(!work)
        {
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        strcpy(work, p.work); 
        hours = p.hours;
    }
    return *this;
}

// ���������� �� ���������� ������� �� ����� ��������
double SalariedWorker::WeekSalary() const
{
    return 40 * get_Salary();
}

// ��������� �� ����-������� � ����������
// ������� �� ����� ��������
void SalariedWorker::print() const
{
    Worker::print();
    cout << setw(10) << hours
         << setw(20) << work
         << setw(10) << WeekSalary() << endl;
}

// ��������� �� �����, �������� ����� �� �������� ���������
void Create_HourlyWorker_arr(int m, HourlyWorker**& arr)
{
    cout << "��������� �� ����� � ����� ��"
            " ���������� ��������� \n";
    // ������� � ���������� � ����������� ����� � ���������� ��
    // �� ��������� ��� ������ �� ���� HourlyWorker.
    arr = new HourlyWorker*[m];
    if(!arr)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    for(int i = 0; i < m; i++)
    {
        char n[MAXSIZE];
        cout << "��� �� ��������: ";
        cin.getline(n, MAXSIZE);    // ��������� �� ����� �� ��������
        double s;
        cout << "��������� �� 1 ��� �� ��������: ";
        cin >> s;                   // ��������� �� ����������� �� 1 ���
        cin.ignore();               // ���������� �� ������� �� ���� �� ���
        char w[MAXSIZE];
        cout << "��� �� ���������� ������: ";
        cin.getline(w, MAXSIZE);    // ��������� �� ���� �� ������
        int h;
        cout << "���� ������ �� ������: ";
        cin >> h;                   // ��������� �� �������� �� ������
        cin.ignore();               // ���������� �� ������� �� ���� �� ���
        arr[i] = new HourlyWorker(n, s, w, h);
        if(!arr[i])
        {
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
    }
}

// ��������� �� ����-������� � ���������� �������
// �� ���������� ��������� �� ������
void Print_HourlyWorker_arr(int n, HourlyWorker** arr)
{
    cout << "������ �� ���������� ���������\n";
    cout << setw(20) << "���"
         << setw(12) << "����./1 �."
         << setw(10) << "������"
         << setw(20) << "��� ������"
         << setw(10) << "�������\n";
    for(int i = 0; i < n; i++)
        arr[i]->print();
}

// ��������� � �������� ��� �� ������� ��
// ��������� �� ���������� �� ������
void Sort_HourlyWorker_arr(int n, HourlyWorker** arr)
{
    // ��������� �� ������ �� ������� ��������
    for(int i = 0; i < n-1; i++)
    {
        int k = i; double max = arr[i]->WeekSalary();
        for(int j = i+1; j < n; j++)
        {
            if(arr[j]->WeekSalary() > max)
            {
                max = arr[j]->WeekSalary();
                k = j;
            }
        }
        HourlyWorker * ptr = arr[i];
        arr[i] = arr[k];
        arr[k] = ptr;
    }
}

// ������������� �� ������� �� ������ � ���������� �� �����
void Delete_HourlyWorker_arr(int n, HourlyWorker** arr)
{
    for(int i = 0; i < n; i++)
        delete arr[i];
    delete [] arr;
}

// ��������� �� �����, �������� ����� �� ����� ���������
void Create_SalariedWorker_arr(int m, SalariedWorker**& arr)
{
    cout << "��������� �� ����� � ����� ��"
        " ������� ��������� \n";
    // ������� � ���������� � ����������� ����� � ���������� ��
    // �� ��������� ��� ������ �� ���� SalariedWorker.
    arr = new SalariedWorker*[m];
    if(!arr)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    for(int i = 0; i < m; i++)
    {
        char n[MAXSIZE];
        cout << "��� �� ��������: ";
        cin.getline(n, MAXSIZE);    // ��������� �� ����� �� ��������
        double s;
        cout << "��������� �� 1 ��� �� ��������: ";
        cin >> s;                   // ��������� �� ����������� �� 1 ���
        cin.ignore();               // ���������� �� ������� �� ���� �� ���
        char w[MAXSIZE];
        cout << "��� �� ���������� ������: ";
        cin.getline(w, MAXSIZE);    // ��������� �� ���� �� ������
        int h;
        cout << "���� ������ �� ������: ";
        cin >> h;                   // ��������� �� �������� �� ������
        cin.ignore();               // ���������� �� ������� �� ���� �� ���
        arr[i] = new SalariedWorker(n, s, w, h);
        if(!arr[i])
        {
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
    }
}

// ��������� �� ����-������� � ����������
// ������� �� ������� ��������� �� ������
void Print_SalariedWorker_arr(int m, SalariedWorker** arr)
{
    cout << "������ �� ������� ���������\n";
    cout << setw(20) << "���"
         << setw(12) << "����./1 �"
         << setw(10) << "������"
         << setw(20) << "��� ������"
         << setw(10) << "�������\n";
    for(int i = 0; i < m; i++)
        arr[i]->print();
}

// ��������� � �������� ��� �� ������ ��
// ��������� �� ���������� �� ������
void Sort_SalariedWorker_arr(int m, SalariedWorker** arr)
{
    // ��������� �� ������ �� ������� ��������
    for(int i = 0; i < m-1; i++)
    {
        int k = i; 
        double max = arr[i]->WeekSalary();
        for(int j = i+1; j < m; j++)
        {
            if(arr[j]->WeekSalary() > max)
            { 
                max = arr[j]->WeekSalary();
                k = j;
            }
        }
        SalariedWorker * ptr = arr[i];
        arr[i] = arr[k];
        arr[k] = ptr;
    }
}

// ������������� �� ������� �� ������ � ���������� �� �����
void Delete_SalariedWorker_arr(int n, SalariedWorker** arr)
{
    for(int i = 0; i < n; i++)
        delete arr[i];
    delete [] arr;
}

int main()
{
    // ��������� �� ���� �� ���������� �� ������
    // � ����� �� ���������� ���������
    int n; cout << "n= "; cin >> n;
    cin.ignore();        // ���������� �� ������� �� ���� �� ���
    // ����������� �� ������ � ����� �� ���������� ���������
    HourlyWorker** hourly_arr = NULL;
    // ��������� �� ������ � ����� �� ���������� ���������
    Create_HourlyWorker_arr(n, hourly_arr);
    // ��������� �� ������ � ����� �� ���������� ���������
    Print_HourlyWorker_arr(n, hourly_arr);
    // ��������� �� ���� �� ���������� �� ������
    // � ����� �� ������� ���������
    int m; cout << "m= "; cin >> m;
    cin.ignore();        // ���������� �� ������� �� ���� �� ���
    // ����������� �� ������ � ����� �� ������� ���������
    SalariedWorker** salaried_arr = NULL;
    // ��������� �� ������ � ����� �� ������� ���������
    Create_SalariedWorker_arr(m, salaried_arr);
    cout << endl;
    // ��������� �� ������ � ����� �� ������� ���������
    Print_SalariedWorker_arr(m, salaried_arr);
    // ��������� � �������� ��� �� ������a �� ���������
    // �� ������ � ����� �� ���������� ���������
    Sort_HourlyWorker_arr(n, hourly_arr);
    // ��������� �� ���������� �����
    // � ����� �� ���������� ���������
    Print_HourlyWorker_arr(n, hourly_arr);
    // ��������� � �������� ��� �� ������a �� ���������
    // �� ������ � ����� �� ������� ���������
    Sort_SalariedWorker_arr(m, salaried_arr);
    // ��������� �� ���������� �����
    // � ����� �� ������� ���������
    Print_SalariedWorker_arr(m, salaried_arr);
    // ������������� �� ������� �� ������
    // hourly_arr � ���������� �� �����
    Delete_HourlyWorker_arr(n, hourly_arr);
    // ������������� �� ������� �� ������
    // salaried_arr � ���������� �� �����
    Delete_SalariedWorker_arr(m, salaried_arr);
    return 0;
}
