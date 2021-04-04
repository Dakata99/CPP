#include <iostream.h>
#include <stdlib.h>

// ��������� �� ������� �� ����� TVec
template <class T>
class TVec
{
public:
    // ��������� �����������
    TVec(int = 1);
    ~TVec();
    TVec(const TVec&);
    TVec& operator=(const TVec&);
    // �������� �� �����������
    T& operator[](int);
    // ������ �� ������� ������� �� �������
    int lowerbound() const;
    // ������ �� ������� ������� �� �������
    int upperbound() const;
private:
    T* vector;          // ������� �� ������
    int size;           // ���������� �� ������
protected:
    int lower;          // ����� ������� �� �������
    int upper;          // ����� ������� �� �������
};

template <class T>
TVec<T>::TVec(int s)
{
    if(s <= 0)
    { 
        cout << "��������� ���������� �� ������!\n";
        exit(1);
    }
    lower = 0;
    upper = s-1;
    size = s;
    vector = new T[s];
    if(!vector)
    { 
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
}

template <class T>
TVec<T>::~TVec()
{
    delete [] vector;
}

template <class T>
TVec<T>::TVec(const TVec<T>& v)
{
    size = v.size;
    vector = new T[size];
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

template <class T>
TVec<T>& TVec<T>::operator=(const TVec<T>& v)
{
    if(this != &v)
    {
        delete [] vector;
        size = v.size;
        vector = new T[size];
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

template <class T>
T& TVec<T>::operator[](int i)
{
    if(i < 0 || i > upper - lower)
    {
        cout << "���������� ������ " << i << endl;
        exit(1);
    }
    return vector[i];
}

template <class T>
int TVec<T>::lowerbound() const
{
    return lower;
}

template <class T>
int TVec<T>::upperbound() const
{
    return upper;
}

// ��������� �� ����� TVector
template <class T>
class TVector : public TVec<T>
{
public:
    TVector(int, int);      // �����������
    T& operator[](int);     // �������� �� �����������
};

// ����������� �� ������ � �������
// ����� � ����� ������� �� �������
template <class T>
TVector<T>::TVector(int low, int upp) : TVec<T>(upp - low + 1)
{ 
    lower = low;
    upper = upp;
}


// ������������� �� ��������� [] ��
// ����������� � ��������� �������
template <class T>
T& TVector<T>::operator[](int i)
{
    return TVec<T>::operator[](i - lower); //  TVec<T>::lower ��� ����� �����������
}

int main()
{
    // ���������� �� ������ � 4 ����������� ����������
    // � � ������� �� ������� �� 0 �� 3
    TVec<int> u(4);
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
    // � � ������� �� ������� �� -4 �� 5
    TVector<double> v(-4, 5);
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
