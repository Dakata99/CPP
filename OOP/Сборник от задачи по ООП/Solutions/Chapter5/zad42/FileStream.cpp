#include "FileStream.h"
#include <assert.h>

FileStream::FileStream(const char * fileName)
{
    assert(fileName);
    file.open(fileName, ios::binary|ios::nocreate);
    if(file.fail())
    {
        file.open(fileName, ios::binary|ios::trunc);
    }
}

FileStream::~FileStream()
{
    if(file.is_open()) file.close();
}    

// �� ������� �� ������ ��������� �� ������
// ���� �� ����� �� � ������� ��� ������� � ������
// ���������� (�������, ��� ����� ��� ������� ������ �� ������
// � �� �����). �������� �������, ����� ��������� ���� �� �����
// �� ��������� � �� �� ������ �� �������� � ����� ���������
// � ���� ������� (��� ����� ����� ���������� �� ������
// ���������� �� ��������� � �������).
int FileStream::GetPosition()
{
    return CanGetPosition() ? (int)file.tellg() : -1;
}

// ��������� �� ������ �� ������ �� ������.
// ���� � �������� ������� �� �����, ��� ���� ������
// �� ������ �� ����� �� ������� ���� ��������� �� ��������� flush.
int FileStream::GetLength()
{
    if(!CanGetLength())
        return -1;
    file.flush();
    int pos = file.tellg();
    file.seekg(0, ios::end);
    int len = file.tellg();
    file.seekg(pos, ios::beg);
    return len;
}

// ��� ������������� �� ���������� � ����� ���������,
// ��� ���� �� �� ���� ��� �� � ���������� ��������.
void FileStream::Seek(int position)
{
    if(CanSeek())
    {
        file.seekp(position, ios::beg);
        file.seekg(position, ios::beg);
    }
}

int FileStream::Read(unsigned char * buffer, int size)
{
    assert(buffer);
    return file.rdbuf()->sgetn((char *)buffer, size);
}

int FileStream::Write(const unsigned char * buffer, int size)
{
    assert(buffer);
    return file.rdbuf()->sputn((char *)buffer, size);
}

int FileStream::CanGetPosition()
{
    return file.tellg() >= 0;
}

int FileStream::CanGetLength()
{
    return CanGetPosition() && CanSeek();
}

int FileStream::CanSeek()
{
    file.seekg(0, ios::cur);
    if(file.fail())
    {
        file.clear(file.rdstate()&~ios::failbit);
        return 0;
    }
    return 1;
}

void FileStream::Flush()
{
    file.flush();
}
