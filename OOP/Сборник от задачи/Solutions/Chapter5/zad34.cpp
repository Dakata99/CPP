#include <iostream.h>
#include <fstream.h>

const int MAX_PATH_SIZE = 100;

int main()
{
    char file_name1[MAX_PATH_SIZE];

    cout << "��� �� ������ ����: ";
    cin.getline(file_name1, MAX_PATH_SIZE);
    ifstream in_file(file_name1);
    if(!in_file)
    {
        cerr << "�� ���� �� �� ������ " << file_name1 << '\n';
        return 1;
    }

    // ��������� �� ���������� �� ����� �� ��������
    // �� ������ ������������� �� ���������� ��
    double numb,
           sum = 0.0,
           average = 0.0;
    int count = 0;
    while(in_file >> numb)
    {
        sum += numb;
        count++;
    }

    if(count > 0)
        average = sum/count;
    // ���������� �� in_file �� ���������� ���������
    in_file.clear();                // �������� eof ����
    in_file.seekg(0, ios::beg);     // ������� get ��������� � �������� �� �����
    
    char file_name2[MAX_PATH_SIZE];
    cout << "��� �� ������� ����: ";
    cin.getline(file_name2, MAX_PATH_SIZE);
    ofstream out_file(file_name2);
    if(!out_file)
    {
        cerr << "�� ���� �� �� ������ " << file_name2 << '\n';
        in_file.close();
        return 1;
    }

    // ��������� �� ����, �������� ���������
    // �� ����� ����� �� ������� ���� ���
    // ������ ������������� �����
    while(in_file >> numb)
        out_file << numb - average << endl;

    in_file.close();
    out_file.close();
    return 0;
}
