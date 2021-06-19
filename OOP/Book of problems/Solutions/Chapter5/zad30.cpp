#include <iostream.h>
#include <fstream.h>
#include <math.h>

const int MAX_PATH_SIZE = 256;
const double eps = 1E-9;

// ������ ��������� ��������� �� ������ �����������
// ����� ���� �� ��������
int solve(double coef[], double solutions[])
{
    double D = coef[1]*coef[1] - 4*coef[0]*coef[2];
    if(D < 0 || fabs(coef[0]) < eps) return 0;
    D = sqrt(D);
    solutions[0] = (-coef[1]+D) / (2*coef[0]);
    solutions[1] = (-coef[1]-D) / (2*coef[0]);
    return D > 0 ? 2 : 1;
}

int main()
{
    char file_name[MAX_PATH_SIZE];
    cout << "��� �� ������ ����: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    ifstream in_file(file_name, ios::binary);
    if(!in_file)
    {
        cerr << "�� ���� �� �� ������ " << file_name << '\n';
        return 1;
    }
    cout << "��� �� ������� ����: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    ofstream out_file(file_name);
    if(!out_file)
    {
        cerr << "�� ���� �� �� ������ " << file_name << '\n';
        in_file.close();
        return 1;
    }

    double coef[3];
    double solutions[2];
    int sol_cnt;
    // ������ � �������� �� ����� �������������
    // �� ��������� ���������
    while(in_file.read((char*)coef, sizeof(coef)))
    {
        // �������� �� �����������
        sol_cnt = solve(coef, solutions);
        if(sol_cnt)      // ��� ������ ������
        {
            for(--sol_cnt; sol_cnt >= 0; --sol_cnt)
                out_file << solutions[sol_cnt] << ' ';
        }
        else
        {
            out_file << "���";
        }
        out_file << endl;
    }
    in_file.close();
    out_file.close();
    return 0;
}
