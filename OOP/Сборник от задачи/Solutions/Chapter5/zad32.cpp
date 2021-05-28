#include <iostream.h>
#include <fstream.h>

const int MAX_PATH_SIZE = 100;

int main()
{
    char file_name[MAX_PATH_SIZE];
    cout << "��� �� ������ ����: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    ifstream f(file_name);
    if(!f)
    {
        cerr << "�� ���� �� �� ������ " << file_name << '\n';
        return 1;
    }
    char ch;
    f.seekg(7, ios::beg);
    f.get(ch);
    cout << "������ 7-�� �� ��������: " << ch << endl;
    f.seekg(-7, ios::end);
    f.get(ch);
    cout << "������ 7-�� �� ����: " << ch << endl;
    f.seekg(3, ios::cur);
    f.get(ch);
    cout << "������ 3-�� �� �������� �������: " << ch << endl;
    f.close();
    return 0;
}
