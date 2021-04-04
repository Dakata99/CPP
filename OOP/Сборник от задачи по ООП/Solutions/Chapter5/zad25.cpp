#include <iostream.h>
#include <fstream.h>

const int MAX_PATH_SIZE = 256;

int main()
{
    char file_name[MAX_PATH_SIZE];
    // �������� �� ������� ����
    cout << "��� �� ������� ����: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    ifstream in_file(file_name);
    if(!in_file)
    {
        cerr << "�� ���� �� �� ������ ������ "
            << file_name << '\n';
        return 1;
    }
    // �������� �� �������� ����
    cout << "��� �� �������� ����: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    ofstream out_file(file_name);
    if(!out_file)
    {
        cerr << "�� ���� �� �� ������ ������ " 
            << file_name << '\n';
        in_file.close();
        return 1;
    }

    char ch;
    // ��������� � �������� ���� �� ����� ������
    // �� ������� ����, ����� �� � ��������
    while(in_file.get(ch))
        if(ch != ' ') out_file.put(ch);
    in_file.close();
    out_file.close();
    return 0;
}
