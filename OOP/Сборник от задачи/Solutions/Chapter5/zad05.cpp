#include <iostream.h>
#include <fstream.h>

const int MAX_PATH_SIZE = 256;

int main()
{
    char file_name[MAX_PATH_SIZE];
    ifstream file;
    cout << "�������� ��� �� ����: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    file.open(file_name, ios::nocreate);
    if(file.fail())
    {
        cout << "������ " << file_name << " �� ����������." << endl;
    }
    else
    {
        cout << "������ " << file_name << " ����������." << endl;
    }
    file.close();
    return 0;
}
