#include <iostream.h>
#include <stdlib.h>

const int MAXSIZE = 100; // ���������� ���� �������� �� ������

template <class T>
class Array
{
public:
    Array(int);
    ~Array();
    Array(const Array&);
    Array& operator=(const Array&);
    int get_size() const;
    T& operator[](int);

private:
    T* arr;                  // �������� ��� ������
    int size;                // ���� �� ����������
};

// �����������
template <class T>
Array<T>::Array(int n)
{
    if(n > MAXSIZE)
				{ 
				    cout << n << " ��������� " << MAXSIZE
             << ".\n";
        exit(1);
				}
    if(n <= 0)
				{ 
				    cout << "���������� ����������!\n";
        exit(1);
				}
    
		  size = n;
    arr = new T[n];
    if(!arr)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
   
}

// ����������
template <class T>
Array<T>::~Array()
{
    delete [] arr;
}

// ����������� �� �����������
template <class T>
Array<T>::Array(const Array<T>& p)
{ 
    size = p.size;
    arr = new T[size];
    if(!arr)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    for(int i = 0; i < size; i++)
        arr[i] = p.arr[i];
}

// �������� �� �����������
template <class T>
Array<T>& Array<T>::operator=(const Array<T>& p)
{ 
    if(this != &p)
    { 
        delete [] arr;
        size = p.size;
        arr = new T[size];
        if(!arr)
        { 
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        for(int i = 0; i < size; i++)
            arr[i] = p.arr[i];
    }
    return *this;
}

// �������� �� �����������
template <class T>
T& Array<T>::operator[](int sub)
{ 
    if(sub < 0 || sub >= size)
    { 
        cout << "������: �������� � ����� ���������!\n";
        exit(1);
    }
    return arr[sub];
}

// ������ ���� �� ���������� �� �����
template <class T>
int Array<T>::get_size() const
{ 
    return size;
}

int main()
{ 
    int n, i;
    cout << "n= "; cin >> n;
    
    // ��������� �� ��������� ����� �� ���� �����
    Array<int> a(n);
    for(i = 0; i < n; i++)
        a[i] = i+1;
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    for(i = 0; i < n; i++)
        a[i] = a[i]+5;
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    for(i = 0; i < n; i++)
        a[i]--;
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // ��������� �� ��������� ����� �� �������
    Array<char> c(n);
    for(i = 0; i < n; i++)
        c[i] = (char)(i+65);
    for(i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
    for(i = 0; i < n; i++)
        c[i] = (char)(c[i]+5);
    for(i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
    for(i = 0; i < n; i++)
        c[i]--;
    for(i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
    return 0;
}
