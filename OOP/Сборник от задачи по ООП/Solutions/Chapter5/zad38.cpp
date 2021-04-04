#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <assert.h>     // assert
#include <stdlib.h>     // exit
#include <stdio.h>      // unlink, rename
#include <ctype.h>      // isspace

// ��� �� ��������� ����, � ����� �� ������� ������������
const char * EXPORT_FILE_NAME = "print.txt";

// ��� �� ��������� ����, ��������� ��� ��������� �� �����
const char * TEMP_FILE_NAME = "temp_student.dat";

// ���������� ������� �� ��� �� ����
const int MAX_PATH_SIZE = 256;

// ���������� ������� �� ��� �� �������
const int MAX_NAME_LENGTH = 32;

// ��������� � ���������� �������� �� ���������� �����
const int MIN_FN = 42900;
const int MAX_FN = 45150;

// ���������, ����������� ���������� �� �������
struct student_info
{
    int     fn;                     // ���������� �����
    char    name[MAX_NAME_LENGTH];  // ���
    float   grade;                  // ������ �����
};

// �������� ��� �������, ����� �� ������� �� ������
typedef int(*cmd_function)(fstream&, const char file_name[]);

// ��������� �� ���������� � ������ �������
int insert (fstream&, const char file_name[]);
int remove (fstream&, const char file_name[]);
int update (fstream&, const char file_name[]);
int print  (fstream&, const char file_name[]);
int save   (fstream&, const char file_name[]);
int search (fstream&, const char file_name[]);
int quit   (fstream&, const char file_name[]);

// ���������, �������� ������� �� ������
struct command
{
    char         key;        // ������, � ����� ������������  ������ �������
    const char * name;       // ��� �� �������, ��������� � ������
    cmd_function function;   // �������� ��� �������, ����� ��������� ���������
} commands[] = {             // ����� �� ������������ �������
    {'i', "��������",      insert},
    {'r', "���������",     remove},
    {'u', "�������������", update},
    {'p', "���������",     print},
    {'s', "���������",     save},
    {'f', "�������",       search},
    {'q', "����������",    quit},
    {0, NULL, NULL}};        // �������� � '�����' �����

    // ������� ����� ������� ������� //

// ������� �� �������� �� ���������� �����
int validate_fn(int fn)
{ 
    return fn >= MIN_FN && fn <= MAX_FN;
}

// ������� �� �������� �� �����
int validate_grade(float grade)
{ 
    return grade >= 2.0 && grade <= 6.0;
}

// ������� �� �������� �� ����� ���� ������ ��� ����
int get_count(fstream& file)
{ 
    long int offset;
    file.clear();
    if(!file.seekg(0, ios::end))    // ������������� � ���� �� �����
    { 
        return -1;
    }
    offset = file.tellg();          // ������� �� ��������� � ������� �� �����

    // ������������� ������ �� � ��������
    // ��������� assert ���������� ����������,
    // ��� ���������-�������� �� � ������.
    // ���� �� ������ ���� � Debug ����� �
    // ������ �������� �� ������� ������������
    // �� �������� ��������.
    assert(offset % sizeof(student_info) == 0);
    // ���������� ���� �� ��������
    return offset / sizeof(student_info);
}

// �������, ��������� ������� �� ���������� �������
int read_at(fstream& file, student_info& info, int pos)
{ 
    file.clear();
    file.seekg(pos * sizeof(info));
    return !file.read((char*)&info, sizeof(info));
}

// ����� ������� �� ����� � ��������� ���������� �����.
// ��� ����� � ����� ����� �� � �������, ����� �������
// �� ������ ������� � ��-����� �����.
// �������� ���������� �� ������� �������
long int seek_fn(fstream& file, int fn, long int count)
{ 
    student_info info;
    long int  start = 0,
              end   = count;
    long int  middle;
    while(start < end)
    { 
        middle = (start + end) / 2;
        if(read_at(file, info, middle))
        {  
            cout << "������� �������� �� �������!" << endl;
            return -1;
        }
        if(info.fn == fn)
        {
            return middle;
        }
        else if(info.fn > fn)
        {
            end = middle;
        }
        else
        {
            start = middle+1;
        }
    }
    return start;
}

