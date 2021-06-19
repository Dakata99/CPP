#include <iostream.h>

class Stack
{
public:
    // ��������� �� ������� � ����
    // ���������� ����� ������, ��� � ���� �������
    // (�.�. ��� � ����� ��� �����) � ����, �
    // �������� ������
    virtual bool push(int) = 0;
    // ���������� �� ������� �� ����
    // ���������� ����� ������, ��� � ���� �������
    // (�.�. ��� � ����� ��� ��������) � ����, �
    // �������� ������
    virtual bool pop(int&) = 0;
    // ���� �������� � ����
    virtual int size() = 0;
    virtual ~Stack()
    {}
};

class ArrayStack : public Stack
{
public:
    ArrayStack()
    {
        count = 0;
    }

    int size()
    {
        return count;
    }

    bool push(int x)
    { 
        // ��� �� �������� �����?
        if(!hasSpace())
            return false;
        getArray()[count] = x;
        count++;
        return true;
    }

    bool pop(int &x)
    { 
        if(isEmpty())
            return false;
        x = getArray()[count-1];
        count--;
        return true;
    }

protected:
    // ������� �������, ������� ������, � �����
    // �� ��������� ������
    virtual int* getArray() = 0;
    // ��������� ������ ���� ��� �������� �����
    // � ������, � ����� �� ��������� ������
    virtual bool hasSpace() = 0;
    // ��������� ������ ���� ���� � ������
    virtual bool isEmpty() = 0;
    // ���� �������� � ����
    int count;
};

class StaticArrayStack : public ArrayStack
{
public:
    StaticArrayStack() : ArrayStack()
    {}

private:
    int staticArray[10];

protected:
    bool hasSpace()
    { 
        return count < 9;
    }
    bool isEmpty()
    { 
        return count == 0;
    }
    int* getArray()
    { 
        return staticArray;
    }
};

class DynamicArrayStack : public ArrayStack
{ 
public:
    DynamicArrayStack() : ArrayStack()
    { 
        dynamicArray = new int[10];
        capacity = 10;
    }

    ~DynamicArrayStack()
    { 
        delete dynamicArray;
    }

private:
    // ����� ������ �� ������
    // ����� �� ���������� ������ � ��-�����
    // ��� ����� �� ������� �� ������
    int capacity;
    int *dynamicArray;

    // ������� ������� �� ������ � ����� ������ ��� �����
    bool enlarge()
    { 
        int* newArray = new int[capacity*2];
        // ��� �� �����?
        if(newArray == NULL)
            return false;
        // �������� �� ������ ����� � �����
        for(int i = 0; i < capacity; i++)
            newArray[i] = dynamicArray[i];
        // ��������� �� dynamicArray � ��������� �� ������ �����
        int *save = dynamicArray;
        dynamicArray = newArray;
        capacity *= 2;
        delete save;
        return true;
    }

protected:
    bool hasSpace()
    { 
        return count < capacity || enlarge();
    }

    bool isEmpty()
    {
        return count == 0;
    }

    int* getArray()
    {
        return dynamicArray;
    }
};

int main()
{ 
    StaticArrayStack staticStack;
    int x;
    // ��������� �� �������� � ��������� ����
    cout << "�������� ���������� �� �����, -1 �� ���� ";
    do
    cin >> x;
    while(x != -1 && staticStack.push(x));
    // ��������� �� ���������� �� �����
    while(staticStack.pop(x))
        cout << x << endl;
    DynamicArrayStack dynamicStack;
    // ��������� �� �������� � ���������� ����
    cout << "�������� ���������� �� �����, -1 �� ���� ";
    do
    cin >> x;
    while(x != -1 && dynamicStack.push(x));
    // ��������� �� ���������� �� �����
    while(dynamicStack.pop(x))
        cout << x << endl;
    return 0;
}
