#include <iostream.h>
#include <fstream.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "������ ������ �� ��� ����: type infile\n";
        return 1;
    }

    ifstream InFile(argv[1], ios::in);
    if(!InFile)
    { 
        cout << argv[1] << " �� ���� �� �� ������!\n";
        return 1;
    }
    char ch;
    while(!InFile.eof())
    { 
        InFile.get(ch);
        cout << ch;
    }
    InFile.close();
    return 0;
}
