#include <iostream.h>
#include <string.h>
#include <stdlib.h>

class String
{ 
public:
    // ����������� �� ������������
    String();
    // ����������� �� �����������
    String(const String&);
    // ����������� � ���� ���������
    String(const char*);
    // ����������
    ~String();
    // ����-������� �� ������ �� ������������
    int length() const;
    const char* getString() const;
    // ������������� �� ���������
    String& operator=(const String&);
    const char* operator=(const char*);
    bool operator==(const String&) const;
    bool operator==(const char*) const;
    bool operator!=(const String&) const;
    bool operator!=(const char*) const;
    bool operator>(const String&) const;
    bool operator>(const char*) const;
    bool operator<(const String&) const;
    bool operator<(const char*) const;
    bool operator>=(const String&) const;
    bool operator>=(const char*) const;
    bool operator<=(const String&) const;
    bool operator<=(const char*) const;
    friend bool operator==(const char*, const String&);
    friend bool operator!=(const char*, const String&);
    friend bool operator> (const char*, const String&);
    friend bool operator< (const char*, const String&);
    friend bool operator>=(const char*, const String&);
    friend bool operator<=(const char*, const String&);
    void print() const
    { 
        for(int i = 0; i < len; i++)
            cout << str[i];
    }

private:
    char* str;        // �������� ���
    int len;          // ������� �� �������� ���
};

// ����������� �� ������������
String::String()
{ 
    str = NULL;
    len = 0;
}

