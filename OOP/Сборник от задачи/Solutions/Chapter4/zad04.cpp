#include <iostream.h>
#include <string.h>

// ��������� �� ���� PersonalData
class PersonalData
{
public:
    // ��������� �����������
    PersonalData();
    PersonalData(const PersonalData&);
    PersonalData& operator=(const PersonalData&);
    ~PersonalData();
    // ��������� �� �����
    void read();
    // ��������� �� �����
    void print() const;

private:
    char *name;                       // ���
    int birthYear;                    // ������ �� �������
    void copy(const PersonalData&);
};

PersonalData::PersonalData() : name(NULL), birthYear(0)
{} 

PersonalData::PersonalData(const PersonalData& data) :
                           name(NULL)
{
    copy(data);
}

PersonalData& PersonalData::operator=(const PersonalData& data)
{
    if(this != &data)
        copy(data);
    return *this;
}

PersonalData::~PersonalData()
{
    if(name != NULL)
        delete name;
}

void PersonalData::read()
{
    char nameTmp[255];
    cout << "����� ���: ";
    cin >> nameTmp;
    if(name != NULL)
        delete name;
    name = new char[strlen(nameTmp)+1];
    strcpy(name, nameTmp);
    cout << "������ �� �������: ";
    cin >> birthYear;
}

void PersonalData::print() const
{
    cout << "����� ���: "
         << name << endl
         << "������ �� �������: "
         << birthYear << endl;
}

void PersonalData::copy(const PersonalData& data)
{
    if(name != NULL)
        delete name;
    name = NULL;
    if(data.name != NULL)
    {
        name = new char [strlen(data.name)+1];
        strcpy (name, data.name);
    }
    birthYear = data.birthYear;
}

// ��������� �� ���� Class
class Class
{
public:
    // ����������� �� ������������
    Class();
    // ��������� �� �����
    void read();
    // ��������� �� �����
    void print() const;

private:
    int year;                // ������
    int childrenCount;       // ���� �������
    int classId;             // ����� �� ���������
};

Class::Class() : year(0), childrenCount(0), classId(0)
{}

void Class::read()
{
    cout << "������: ";
    cin >> year;
    cout << "���� �������: ";
    cin >> childrenCount;
    cout << "���������: ";
    cin >> classId;
}

void Class::print() const
{
    cout << "������: " <<  year << endl
         << "���� �������:" << childrenCount << endl
         << "���������: " << classId << endl;
}

// ��������� �� ���� Car
class Car
{
public:
    // ��������� �����������
    Car();
    Car(const Car&);
    Car& operator=(const Car&);
    ~Car();
    // ��������� �� �����
    void read();
    // ��������� �� �����
    void print() const;

private:
    char *model;                    // �����
    char registration[10];          // �������������� �����
    void copy(const Car&);
};

Car::Car() : model(NULL)
{}

Car::Car(const Car& data) : model(NULL)
{
    copy (data);
}

Car& Car::operator=(const Car& data)
{
    if(this != &data)
        copy (data);
    return *this;
}

Car::~Car()
{
    if(model != NULL)
        delete model; 
}

void Car::read()
{
    char nameTmp[255];
    cout << "�����: ";
    cin >> nameTmp;
    if(model != NULL)
        delete model;
    model = new char[strlen(nameTmp)+1];
    strcpy(model, nameTmp);
    cout << "�������������� �����: ";
    cin >> registration;
}

void Car::print() const
{
    cout << "�����: " <<  model << endl
         << "�������������� �����: " << registration << endl;
}

void Car::copy(const Car& data)
{
    if(model != NULL)
        delete model;
    model = NULL;
    if(data.model != NULL)
    {
        model = new char[strlen(data.model)+1];
        strcpy(model, data.model);
    }
    strcpy(registration, data.registration);
}

class Teacher : public PersonalData, public Class
{
public:
    // ��������� �� �����
    void read();
    // ��������� �� �����
    void print() const;
};

void Teacher::read()
{
    PersonalData::read();
    Class::read();
}

void Teacher::print() const
{
    PersonalData::print();
    Class::print();
}

class CarOwner : public PersonalData, public Car
{
public:
    // ��������� �� �����
    void read();
    // ��������� �� �����
    void print() const;
};

void CarOwner::read()
{
    PersonalData::read();
    Car::read();
}

void CarOwner::print() const
{
    PersonalData::print(); 
    Car::print();
}

int main()
{
    Teacher t;
    CarOwner co;
    t.read();
    co.read();
    cout << "\n============\n";
    t.print();
    cout << "\n============\n";
    co.print();
    return 0;
}
