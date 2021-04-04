#include <iostream.h>
#include <fstream.h>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// ��������� ��� �������� ��� �� ����� �� 3 ���� �����
void sort3(int nums[])
{
    if(nums[1] < nums[0])
        swap(nums[0], nums[1]);
    if(nums[2] < nums[1])
    { 
        swap(nums[2], nums[1]);
        if(nums[1] < nums[0])
            swap(nums[0], nums[1]);
    }
}

int main()
{ 
    // �������� �� ������� ����
    const char* input_file_name = "numbers.txt";
    ifstream in_file(input_file_name);
    if(!in_file)
    {
        cerr << "�� ���� �� �� ������ ������ "
             << input_file_name << '\n';
        return 1;
    }

    // �������� �� �������� ����
    const char* output_file_name = "sorted.dat";
    ofstream out_file(output_file_name, ios::binary | ios::trunc);
    if(!out_file)
    {
        cerr << "�� ���� �� �� ������ ������ "
             << output_file_name << '\n';
        in_file.close();
        return 1;
    }

    int nums[3];
    // ������ �� ��� ����� �� ������� ����
    while(in_file >> nums[0] >> nums[1] >> nums[2])
    { 
        // ��������� �� �������
        sort3(nums);
        // ��������� ��� �����
        out_file.write((const char *)nums, 3*sizeof(nums[0]));
    }

    in_file.close();
    out_file.close();
    return 0;
}
