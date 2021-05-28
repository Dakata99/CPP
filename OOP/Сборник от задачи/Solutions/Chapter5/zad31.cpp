#include <iostream.h>
#include <fstream.h>

int main()
{
    const char* file_name = "Rab.dat";

    // �������� �� ���� �� ��������� � ����
    ofstream OutFile(file_name, ios::out);
    if(!OutFile)
    {
        cout << file_name << " �� ���� �� �� ������!\n";
        return 1;
    }

    // ��������� �� ���������� �� �����
    int a[10], b, i;
    for(i = 0; i < 10; i++)
    { 
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }

    // ��������� �� ���������� �� ������ ��� �����
    for(i = 0; i < 10; i++)
        OutFile.write((const char*)&a[i], sizeof(int));
    OutFile.close();

    // �������� �� ����� �� ������ �� ����
    ifstream InFile(file_name, ios::in);
    if(!InFile)
    { 
        cout << file_name << " �� ���� �� �� ������!\n";
        return 1;
    } 
    i = 0; double s = 0;

    // ��������� �� ���������� �� �����, ���������
    // � �������� �� ������ ������������� ��
    InFile.read((char*)&b, sizeof(int));
    while(InFile.good())        // ��� !Infile.eof()
    {
        cout << b << " "; i++;
        s += b;
        InFile.read((char*)&b, sizeof(int));
    }
    // ��������� �� ������ �������������
    // �� ���������� �� �����
    if(i)
    {
        cout << s/i << endl;
    }
    else
    {
        cout << "���� ����� ��� �����" << endl;
    }
    InFile.close();
    return 0;
}
