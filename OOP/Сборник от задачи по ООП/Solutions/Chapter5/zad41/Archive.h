#ifndef _ARCHIVE_HEADER_INCLUDED_
#define _ARCHIVE_HEADER_INCLUDED_

#include <iostream.h>
#include <fstream.h>

class Archive
{
public:
    Archive(const char* archiveName, bool deleteIfExist = true);
    ~Archive();
    bool AddFile(const char* fileName, const char* keyword = NULL);
    int GetTotalSize() const;
    bool ExtractAll(const char* directoryName, const char* keyword = NULL);
protected:
    void codeBuffer(char* buffer, int size,
                    const char* keyword, 
                    size_t keyLen, size_t& keyPosition) const;
    int writeName(const char* fileName);
    void actualizeSize(int fileSize, int startPosition);
    int extractFile(const char *directoryName, const char *keyword);
    char* getOutputFileName(const char *directoryName);

protected:
    // ���� �� ������
    fstream file;
    // ��� ������ �� ��������� � ������
    unsigned int totalSize;
    // ������ �� ������ �� ������/���������
    static const int bufferSize;
    // ������ � ���������� �� ����
    static const char pathSeparator;

private:
    // ��������� �� ����������
    Archive(const Archive&);
    void operator=(const Archive&);
};

#endif //_ARCHIVE_HEADER_INCLUDED_