// ����������� �� �����������
String::String(const String& r)
{ 
    if(r.str)
    { 
        str = new char[r.len+1];
        if(!str)
        {
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        strcpy(str, r.str);
        len = r.len;
    }
    else
    {
        str = NULL;
        len = 0;
    }
}

// ���������������� �����������
String::String(const char* s)
{ 
    if(s)
    { 
        len = strlen(s);
        str = new char[len+1];
        if(!str)
        { 
            cout << "������ ��� �������� �� �����!\n";
            exit(1);
        }
        strcpy(str, s);
    }
    else
    {
        str = NULL;
        len = 0;
    }
}

// ����������
String::~String()
{ 
    if(len != 0) delete [] str;
}

// ������ �� ��������� �� ���
int String::length() const
{ 
    return len;
}

// ������ �� ���
const char* String::getString() const
{ 
    return str;
}

// ������������� �� ��������� �� �����������,
// ����� �� ����� �� ����� String ���������
// ����� �� ����� ����
String& String::operator=(const String& r)
{ 
    if(r.str)
    { 
        if(r.str != str)
        { 
            len = r.len;
            if(str) delete [] str;
            str = new char[len+1];
            if(!str)
            { 
                cout << "������ ��� �������� �� �����!\n";
                exit(1);
            }
            strcpy(str, r.str);
        }
    }
    else if(str)
    { 
        delete [] str;
        str = NULL;
        len = 0;
    }
    return *this;
}

// ������������� �� ��������� �� �����������, �����
// �� ����� �� ����� String ��������� �������� ���
const char* String::operator=(const char* r)
{ 
    if(r)
    { 
        if(r != str)
        { 
            if(str) delete [] str;
            len = strlen(r);
            str = new char[len+1];
            if(!str)
            { 
                cout << "������ ��� �������� �� �����!\n";
                exit(1);
            }
            strcpy(str, r);
        }
    }
    else 
    {
        if(str)
        { 
            delete [] str;
            str = NULL;
            len = 0;
        }
    }
    return str;
}

// ������������� �� ��������� ==, �����
// �������� �� == ������� ����� � ������ r
bool String::operator==(const String& r) const
{ 
    return !strcmp(str, r.getString());
}

// ������������� �� ��������� ==, �����
// �������� �� == ������� ����� � ���� r
bool String::operator==(const char* r) const
{ 
    return !strcmp(str, r);
}

// ������� �������, ����� ����������� ��������� ==
// �� ��������� �� == �� ��������� ��� s � ������ r
bool operator==(const char* s, const String& r)
{ 
    return !strcmp(s, r.getString());
}

// ������������� �� ��������� !=, �����
// �������� �� != ������� ����� � ������ r
bool String::operator!=(const String& r) const
{ 
    return strcmp(str, r.getString()) != 0;
}

// ������������� �� ��������� !=, �����
// �������� �� != ������� ����� � ���� r
bool String::operator!=(const char* r) const
{ 
    return strcmp(str, r) != 0;
}

// ������� �������, ����� ����������� ��������� !=
// �� ��������� �� != �� ��������� ��� s � ������ r
bool operator!=(const char* s, const String& r)
{ 
    return strcmp(s, r.getString()) != 0;
}

// ������������� �� ��������� >, ����� ���������
// ���� �������� ����� � > �� ������ r
bool String::operator>(const String& r) const
{ 
    return strcmp(str, r.getString()) > 0;
}

// ������������� �� ��������� >, ����� ���������
// ���� �������� ����� � > �� ���� r
bool String::operator>(const char* r) const
{
    return strcmp(str, r) > 0;
}

// ������� �������, ����� ����������� ��������� >,
// ���������� ���� ���������� ��� s � > �� ������ r
bool operator>(const char* s, const String& r)
{
    return strcmp(s, r.getString()) > 0;
}

// ������������� �� ��������� <, ����� ���������
// ���� �������� ����� � < �� ������ r
bool String::operator<(const String& r) const
{
    return strcmp(str, r.getString()) < 0;
}

// ������������� �� ��������� <, ����� ���������
// ���� �������� ����� � < �� ���� r
bool String::operator<(const char* r) const
{
    return strcmp(str, r) < 0;
}

// ������� �������, ����� ����������� ��������� <,
// ���������� ���� ���������� ��� s � < �� ������ r
bool operator<(const char* s, const String& r)
{
    return strcmp(s, r.getString()) < 0;
}

// ������������� �� ��������� >=, ����� ���������
// ���� �������� ����� � >= �� ������ r
bool String::operator>=(const String& r) const
{
    return strcmp(str, r.getString()) >= 0;
}

// ������������� �� ��������� >=, ����� ���������
// ���� �������� ����� � >= �� ���� r
bool String::operator>=(const char* r) const
{
    return strcmp(str, r) >= 0;
}

// ������� �������, ����� ����������� ��������� >=,
// ���������� ���� ���������� ��� s � >= �� ������ r
bool operator>=(const char* s, const String& r)
{
    return strcmp(s, r.getString()) >= 0;
}

// ������������� �� ��������� <=, ����� ���������
// ���� �������� ����� � <= �� ������ r
bool String::operator<=(const String& r) const
{
    return strcmp(str, r.getString()) <= 0;
}

// ������������� �� ��������� <=, ����� ���������
// ���� �������� ����� � <= �� ���� r
bool String::operator<=(const char* r) const
{
    return strcmp(str, r) <= 0;
}

// ������� �������, ����� ����������� ��������� <=,
// ���������� ���� ���������� ��� s � <= �� ������ r
bool operator<=(const char* s, const String& r)
{
    return strcmp(s, r.getString()) <= 0;
}

int main()
{
    // �������� "="
    String a("��������� "), b;
    b = a;
    b.print();
    b = "���� � ";
    b.print();
    char str1[] = "������!\n";
    b = str1;
    b.print();
    // �������� "=="
    String c("�����"), d("�����");
    if(c == d) cout << "������� ��������.\n";
    else cout << "������� �� ��������.\n";
    if(c == "�����") cout << "������� ��������.\n";
    else cout << "������� �� ��������.\n";
    if("�����" == d) cout << "������� ��������.\n";
    else cout << "������� �� ��������.\n";
    // �������� ">" 
    String e("�����"), f("����");
    if(e > f)
        cout << "����� ����� � ��-������ �� ����� ����.\n";
    else
        cout << "����� ����� �� � ��-������ �� ����� ����.\n";
    if(e > "����")
        cout << "����� ����� � ��-������ �� ����� ����.\n";
    else
        cout << "����� ����� �� � ��-������ �� ����� ����.\n";
    if("�����" > f)
        cout << "����� ����� � ��-������ �� ����� ����.\n";
    else
        cout << "����� ����� �� � ��-������ �� ����� ����.\n";
    // ���������� �� ������� ��������� �� ���������
    return 0;
}
