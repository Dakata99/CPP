#include <iostream.h>
#include <stdlib.h>

// ��������� �� ����� DoubleVec
class DoubleVec
{
public:
    // ��������� �����������
    DoubleVec(int = 1);
    ~DoubleVec();
    DoubleVec(const DoubleVec&);
    DoubleVec& operator=(const DoubleVec&);
    // ������������� �� ��������� �� ����������� []
    double& operator[](int);
    // ������ �� ������� ������� �� �������
    int lowerbound() const;
    // ������ �� ������� ������� �� �������
    int upperbound() const;

private:
    double* vector;         // ������� �� ������
    int size;               // ���������� �� ������
protected:
    int lower;              // ����� ������� �� �������
    int upper;              // ����� ������� �� �������
};

DoubleVec::DoubleVec(int s)
{
    if(s <= 0)
    {
        cout << "��������� ���������� �� ������!\n";
        exit(1);
    }
    lower = 0;
    upper = s-1;
    size = s;
    vector = new double[s];
    if(!vector)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
}

DoubleVec::~DoubleVec()
{
    delete [] vector;
}

DoubleVec::DoubleVec(const DoubleVec& v)
{
    size = v.size;
    vector = new double[size];
    if(!vector)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    for(int i = 0; i < size; i++)
        vector[i] = v.vector[i];
    lower = v.lower;
    upper = v.upper;
}

DoubleVec& DoubleVec::operator=(const DoubleVec& v)
{
    if(this != &v)
    {
        delete [] vector;
        size = v.size;
        vector = new double[size];
        if(!vector)
        {
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        for(int i = 0; i < size; i++)
            vector[i] = v.vector[i];
        lower = v.lower;
        upper = v.upper;
    }
    return *this;
}

double& DoubleVec::operator[](int i)
{
    if(i < 0 || i > upper - lower)
    {
        cout << "���������� ������ " << i << endl;
        exit(1);
    }
    return vector[i];
}

int DoubleVec::lowerbound() const
{
    return lower;
}

int DoubleVec::upperbound() const
{
    return upper;
}

// ��������� �� ����� DoubleVector
class DoubleVector : public DoubleVec
{
public:
    DoubleVector(int, int);     // �����������
    double& operator[](int);    // �������� �� �����������
};

// ����������� �� ������ � �������
// ����� � ����� ������� �� �������
DoubleVector::DoubleVector(int low, int upp)
    : DoubleVec(upp - low + 1)
{ 
    lower = low;
    upper = upp;
}


// ������������� �� ��������� [] ��
// ����������� � ��������� �������
double& DoubleVector::operator[](int i)
{
    return DoubleVec::operator[](i - lower);
}

int main()
{
    // ���������� �� ������ ������ � 4 ����������
    // � � ������� �� ������� �� 0 �� 3
    DoubleVec u(4);
    // ��������� �� ��������� �� ������������ �� ������� u
    int i;
    for(i = u.lowerbound(); i <= u.upperbound(); i++)
    {
        cout << "> "; cin >> u[i];
    }

    // ��������� �� ������� u
    for(i = u.lowerbound(); i <= u.upperbound(); i++)
        cout << u[i] << " ";
    cout << endl;

    // ���������� �� ������ ������ � 10 ����������
    // � � ������� �� ������� �� 26 �� 35
    DoubleVector v(26, 35);

    // ��������� �� ��������� �� ������������ �� ������� v
    for(i = v.lowerbound(); i <= v.upperbound(); i++)
    {
        cout << "> "; cin >> v[i];
    }

    // ��������� �� ������� v
    for(i = v.lowerbound(); i <= v.upperbound(); i++)
        cout << v[i] << " ";
    return 0;
}
