#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>

const int MaxSide = 100;
int OverflowFlag = -99;                     // �������� ����������

class Matrix
{
public:
    Matrix(int);                             // �����������
    Matrix::Matrix(const Matrix&);           // ����������� �� �����������
    ~Matrix();                               // ����������
    Matrix& operator=(const Matrix&);        // �������� �� �����������
    void print() const;                      // ��������� �� �������
    int& operator()(int, int);               // ������ �� �������
private:
    int* array;                              // ����������� �� ���������
    int side;                                // ���������� �� ���������
};

Matrix::Matrix(int s)
{
    if(s > MaxSide)
    {
        cout << s << " ��������� "  << MaxSide << ".\n";
        exit(1);
    }

    if(s <= 0)
    { 
        cout << s << " � ���������� ����������\n";
        exit(1);
    }

    array = new int[s * s];
    side = s;
}

Matrix::Matrix(const Matrix& m)
{
    side = m.side;
    array = new int[side * side];
    for(int i = 0; i < side * side; i++)
        array[i] = m.array[i];
}

Matrix::~Matrix()
{
    delete [] array;
}

void Matrix::print() const
{
    Matrix m(side);
    m = *this; 
    for(int i = 0; i < side; i++)
    {
        for(int j = 0; j < side; j++)
            cout << setw(8) << m(i, j);
        cout << endl;
    }
}

Matrix& Matrix::operator=(const Matrix& m)
{ 
    if(this != &m)
    { 
        delete [] array;
        side = m.side;
        array = new int[side * side];
        for(int i = 0; i < side * side; i++)
            array[i] = m.array[i];
    }
    return *this;
}

int& Matrix::operator()(int i, int j)
{
    if(i < 0 || j < 0 || i >= side || j >= side)
    { 
        cout << " ����������� ���-������ " << i 
             << "-" << j << " � ����� ���������.\n";
        return OverflowFlag;
    }
    else
    {
        return array[i * side + j];
    }
}

int main()
{ 
    // ��������� �� ��������� ������� � ���������� 5
    Matrix m(5);
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            m(i, j) = i * j + 1;
    // ��������� �� ����� n �� ����������� ������� m
    Matrix n(5);
    n = m;
    // ��������� �� ��������� n
    n.print();
    return 0;
}
