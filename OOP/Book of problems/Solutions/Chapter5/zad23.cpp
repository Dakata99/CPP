#include <iostream.h>
#include <fstream.h>

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        cout << "������ ������ �� ��� ����: append file1 file2 ... resfile\n";
    }
    else
    {
        ofstream OutFile(argv[argc-1], ios::out);
        if(!OutFile)
        {
            cout << argv[argc-1] << " �� ���� �� �� ������!\n";
            return 1;
        }
        for(int i = 1; i < argc-1; i++)
        {
            ifstream InFile(argv[i], ios::in);
            if(!InFile)
            {
                cout << argv[i] << " �� ���� �� �� ������!\n";
                return 1;
            }
            char ch;
            while(InFile.get(ch))
                OutFile.put(ch);
            InFile.close();
        }
    }
    return 0;
}