// ��������� �������� �� ���������� ����� �� ���� ��
// ����� � ���� ������� ������. ���� �� �����������
// ����� �� �������� �� ��� �����.
// � ���� ���������� ���������� ����� ����� �� �����.
// � ��� ��-������ ����������� �� ����� �� �� ���������
// �������� �� ������� � ��-����� ������.
int shift_out(long int start, long int count, fstream& file)
{
    student_info info;
    file.clear();
    for(int pos = count-1; pos >= start; --pos)
    {
        file.seekg(pos*sizeof(info));
        file.read((char*)&info, sizeof(info));
        file.seekp((pos+1)*sizeof(info));
        file.write((char*)&info, sizeof(info));
        if(!file) return 1;
    }
    return 0;
}

// ������� ����� � ��������� ������ �� ����.
// ����������� ����� ���� ��������, ��� ���� ����� ������
// �� ���� ������, �� ������� � ��� � �������� ���� � ���� ����
// �������������� ���� �� ������� � ������� �� ���������
// unlink, � ���������� �� ��������� (���� ��������� rename).
// ���������� �������� ������� � ��� ����� ����� �� �������
// �� �������� �������, ���� �������� ���� �� �����. ��
// �������� � ���� � �������� ����� �� ��������� ���� �� ��
// �������� �� ����� �� ����� � ����� ���� �� ������ .tmp
// ������, ��������.
int remove_from_file(long int index, fstream& file,
                     const char file_name[MAX_NAME_LENGTH])
{
    // ������ ������ ��� ���� �� ������� � ���� �������� ����
    ofstream tmp(TEMP_FILE_NAME, ios::binary|ios::out|ios::trunc);
    if(!tmp)
    {
        cout << "������� ���������� �� �����!" << endl;
        return 1;
    }
    int pos = 0;
    student_info info;
    file.clear();
    file.seekg(0);

    while(file.read((char*)&info, sizeof(info)))
    { 
        if(pos != index)
        { 
            tmp.write((char*)&info, sizeof(info));
            if(!tmp)
            { 
                cout << "��������� ��������� �� ����� ��� ��������� ����";
                tmp.close();
                unlink(TEMP_FILE_NAME);
                return 1;
            }
        }
        ++pos;
    }

    file.clear();
    file.close();
    unlink(file_name);                  // ��������� �� ����������� ����
    tmp.close();
    rename(TEMP_FILE_NAME, file_name);  // � ������������ �� ��������� ����

    file.open(file_name, ios::in|ios::out|ios::binary);
    if(!file)
    { 
        cout << "��������� �������� �� �����."
             << file_name << endl;
        return 1;
    }
    return 0;
}

// �������, ����� �������� ������ ������ ������� � �������� �� �����
void ignore_spaces(istream& in)
{
    char ch;
    do
    { 
        ch = in.get();
    }while(in  && isspace(ch));
    in.putback(ch);
}

// �������� �� ����� �� ����� �� �������
ostream& operator<<(ostream& out, const student_info& info)
{ 
    out  << setw(MAX_NAME_LENGTH-1) << setiosflags(ios::left)
         << info.name << " |" << resetiosflags(ios::left)
         << setw(7) << info.fn << " |"
         << setw(6) << setprecision(2) 
         << info.grade << endl;
    return out;
}

// �������� �� ���� �� ����� �� �������
istream& operator>>(istream& in, student_info& info)
{ 
    ignore_spaces(in);
    in.getline(info.name, MAX_NAME_LENGTH, ' ');
    in >> info.fn;
    in >> info.grade;
    return in;
}

    // �������, ����������� ������������ ������� //

// ������� �� ���� �� ��������
// ��������� � ������ � �� ����� ��������, �������
// ���� �� �������� ��� ���������.
int quit(fstream& file, const char file_name[])
{ 
    file.close();
    return 1;
}

