#include <iostream.h>
#include <string.h>

const int MaxLengthName = 30;        // ���������� ������� �� ���
const int PATIENTS = 200;            // ���������� ���� ��������

// ��������� �� ���� Date
class Date
{ 
private:
    int theDay,                      // ���
        theMonth,                    // �����
        theYear;                     // ������

public:
    Date(int = 1, int = 1, int = 2000);    // �����������
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

// ��������� �� ���� Patient
class Patient
{ 
public:
    Patient();                                // ����������� �� ������������
    Patient(char *, const Date&, int);        // ����������� � ���������
    const char* getName() const;              // ������ �� ���
    Date getDOB() const;                      // ������ �� ���� �� �������
    int getVisits() const;                    // ������ �� ���� ���������
    void print() const;                       // ��������� �� �������

private:
    char Name[MaxLengthName];                 // ��� �� �������
    Date DOB;                                 // ���� �� ������� �� �������
    int Visits;                               // ���� ��������� �� ��������
};

Patient::Patient()
{ 
    Visits = 0;
}

Patient::Patient(char * n, const Date& d, int v)
{ 
    strcpy(Name, n);
    DOB = d;
    Visits = v;
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
    Doctor(char*);                          // �����������
    const char* getName() const;            // ������ �� ��� 
    //������������ �� �������
    void registerPatient(const Patient&);
    // �������� �� ������� ���� �� ����������� �� ����������
    double average() const;
    // ��������� �� ����������, ��������� ��-����� ����
    // ��������� �� �������� ���� ��������� ����
    void printUpper(int) const;

private:
    char Name[MaxLengthName];               // ��� �� �����
    Patient PatientsList[PATIENTS];         // ����� � ���������� �� ������
    int PatientsRegistered;                 // ���� �� �������������� ��������
};

Doctor::Doctor(char* n)
{
    strcpy(Name, n);
    PatientsRegistered = 0;
}

const char* Doctor::getName() const
{ 
    return Name;
}

void Doctor::registerPatient(const Patient& P)
{ 
    PatientsList[PatientsRegistered] = P;
    PatientsRegistered++;
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
    // ���������� �� �����
    Doctor d1("Petrov");
    // ��������� �� ���� �� ���������� �� ������
    int n; 
    do
    { 
        cout << "���� �� ����������: ";
        cin >> n;
    } while (n < 0 || n > PATIENTS);

    // ������������ �� ����������
    for(int i = 0; i < n; i++)
    { 
        // ���������� �� ����� �� ���� �� ���
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
    cout << "������ ���� ��������� ��� ������ " 
        << d1.average() << endl;
    // ��������� �� ����������, ��������� ������ �� 3 ���������
    if(n > 0) d1.printUpper(3);
    return 0;
}
