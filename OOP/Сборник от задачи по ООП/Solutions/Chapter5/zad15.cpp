#include <iostream.h>
#include <iomanip.h>

// ���������� �� ������������ outp
ostream& outp(ostream& ostr)
{
    ostr << "��������������� ���� ����� ���������� "
         << "�� ��������� [1, 100]!\n";
    return ostr;
}

int main()
{
    cout << outp << endl;
    return 0;
}
