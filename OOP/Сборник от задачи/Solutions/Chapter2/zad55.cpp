#include <iostream.h>
#include <string.h>
#include <stdlib.h>

const int MaxLengthName = 30;    // ���������� ������� �� ���
const int PATIENTS = 100;        // ���������� ���� �� ����������

// ��������� �� ���� Date
class Date
{ 
private:
    int theDay,                     // ���
        theMonth,                   // �����
        theYear;                    // ������

public:
    Date(int = 1, int = 1, int = 2000);    // �����������
    int Day() const;                 // ������ �� ���
    int Month() const;               // ������ �� �����
    int Year() const;                // ������ �� ������
    void setDay(int);                // ������� �� ���
    void setMonth(int);              // ������� �� �����
    void setYear(int);               // ������� �� ������
    void print() const;              // ��������� �� ����
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

Date date(1, 1, 2000);            // ������������ �� ����

// ��������� �� ���� Patient
class Patient
{ 
public:
    // ��������� �����������
    Patient(const char * = "", const Date& = date, int = 0);
    ~Patient();
    Patient(const Patient&);
    Patient& operator=(const Patient&);
    // ������� �� ������
    const char* getName() const;        // ������ �� ���
    Date getDOB() const;                // ������ �� ���� �� �������
    int getVisits() const;              // ������ �� ���� ������
    void print() const;                 // ��������� �� �������

private:
    char* Name;                         // ��� �� �������
    Date DOB;                           // ���� �� ������� �� �������
    int Visits;                         // ���� ��������� �� ��������
};

Patient::Patient(const char * n, const Date& d, int v)
{ 
    Name = new char[strlen(n)+1];
    if(!Name)
    { 
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(Name, n);
    DOB = d;
    Visits = v;
}

Patient::~Patient()
{ 
    delete [] Name;
}

Patient::Patient(const Patient& P)
{ 
    Name = new char[strlen(P.Name)+1];
    if(!Name)
    { 
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(Name, P.Name);
    DOB = P.DOB;
    Visits = P.Visits;
}

Patient& Patient::operator=(const Patient& P)
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
        Visits = P.Visits;
    }
    return *this;
}

const char* Patient::getName() const
{ 
    return Name;
}

Date Patient::getDOB() const
{ 
    return DOB;
}

int Patient::getVisits() const
{ 
    return Visits;
}

void Patient::print() const
{
    cout << "���: " << Name << "\n";
    cout << "����: "; DOB.print();
    cout << "���� �� ��������: " << Visits << endl; 
}

// ��������� �� ���� Doctor
class Doctor
{ 
public:
    // ��������� �����������
    Doctor(const char* = "", int = 0);
    ~Doctor();
    Doctor(const Doctor&);
    Doctor& operator=(const Doctor&);
    const char* getName() const;    // ������ �� ��� �� �����
    // ����-������� �� ����������� �� �������
    void registerPatient(const Patient&);
    // ����-������� �� �������� ��
    // ������� ���� ������ �� ������
    double average() const;
    // ��������� �� ����������, ��������� ��-
    // ����� ���� ������ �� �������� �����
    void printUpper(int) const;

private:
    char* Name;                       // ��� �� �����
    Patient* PatientsList;            // ����� � ���������� �� ������
    int PatientsRegistered;           // ���� �� �������������� ��������
    static int Registered;            // ����� ����������� �������
};

int Doctor::Registered = 0;     // ������������� �� ���������� ����-�����

Doctor::Doctor(const char* n, int reg)
{ 
    Name = new char[strlen(n)+1];
    if(!Name)
    { 
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(Name, n);
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
    delete [] Name;
    delete [] PatientsList;
}

Doctor::Doctor(const Doctor& D)
{ 
    Name = new char[strlen(D.Name)+1];
    if(!Name)
    { 
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    strcpy(Name, D.Name);
    PatientsRegistered = D.PatientsRegistered;
    PatientsList = new Patient[PatientsRegistered];
    if(!PatientsList)
    { 
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    for(int i = 0; i < PatientsRegistered; i++)
        PatientsList[i] = D.PatientsList[i];
}

Doctor& Doctor::operator=(const Doctor& D)
{ 
    if(this != &D)
    { 
        delete [] Name;
        delete [] PatientsList;
        Name = new char[strlen(D.Name)+1];
        if(!Name)
        { 
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        strcpy(Name, D.Name);
        PatientsRegistered = D.PatientsRegistered;
        PatientsList = new Patient[PatientsRegistered];
        if(!PatientsList)
        { 
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        for(int i = 0; i < PatientsRegistered; i++)
            PatientsList[i] = D.PatientsList[i];
    }
    return *this;
}

const char* Doctor::getName() const
{ 
    return Name;
}

void Doctor::registerPatient(const Patient& P)
{
    PatientsList[Registered] = P;
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
    int n;
    do
    { 
        cout << "���� �� ���������� �� �����: ";
        cin >> n;
    } while(n < 0 || n > PATIENTS);

    // ��������� �� ������ � ����� �� ���������� �� �����
    Doctor d1("Petrov", n);
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
        cout << "���� ������ �� �������: ";
        cin >> vis;
        Patient P(NamePatient, dat, vis);
        d1.registerPatient(P);
    }

    // �������� � ��������� �� ������� ����
    // ��������� �� �������� ��� ������
    cout << "������ ���� ��������� �� ��������: "
         << d1.average() << endl;
    // ��������� �� ����������, ���������
    // ������ �� 3 ��������� ��� ������
    if(n > 0) d1.printUpper(3);
    return 0;
}
