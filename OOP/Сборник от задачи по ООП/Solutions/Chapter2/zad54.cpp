#include <iostream.h>
#include <iomanip.h>

const int MAXSIZE = 5;  // ���� �� ����������� �� �����������

class Budget
{ public:
Budget();
double getFacultyBudget() const;
double getUniversityBudget() const;
void addBudget(double);
static void administration(double);

private:
    static double universityBudget;      // ������ �� �����������
    double facultyBudget;                // ������ �� ��������
};

// �������������� �� ���������� ����-����� �� �����
double Budget::universityBudget = 0;

// �����������
Budget::Budget()
{
    facultyBudget= 0;
}

// ������� �� ������, ������� ������� �� ��������
double Budget::getFacultyBudget() const
{ 
    return facultyBudget;
}

// ������� �� ������, ������� ������� �� �����������
double Budget::getUniversityBudget() const
{ 
    return universityBudget;
}

// �������� �� ������� �� ��������
// ��� ������� �� �����������
void Budget::addBudget(double bud)
{ 
    facultyBudget = bud;
    universityBudget += facultyBudget;
}

// �������� �� ������� �� ��������������� ���
// ������� �� ������������
void Budget::administration(double bud)
{ 
    universityBudget += bud;
}

int main()
{
    const int numFaculty = MAXSIZE;
    cout << "�������� ������� �� ���������������: ";
    double adminBudget;
    cin >> adminBudget;
    // �������� �� ������� �� ��������������� ���
    // ������� �� ������������
    Budget::administration(adminBudget);
    int i;
    // ��������� �� ��������� �� ����������� �
    // �������� ��� ������� �� ������������
    double budgetAmount;
    Budget fac[numFaculty];
    for(i = 0; i < numFaculty; i++)
    {
        cout << "�������� ������� �� " << i+1
            << "- � ��������: ";
        cin >> budgetAmount;
        fac[i].addBudget(budgetAmount);
    }
    cout << setiosflags(ios::fixed) << setprecision(2);
    // ��������� �� ������� �� ���������������
    cout << "\t ������ �� ���������������:\t ";
    cout << adminBudget << endl;
    // ��������� �� ������� �� ����� �������� �
    // �� ������������
    for(i = 0; i < numFaculty; i++)
    { 
        cout << "\t �������� " << (i+1) << ":\t ";
        cout << fac[i].getFacultyBudget() << endl;
    }
    cout << "\t ������ �� ������������:\t ";
    cout << fac[0].getUniversityBudget() << endl;
    return 0;
}
