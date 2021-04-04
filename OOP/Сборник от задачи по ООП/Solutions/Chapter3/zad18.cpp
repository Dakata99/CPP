#include <iostream.h>
#include <string.h>
#include <stdlib.h>

class Date
{ 
private:
    int theDay,                      // ���
        theMonth,                    // �����
        theYear;                     // ������

public:
    Date(int = 1, int = 1, int = 2000); // �����������
    int Day() const;                    // ������ �� ���
    int Month() const;                  // ������ �� �����
    int Year() const;                   // ������ �� ������
    void setDay(int);                   // ������� �� ���
    void setMonth(int);                 // ������� �� �����
    void setYear(int);                  // ������� �� ������
    void print() const;                 // ��������� �� ����
};

Date::Date(int d, int m, int y)
{ 
    theDay = d;
    theMonth = m;
    theYear = y;
}

int Date::Day() const
{ 
    return theDay;
}

int Date::Month() const
{ 
    return theMonth;
}

int Date::Year() const
{ 
    return theYear;
}

void Date::setDay(int d)
{ 
    theDay = d;
} 

void Date::setMonth(int m)
{ 
    theMonth = m;
}

void Date::setYear(int y)
{ 
    theYear = y;
}

void Date::print() const
{ 
    cout << theDay << "." << theMonth 
         << "." << theYear << endl;
}


const int MaxLengthName = 30;        // ���������� ������� �� ���
const int PATIENTS = 100;            // ���������� ���� �� ����������
const Date DATE(1, 1, 1900);         // ������������ �� ����

// ��������� �� ���� Person
class Person
{ 
public:

    // ��������� �����������
    Person(const char* = "", const Date& = DATE);
    ~Person();
    Person(const Person&);
    Person& operator=(const Person&);
    // ����-������� �� ������
    const char* getName() const;    // ������ �� ���
    Date getDOB() const;            // ������ �� ���� �� �������
    void print() const;             // ��������� �� ������� �� ����
private:
    char* Name;                     // ��� �� ����
    Date DOB;                       // ���� �� ������� �� ����
};

Person::Person(const char* n, const Date& d)
{
    Name = new char[strlen(n)+1];
    if(!Name)
    { 
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(Name, n);
    DOB = d;
}

Person::~Person()
{
    delete [] Name;
}

Person::Person(const Person& P)
{
    Name = new char[strlen(P.Name)+1];
    if(!Name)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(Name, P.Name);
    DOB = P.DOB;
}

Person& Person::operator=(const Person& P)
{
    if(this != &P)
    {
        delete [] Name;
        Name = new char[strlen(P.Name)+1];
        if(!Name)
        {
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        strcpy(Name, P.Name);
        DOB = P.DOB;
    }
    return *this;
}

const char* Person::getName() const
{ 
    return Name;
}

Date Person::getDOB() const
{
    return DOB;
}

void Person::print() const
{
    cout << "���: " << Name << "\n";
    cout << "����: "; DOB.print();
}

// ��������� �� ���� Patient
class Patient : public Person
{
public:
    // �����������
    Patient(char * = "", Date = DATE, int = 0);
    int getVisits() const;        // ������ �� ���� ������
    void print() const;           // ��������� �� �������

private:
    int Visits;                   // ���� ��������� �� ��������
};

Patient::Patient(char * n, Date d, int v) : Person(n, d)
{
    Visits = v;
}

int Patient::getVisits() const
{
    return Visits;
}

void Patient::print() const
{
    Person::print();
    cout << "���� �� ��������: " << Visits << endl; 
}

// ��������� �� ���� Doctor
class Doctor : public Person
{
public:
    // ��������� �����������
    Doctor(char* = "", const Date& = DATE, int = 0);
    ~Doctor();
    Doctor(const Doctor&);
    Doctor& operator=(const Doctor&);
    // 
    void registerPatient(const Patient&);
    // ����-������� �� �������� �� ������� ���� ������ �� �����
    double average() const;
    // ��������� �� ����������, ��������� ��-�����
    // ���� ������ �� ��������� ����������
    void printUpper(int) const;

private:
    Patient* PatientsList;      // ������ � ���������� �� �����
    int PatientsRegistered;     // ���� �� �������������� ��������
    static int Registered;      // ������� ����� �� ����������� �������
};

int Doctor::Registered = 0;     // ������������� �� ���������� ����-�����

Doctor::Doctor(char* n, const Date& d, int reg) : Person(n, d)
{
    PatientsRegistered = reg;
    PatientsList = new Patient[PatientsRegistered];
    if(!PatientsList)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
}

Doctor::~Doctor()
{
    delete [] PatientsList;
}

Doctor::Doctor(const Doctor& d) : Person(d)
{
    PatientsRegistered = d.PatientsRegistered;
    PatientsList = new Patient[PatientsRegistered];
    if(!PatientsList)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    for(int i = 0; i < PatientsRegistered; i++)
        PatientsList[i] = d.PatientsList[i];
}

Doctor& Doctor::operator=(const Doctor& d)
{
    if(this != &d)
    {
        Person::operator=(d);
        delete [] PatientsList;
        PatientsRegistered = d.PatientsRegistered;
        PatientsList = new Patient[PatientsRegistered];
        if(!PatientsList)
        { 
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        for(int i = 0; i < PatientsRegistered; i++)
            PatientsList[i] = d.PatientsList[i];
    }
    return *this;
}

void Doctor::registerPatient(const Patient& p)
{
    PatientsList[Registered] = p;
    Registered++;
}

double Doctor::average() const
{
    int totalVisits = 0;
    for(int i = 0; i < PatientsRegistered; i++)
        totalVisits += PatientsList[i].getVisits();
    if(PatientsRegistered != 0)
        return double(totalVisits)/PatientsRegistered;
    else return 0;
}

void Doctor::printUpper(int lim) const
{
    cout << "�������� � ��������� ��� ������!\n";
    for(int i = 0; i < PatientsRegistered; i++)
        if(PatientsList[i].getVisits() > lim)
            PatientsList[i].print();
}

int main()
{
    // ��������� �� ���� �� ���������� �� �����
    int n;
    do
    {
        cout << "���� �� ����������: ";
        cin >> n;
    } while(n < 0 || n > PATIENTS);

    // ��������� �� ������ �� ������� �� �����
    Date DOB_Petrov(5, 10, 1975);
    // ��������� �� �����, ���������� "�����" � n ��������
    Doctor d1("Petrov", DOB_Petrov, n);
    for(int i = 0; i < n; i++)
    { 
        cin.ignore();
        cout << "��� �� �������: ";
        char NamePatient[MaxLengthName];
        cin.getline(NamePatient, MaxLengthName+1);
        int d, m, y;
        cout << "���: "; cin >> d;
        cout << "�����: "; cin >> m;
        cout << "������: "; cin >> y;
        Date dat(d, m, y);

        int vis;
        cout << "���� ������ �� �������:";
        cin >> vis;
        Patient P(NamePatient, dat, vis);
        d1.registerPatient(P);
    }

    // ��������� �� ������� ���� ��������� ��� ������
    cout << d1.average() << endl;

    // ��������� �� ����������, ��������� ������ �� 3 ���������
    if(n > 0) d1.printUpper(3);
    return 0;
}
