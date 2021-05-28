#include <iostream.h>
#include <stdlib.h>

const int MAX_SIZE = 20;
class IntArray
{
public:
    IntArray(int);             // ����������� � ���������
    ~IntArray();               // ����������
    IntArray(const IntArray&); // ����������� �� �����������
    bool set(int, int);        // ��������� �������� �� �������
    bool get(int, int&);       // ������ �������� �� �������
    int linearSearch(int);     // ��������� ������� �������
    int binarySearch(int);     // ��������� ������� �������
    void selectionSort();      // ��������� ��������� �� ������
    // "����� ��������"
    void bubbleSort();         // ��������� ��������� �� ������
    // �� ���������

private:
    int* array;                // �������� ��� ������
    int num;                   // ���� �� ����������
    bool isValid(int);         // ��������� ����������� �� ������� �� ������
};

// �����������
// ����� ������� �� ������ � ������������� � 0.
IntArray::IntArray(int size)
{
    if(size > MAX_SIZE)
				{ 
		      cout << size << " ��������� " << MAX_SIZE
             << ".\n";
        exit(1);
				}
    if(size <= 0)
				{ 
		      cout << "���������� ����������!\n";
        exit(1);
					}
    array = new int[size];
    if(!array)
    {
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }
    num = size;
    for(int i = 0; i < size; i++)
        array[i] = 0;
}

// ����������
// ����������� �������, ����� �� ������.
IntArray::~IntArray()
{
    delete [] array;
}

// ����������� �� �����������
IntArray::IntArray(const IntArray& p)
{
    array = new int[p.num];
    if(!array)
    { 
        cout << "������ ��� �������� �� �����!\n";
        exit(1);
    }

    for(int i = 0; i < p.num; i++)
        array[i] = p.array[i];
    num = p.num;
}

// isValid ����� true, ��� ���������� � � �������
// ������ �� ������ � false - � �������� ������.
bool IntArray::isValid(int elem)
{ 
    return elem >= 0 && elem < num;
}

// set ��������� �������� �� ������ ������� �� ������.
// A�� ���������� �� ��������� �� ������� �������, set
// ����� true. � �������� ������ set ����� false.
bool IntArray::set(int elem, int value)
{ 
    if(isValid(elem))
    { 
        array[elem] = value;
        return true;
    }
    return false;
}

// get ������ ���������� �� ������ �� ����� ������ �������.
// ��� �������� � ��������, get ����� true,
// � �������� ������ ����� false.
bool IntArray::get(int elem, int& value)
{ 
    if(isValid(elem))
    { 
        value = array[elem];
        return true;
    }
    return false;
}

// linearSearch ��������� ������ �� ���������������� �������.
int IntArray::linearSearch(int x)
{ 
    int i = 0;
    while(i < num-1 && x != array[i])
        i++;
    if(x == array[i]) return i;
    else return num;
}

// binarySearch ��������� ������ �� ��������� �������
// � �������� ��� �������� ��� ��������� �����.
int IntArray::binarySearch(int x)
{ 
    int middle, left = 0, right = num-1;
    if(x < array[left]) return -1;
    if(x == array[left]) return 0;
    if(x > array[right]) return num;

    while(right-left > 1)
    { 
        middle = (left + right)/2;
        if(x <= array[middle]) right = middle; 
        else left = middle;
    }
    return right;
}

// selectionSort ��������� ������ �� �������
// �������� �� ��������� �� ��������� �����
void IntArray::selectionSort()
{
    int i, j, k;
    int min;
    for(i = 0; i < num-1; i++)
    {
        k = i; min = array[k];
        for(j = i+1; j < num; j++)
        {
            if(array[j] < min)
            {
                k = j;
                min = array[k];
            }
        }
        array[k] = array[i]; 
        array[i] = min;
    }
}

// bubbleSort ��������� ������ �� ���������
// �� ��������� �� ��������� �����
void IntArray::bubbleSort()
{
    int i, k, right = num-1;
    while(right > 0)
    { 
        k = 0; int swap;
        for(i = 0; i < right; i++)
        {
            if(array[i+1] < array[i])
            {
                swap = array[i];
                array[i] = array[i+1];
                array[i+1] = swap;
                k = i;
            }
        }
        right = k;
    }
}

int main()
{
    // ��������� �� ��������� �����
    int n;
    cout << "n= "; cin >> n;
    IntArray a(n);

    int val, i;
    for(i = 0; i < n; i++)
    {
        cout << "�������? "; cin >> val;
        if(!a.set(i, val))
            cout << "������ � ��������������� �� ������� �� ������!\n";
    }

    cout << endl;
    // ��������� �� ���������� �����
    for(i = 0; i < n; i++)
        if(a.get(i, val)) cout << val << " ";
        else cout << "������ ��� ���������� �� ������� �� ������!\n";
    cout << endl;

    // ���� �� �� ������� ������� ����� ��������� �� ������
    if(a.set(n, MAX_SIZE+1))
        cout << "��������� " <<  MAX_SIZE+1
             << " � �������� � ������ �������.\n";
    else
        cout << "������ ��� ��������� �� �������� " << MAX_SIZE+1 << ".\n";

    // ������� �� ������� � ������
    cout << "�������? "; cin >> val;
    if(a.get(a.linearSearch(val), val))
        cout << val << " �� ������� � ������.";
    else cout << val << " �� �� ������� � ������.";

    // ��������� �� ������ �� ������ �� ���������
    a.bubbleSort();
    cout << "�������� �����!\n";

    // ��������� �� ���������� ��������� �����
    for(i = 0; i < n; i++)
        if(a.get(i, val)) cout << val << " ";
        else cout << "������ ��� ���������� �� ������� �� ������!\n";
    cout << endl;

    // ������� �� ������� �� ����� ������� � ���������� �����
    cout << "�������? "; cin >> val;
    cout << "��������� �� " << val << " � ������ e: "
         << a.binarySearch(val) << endl;
    return 0;
}
