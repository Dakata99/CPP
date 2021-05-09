#include <iostream.h>
#include <fstream.h>

int main()
{ 
    ifstream f("numbers.txt", ios::in);
    if(!f)
    { 
        cerr << "������ �� ���� �� �� ������! \n";
        return 1;
    }
    char ch;
    while(!f.eof())
    { 
        f.get(ch);
        if(!f.good() && !f.eof())
        { 
            cout << "I/O ������! ����������!\n";
            return 1;
        }
        cout << ch;
    }
    return 0;
}
