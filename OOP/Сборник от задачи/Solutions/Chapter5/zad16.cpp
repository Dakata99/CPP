#include <iostream.h>
#include <string.h>

// ���������� �� ������������ inptext
istream& inptext(istream& istr)
{
    cout << "\a" << "�������� �����: ";
    return istr;
}

int main()
{
    char str[80];
    do
    {
        cin >> inptext >> str;
    } while(strcmp(str, "star123"));
    return 0;
}
