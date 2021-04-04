#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>

struct PersonalData
{ 
    bool read(istream &in)
    {
        // ������� ������
        // ���������� ����� (���� �����)
        // ��� (�� 199 �������)
        return (in >> fn) && in.getline(name,199);
    }
    int fn;                // ���������� �����
    char name[200];        // ���
};

struct ExamData
{
    bool read(istream &in)
    {
        // ������� ������
        // ���������� ����� (���� �����)
        // ������ (double)
        // ������� (�� 199 �������)
        return in >> fn && in >> mark &&
            in.getline(subject, 199);
    }

    int fn;                // ���������� �����
    double mark;           // ������
    char subject[200];     // �������
};

struct CombinedExamData
{
    // ���������� ������������� ����� ���� ������
    // ������� �� PersonalData � ExamData ������
    CombinedExamData(const PersonalData& _personalData,
        const ExamData& _examData)
    {
        personalData = _personalData;
        strcpy(personalData.name, _personalData.name);
        examData = _examData;
        strcpy(examData.subject, _examData.subject);
        count = 1;
    }

    PersonalData personalData;
    ExamData examData;
    // �� ����� ������ �� ����������� ������
    int count;
};

// ������� �������
// ��������� ������ dataArray �� ����� �� ������
// �� ����� ������� �� ����� �������. ��� ������
// ����� �� ��������, data.examData.mark ��
// ������ ��� �������������� ������ � ������� ��
// CombinedData �� ���������. � �������� ������ ��
// ������ ��� ������� ��� ������ � �������
void addEntry(CombinedExamData *dataArray[],
              const PersonalData& personalData,
              const ExamData& examData,
              int& count)
{
    int i = 0;
    // ������� �� ����� �� ������� ������� �� ������� �������
    while(i < count &&
         (strcmp(dataArray[i]->personalData.name, personalData.name) != 0 ||
          strcmp(dataArray[i]->examData.subject, examData.subject) != 0))
        i++;

    // ������� �� � ����� �����?
    if(i < count)
    {
        dataArray[i]->examData.mark += examData.mark;
        dataArray[i]->count++;
    }
    else
    {
        dataArray[count] = new CombinedExamData(personalData, examData);
        count++;
    }
}

void printResults(CombinedExamData *dataArray[], int count)
{
    cout << setiosflags(ios::left);
    for(int i = 0; i < count; i++)
        cout << setw(5) << dataArray[i]->personalData.fn 
             << setw(40) << dataArray[i]->examData.subject
             << setprecision(2) << setw(5) 
             << dataArray[i]->examData.mark / dataArray[i]->count
             << endl;
}

void readUnsorted()
{
    ifstream personalDataFile("personal.txt");
    // �����, � ����� �� ��������� ���������
    CombinedExamData *combined[500];
    // ���� ������� ���������
    int count = 0;
    PersonalData personalData;
    ExamData examData;
    while(personalDataFile && personalData.read(personalDataFile))
    {
        ifstream examDataFile("exams.txt");
        // ������ �� ����� �� ������ ������, ��������� �� ������� �������
        while(examDataFile && examData.read(examDataFile))
            if(examData.fn == personalData.fn)
                addEntry(combined, personalData, examData, count);
    }
    printResults(combined, count);
    for(int i = 0; i < count; i++)
        delete combined[i];
}

int main()
{
    readUnsorted();
    return 0;
}
