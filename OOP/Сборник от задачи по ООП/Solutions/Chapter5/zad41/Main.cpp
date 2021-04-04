#include "Archive.h"
#include <iostream.h>  // cerr, cout, endl
#include <stdlib.h>    // exit
#include <memory.h>    // memcpy
#include <conio.h>     // getch

void printHelp(char* exeName)
{
    cout << "���������� �� ����������: \n " << exeName
         << " <option> <archive name> <files>\n\n"
            " ������� �����: \n"
            " -a  : ������ ������� ��� �����\n"
            " -n  : ������ ������� ��� ��� ����� \n"
            " -e  : ������� ������� � ������� ����������\n\n"
            " ������� :\n"
         << exeName << " -a test.arc file1.txt file2.txt file3.txt\n"
         << exeName << " -e test.arc dir1" << endl;
}

void error(const char* msg)
{
    cerr << "������ � ������! ";
    cerr << msg << endl;
}

char* readPassword()
{
    int max_size = 256;
    char* passwd = new char[max_size];
    int pos = 0;
    char ch;
    cout << "������: ";
    do
    {
        // ������� ���� ������, ��� �� �� ������� �� ������
        ch = getch();
        if(ch != '\n' && ch != '\r')
        {
            cout << '*';
            passwd[pos++] = ch;
        }

        // ��� � �������� ���������� �����, �� ������ ��� ��-�����
        if(pos == max_size-1)
        {
            max_size <<= 1;
            char* tmp = new char[max_size];
            memcpy(tmp, passwd, pos);
            delete[] passwd;
            passwd = tmp;
        }
    } while(ch != '\n' && ch != '\r');
    passwd[pos] = '\0';
    cout << endl;
    return passwd;
}

// ��������� ������� �������
void doCommand(char command, char* archiveName,
               int filesCount, char* files[])
{
    // ��������� �� � ���� ���������
    if(command != 'a' && command != 'e' && command != 'n')
    {
        error("��������� �����");
        exit(EXIT_FAILURE);
    }

    char* keyword;

    // �������� �� ������
    Archive arch(archiveName, command == 'n');
    // ��� �� �� ������� ��� ��������
    // �������, �� ������� ������
    keyword = filesCount ? readPassword() : NULL;
    if(command == 'a' || command == 'n')
    {
        for(int i = 0; i < filesCount; ++i)
        {
            cout << "�������� �� ����� " << files[i] << " ... ";
            if(arch.AddFile(files[i], keyword))
            {
                cout << "�����"<<endl;
            }
            else
            {
                cout << "������"<<endl;
            }
        }
    }
    else if(command == 'e')
    {
        if(filesCount)
        {
            cout << "��������� �� ������� � " << files[0] << " ... ";
            if(arch.ExtractAll(files[0], keyword))
            {
                cout << "�����" << endl;
            }
            else
            {
                cout << "������" << endl;
            }
        }
    }
    delete[] keyword;
    cout << "���������� � ���������!" << endl;
    cout << "������ �� ��������� � ������: " 
         << arch.GetTotalSize() << endl;
}

int main(int argc, char * argv[])
{
    if(argc < 3)       // ��������� ���� ���������
    {
        error("������ ����� ���������!");
        printHelp(argv[0]);
        exit(EXIT_FAILURE);
    }

    // ������� �������� ������ �� � �� ���� -X,
    // ������ X � ������ �� �������
    if(argv[1][0] != '-' || argv[1][2])
    {
        error("���������� ����������");
        printHelp(argv[0]);
        exit(EXIT_FAILURE);
    }

    doCommand(argv[1][1], argv[2], argc-3, argv+3);
    return 0;
}