// ������� �� �������� �� ������� ��� ����
int insert(fstream& file, const char file_name[])
{ 
    // ������ �� ������������ �� ��� �������
    student_info info;
    cout << "�������� ���������� �� �������: " << endl;
    cout << "�������, ����� � ������: ";
    cin >> info;
    while(!cin || !validate_fn(info.fn) ||
          !validate_grade(info.grade))
    {
        cout << "������ �����! �������� ������������ ������!";
        cin.clear();
        cin >> info;
    }

    long int count = get_count(file);
    if(count < 0)
    { 
        cout << "������� ��� ������� �� ���� ������!" << endl;
        return count;
    }

    // �������� �� �������, �� ����� ������ �� �� ��������� ����������
    long int index = seek_fn(file, info.fn, count);
    if(index < 0)
    {
        cout << "������� ��� ������� �� �������!" << endl;
        return index;       // ���������� �������� �� ����������
    }

    if(index >= count)      // �������� � ���� �� �����
    { 
        file.seekp(0, ios::end);
        if(!file.write((char*)&info, sizeof(info)))
        { 
            cout << "��������� ��������� �� �������!" << endl;
            return 1;
        }
        return 0;
    }

    // ��� ���� �� �� ������ � ���� �� �����, �� �����
    // ��������� ����� ������ ������ �� �� ������
    student_info tmp_info = {0, };
    if(read_at(file, tmp_info, index))
    { 
        cout << "�� ���� �� ������� ����� �� ��������!" << endl;
        return 1;
    }

    // ��� ������� � ��� ����� �����, ������ ������������� �� �������
    if(tmp_info.fn == info.fn)
    { 
        cout << "������� � ����� ����� ���� ����������."
                " ������� �� ����� ���������." << endl;
    }
    else
    { 
        // ����������� �� �������� �� ���� �� �� �� �������� �����
        if(shift_out(index, count, file))
        {
            cout << "������������� � ���������!" << endl;
            return 1;
        }
    }

    // � � ����� ������ �� ���������� ������� �� 
    // �������� ������� �� ����� �����
    file.seekp(index*sizeof(info));
    if(!file.write((char*)&info, sizeof(info)))
    { 
        cout << "��������� ��������� �� �����!" << endl;
        return 1;
    }
    return 0;
}

// ������� �� ��������� �� ����� �� �������
int remove(fstream& file, const char file_name[])
{ 
    // ��������� �� ������ �� ��������, ����� �� �� �������
    int fn;
    cout << "����� �� ������� �� ���������: ";
    cin >> fn;
    if(!validate_fn(fn))
    { 
        cout << fn << " �� � ������� �����!" << endl;
        return 0;
    }

    // ������� �� ���������, �� ����� �� ������
    long int count = get_count(file);
    long int index = seek_fn(file, fn, count);
    if(index < 0)
    { 
        cout << "��������� ������� �� �������!" << endl;
        return index;
    }

    // ��� ������� � ��-����� �� ������
    if(index > count) 
    { 
        cout << "���� ������� � ���� �����!" << endl;
        return 0;
    }
    student_info info;
    if(read_at(file, info, index))
    { 
        cout << "�������� �� ������� � ���������!" << endl;
        return 1;
    }

    if(info.fn != fn)     // ��� ���� ����� �����
    { 
        cout << "���� ������� � ���� �����!" << endl;
        return 0;
    }

    // ��������� �� ������������ �� ���������
    cout << "��������� �� �������:" << endl;
    cout << info;
    cout << "<y/n>";
    char ans;
    cin >> ans;
    if(ans != 'y' && ans != 'Y')
    { 
        return 0;
    }

    // � ���������� �� ������ ���������
    if(remove_from_file(index, file, file_name))
    { 
        cout << "����������� �� ������� � ���������!" << endl;
        return 1;
    }
    return 0;
}

// ������� �� ������� �� ������ �������� � ��������� �����
int search(fstream& file, const char file_name[])
{ 
    float grade;
    cout << "������ �� �������: ";
    cin >> grade;
    if(!validate_grade(grade))
    { 
        cout << setprecision(2) << grade
             << " �� � ������� ������!" << endl;
        return 0;
    }
    file.clear();
    file.seekg(0);

    student_info info;
    bool found = false;
    while(file.read((char*)&info, sizeof(info)))
    { 
        if(info.grade == grade)
        { 
            cout << "���������� �� ��������: " << endl;
            cout << info;
            found = true;
        }
    }

    if(!found)
    { 
        cout << "�� � ������� ������� � ������ ������!" << endl;
    }
    return 0;
}

// ������� �� ��������� ������ �� ������� � ��������� �����
int update(fstream& file, const char file_name[])
{ 
    int fn;
    float new_grade;
    cout << "����� �� ������� �� �������: ";
    cin >> fn;
    if(!validate_fn(fn))
    { 
        cout << fn << " �� � ������� �����!" << endl;
        return 0;
    }
    long int count = get_count(file);
    long int index = seek_fn(file, fn, count);
    if(index < 0)
    { 
        cout << "��������� ������� �� �������!" << endl;
        return index;      // ���������� ������������ �� ����������
    }

    if(index > count)
    {
        cout << "���� ������� � ����� �����!" << endl;
        return 0;
    }

    student_info info;
    if(read_at(file, info, index))
    { 
        cout << "��������� ������ �� �����!" << endl;
        return 1;
    }

    if(info.fn != fn)
    { 
        cout << "���� ������� � ����� �����!" << endl;
        return 0;
    }

    // ��������� �� ������� ����� � ��������� �� ��������� �� ��� �����
    cout << "����� �� ��������: " << endl;
    cout << info;
    cout << "���� ������ : ";
    cin >> new_grade;
    if(!validate_grade(new_grade))
    { 
        cout << new_grade << " �� � ������� ������!" << endl;
        return 0;
    }

    // ��������� ������ ����� ����� �������
    info.grade = new_grade;
    file.seekp(index * sizeof(student_info));
    if(!file.write((char*)&info, sizeof(info)))
    { 
        cout << "��������� ����� �� �������!" << endl;
        return 1;
    }
    return 0;
}

