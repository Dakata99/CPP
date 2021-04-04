#include <iostream.h>
#include <fstream.h>

void checkstatus(ifstream& f)
{ 
    int stat = f.rdstate();
    if(stat & ios::eofbit)
        cout << "EOF � �������!\n";
    else if(stat & ios::failbit)
        cout << "I/O ������\n";
    else if(stat & ios::badbit)
        cout << "������� I/O ������";
}

int main()
{
    ifstream f("numbers.txt", ios::in);
    if(!f)
    {
        cerr << "������ �� ���� �� �� ������! \n";
        return 1;
    }
    char ch;
    while(f.get(ch))
    {
        cout << ch;
        checkstatus(f);    
    }
    checkstatus(f);
    return 0;
}
