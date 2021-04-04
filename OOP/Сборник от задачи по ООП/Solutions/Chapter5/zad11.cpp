#include <iostream.h>
#include <iomanip.h>

// ������� �������, ����� ����������� ������, ����������
// ��������������� �����, � ����������� �� �����
unsigned int char_to_digit(char ch)
{
    if(ch >= '0' && ch <= '9')
        return ch - '0';
    if(ch >='a' && ch <= 'f')
        return 10 + ch - 'a';
    if(ch >='A' && ch <= 'F')
        return 10 + ch - 'A';
    return (unsigned int)(-1);
}

// �������, ��������� �� ����� ����� �����,
// �������� � ������� ������ �������
unsigned int get_number(istream& stream, unsigned int base)
{
    char ch;
    unsigned int digit = 0;
    unsigned int number = 0;
    while(digit < base)
    {
        number = number * base + digit;
        ch = stream.get();
        digit = char_to_digit(ch);
    }
    return number;
}

// �������, ����� ���������� �������� �������,
// � ����� � �������� ������� �� �������� ������� �� ����� ������ �����
// �������������� �� �������� �� ������ ���� ��� ������� ��� ������� �� ������.
// ��� ������� ������� � �����, �������� �� 0, �� � � ��������� �������,
// ��� ������� � 0x � � ���������������, � ��� ������� ���� � 0 � � ������� �������.
int detect_base(istream& stream)
{
    char ch = stream.get();
    if(ch == '0')
    {
        ch = stream.get();
        if(ch == 'x' || ch == 'X')
        {
            ch = stream.get();
            stream.putback(ch);
            if((ch >= '0'&&ch <= '9')||
                (ch >= 'a'&&ch <= 'f')||
                (ch >= 'A'&&ch <= 'F'))
                return 16;
            else return -1;
        }
        else
        {
            stream.putback(ch);
            // ��� ���������� ������ �� � ������� ����� �� ������, �� ������� � 0
            return 8;
        }
    }
    else
    {
        stream.putback(ch);
        if(ch >= '0' && ch <= '9')
            return 10;
        else
            return -1;
    }
}

// ������� ������ ����� � ����� � ������ �������, �������� �� ��������
void print_number(ostream& stream, unsigned int number, int base)
{
    if(base != 8)
    { 
        stream << setiosflags(ios::showbase) << oct 
               << number << endl;
    }
    if(base != 10)
    { 
        stream << dec << number << endl;
    }
    if(base != 16)
    { 
        stream << setiosflags(ios::showbase) << hex 
               << number << endl;
    }
    stream << dec;
}

int main()
{ 
    // ���������� � ����� ������ ������� � �����
    int base = detect_base(cin);
    if(base < 0)
    {
        cerr << "��������� �����!\n";
        return 1;
    }
    // ���� �����
    unsigned int number = get_number(cin, base);
    // ������� ������� � ���������� ������ ������
    print_number(cout, number, base);
    return 0;
}
