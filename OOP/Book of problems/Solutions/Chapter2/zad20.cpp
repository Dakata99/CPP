#include <iostream.h>

const int MaxStack = 100;             // ���������� ���� �������� �� �����
const int FullStack = MaxStack;       // ���������, ���������� ����� ����
const int EmptyStack = -1;            // ���������, ���������� ������ ����
const char EmptyFlag = '\0';          // ������� ���� �� ������ ����

class Stack
{
private:
    char items[MaxStack];             // ������� �� �����
    int top;                          // �������� ��� ����� �� �����

public:
    // ����������� �� ������������,
    // �������� ������ ����
    Stack();
    // ����������� �� �����������
    Stack(const Stack&);
    // ����-�������, ����� ������� �������
    // c � ������� ����
    void push(char c);
    // ����-�������, ����� �������� ������� ��
    // ������� ����, ��� ���������� �� � ������
    char pop();
    // ����-�������, ����� ��������� ����
    // �������� ���� � ������
    bool empty() const;
    // ����-�������, ����� ��������� ����
    // �������� ���� � �����
    bool full() const;
    // ����-�������, ����� ������� ����������
    // �� ������� ����, ���� �� ���������
    void print();
};

Stack::Stack()
{
    top = EmptyStack;
}

Stack::Stack(const Stack& s)
{
    top = s.top;
    for(int i = 0; i <= top; i++)
        items[i] = s.items[i];
}

void Stack::push(char c)
{
    if(full())
    {
        cout << "������ � �����!\n";
        return;
    }
    items[++top] = c;
}

char Stack::pop()
{
    if(empty())
    {
        cout << "������ � ������!\n";
        return EmptyFlag;
    }
    return items[top--];
}

bool Stack::empty() const
{
    return top == EmptyStack;
}

bool Stack::full() const
{
    return top == FullStack - 1;
}

void Stack::print()
{
    for(int i = top; i >= 0; i--)
        cout << pop() << endl;
}

int main()
{
    // ��������� �� ������ ���� s
    Stack s;
    // ��������� �� ��������� �a�, �b� � �c� � s
    s.push('a');
    s.push('b');
    s.push('c');
    // ��������� �� ��� ���� t, ����� �� ����� s
    Stack t = s;
    // ��������� �� ���������� �� ����� s
    s.print();
    // ���������� �� ������� �� ����� t
    if(!t.empty())
        cout << t.pop() << endl;
    // ��������� �� ���������� �������� �� ����� t
    t.print();
    return 0;
}