// ������� �� ��������� �� ������ �� ������ ������
int print(fstream& file, const char file_name[])
{
    student_info info;
    file.clear();
    file.seekg(0);
    // ��������� �� �������� ���
    cout << setw(MAX_NAME_LENGTH) << setiosflags(ios::left)
         << "���" << '|' << resetiosflags(ios::left)
         << setw(8) << "�����" << '|'
         << setw(7) << "������" << endl;
    // � �� �������� ��� ����
    while(file.read((char*)&info, sizeof(info)))
        cout << info;
    return 0;
}

// ������� �� ��������� �� ������� � ������� ����
int save(fstream& file, const char file_name[])
{ 
    student_info info;
    ofstream output(EXPORT_FILE_NAME);
    if(!output)
    { 
        cout << "�� ���� �� �� ������ " << EXPORT_FILE_NAME;
        return 1;
    }
    // ��������� �� �������� ���
    output << setw(MAX_NAME_LENGTH) << setiosflags(ios::left)
           << "���" << '|' << resetiosflags(ios::left)
           << setw(8) << "�����" << '|'
           << setw(7) << "������" << endl;
    file.clear();
    file.seekg(0);

    // � �� �������
    while(file.read((char*)&info, sizeof(info)))
    { 
        if(!(output << info))
        { 
            cout << "������� � ������� ���� � ���������!" << endl;
            output.close();
            return 1;
        }
    }
    output.close();
    cout << "������������ � �������� � " << EXPORT_FILE_NAME << endl;
    return 0;
}

    // ������� �� ����������� �� ������ � ������� //

// �������, ��������� ������ �� ���������
void print_menu()
{ 
    cout << "\t\t ����\n";
    // �� ����� ����� �� ������ � �������
    for(int i = 0; commands[i].name; ++i)
    {
        cout << commands[i].key << " : "    // ��������� �� �������
             << commands[i].name << "\n";   // � ����� �� �������
    }
}

// �������, ������ ������ �� �����������
int read_command()
{ 
    char key = -1;
    // ���� ������
    cin >> key;
    if(!cin) return 1;
    // � ����� �� ��� ������� � ���
    for(int i = 0; commands[i].name; ++i)
    {
        if(commands[i].key == key)
            return i;
    }
    // ��� �� � �������� ������ �������
    cout << "��������� �������!" << endl;
    return -1;
}

// ����������� ������������ �� ������� �
// ��������� ������ � ������ �� �������.
// ������� �� ��������� ����� � ����� � �����.
int execute_command(int command, fstream& file,
                    const char file_name[])
{ 
    if(command >= 0 && commands[command].function)
    {
        return commands[command].function(file, file_name);
    }
    return 0;
}

// ������� �� ������� ��������������
void initialize(fstream& file, char file_name[MAX_PATH_SIZE])
{ 
    // ������ �� ����� �� ����� � �����
    cout << "��� �� ������� ����: ";
    cin.getline(file_name, MAX_PATH_SIZE);
    // � ��������
    file.open(file_name, ios::in|ios::out|ios::binary);
    if(!file)  // ��� ������ �� ���������� �� �������
    {
        file.open(file_name, ios::in|ios::out|ios::binary|ios::trunc);
    }
}

int main()
{ 
    char file_name[MAX_PATH_SIZE];
    fstream file;

    // �������������� �� ����������
    initialize(file, file_name);
    int command, result = 0;

    // ����������� � ����� �� �������
    do
    { 
        print_menu();
        command = read_command();
        if(command < 0) continue;
        result = execute_command(command, file, file_name);
    } while(result == 0);    // ������ ������������ �� � �������.

    // ������������ �� exit � ���� �� main �� ����������
    // �� ����������� �� ���������� ���������� ���������
    exit(EXIT_SUCCESS);
    return 0;
}
