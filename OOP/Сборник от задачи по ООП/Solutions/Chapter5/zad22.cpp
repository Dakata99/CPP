#include <iostream.h>
#include <fstream.h>

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cout << "������ ������ �� ��� ����: copy infile outfile\n";
        return 1;
    }
    ifstream InFile(argv[1], ios::in);
    if(!InFile)
    {
        cout << argv[1] << " �� ���� �� �� ������!\n";
        return 1;
    }
    ofstream OutFile(argv[2], ios::out);
    if(!OutFile)
        cout << argv[2] << " �� ���� �� �� ������!\n";
    char ch;
    while(InFile.get(ch))
        OutFile.put(ch);
    InFile.close();
    OutFile.close();
    return 0;
}
