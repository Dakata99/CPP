#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>

struct Product
{ 
    char description[28];   // �������� �� �������
    int partNum;            // ����� �� �������
    double cost;            // ���� �� �������
};

//�)
void Create(ofstream&  f)
{ 
    Product Pr = {"", 0, 0.0};
    for(int i = 0; i <= 99; i++)
        f.write(reinterpret_cast<const char *>(&Pr), sizeof(Product));
    f.close();
}

//�) 
void Modify(ofstream& f)
{ 
    cout << "�������� ����� �� �������\n"
         << "(43000 to 43099, 0 �� ����) > ";
    Product Pr;
    cin >> Pr.partNum;
    while(Pr.partNum >= 43000 && Pr.partNum <= 43099)
    { 
        cin.ignore();    // �������� ����� �� ���� �� ���
        cout << "�������� �������� �� ������� > ";
        cin.getline(Pr.description, 28);
        cout << "�������� ���� �� ������� > ";
        cin >> Pr.cost;
        f.seekp((Pr.partNum - 43000)*sizeof(Product));
        f.write(reinterpret_cast<const char *>(&Pr), sizeof(Product));
        cout << "�������� ����� �� ������� > ";
        cin >> Pr.partNum;
    }
    f.close();
}

//�)
void OutLine(ostream &f, const Product &c)
{
    f << setiosflags(ios::left) << setw(35) << c.description
      << setw(10) << c.partNum << setw(10) << setprecision(2)
      << resetiosflags(ios::left)
      << setiosflags(ios::fixed|ios::showpoint)
      << c.cost << endl;
}

void WriteFile(fstream& f)
{
    cout << "���������:\n";
    cout << setiosflags(ios::left) << setw(35)
         << "�������� �� �������"
         << setw(10) << "�����"
         << resetiosflags(ios::left) << setw(10)
         << "����" << endl;
    Product Pr;
    f.read(reinterpret_cast<char*>(&Pr), sizeof(Product));
    while(f.good())
    {
        if(Pr.partNum != 0)
            OutLine(cout, Pr);
        f.read(reinterpret_cast<char *>(&Pr), sizeof(Product));
    }
    f.close();
}

//�)
void Update(fstream &f)
{
    cout << "�������������:\n";
    cout << "����� �� �������: (43000 - 43099) > ";
    int n;
    do
    cin >> n;
    while(n < 43000 || n > 43099);
    f.seekg((n - 43000)*sizeof(Product));
    Product Pr;
    f.read((char*)(&Pr), sizeof(Product));
    if(Pr.partNum != 0)
    {
        OutLine(cout, Pr);
        cout << "\n ���� ����: ";
        cin >> Pr.cost;
        OutLine(cout, Pr);
        f.seekp((n - 43000)*sizeof(Product));
        f.write((const char*)(&Pr), sizeof(Product));
    }
    else
    {
        cerr << "�� ����� # " << n << " ���� ����������." << endl;
    }
    f.close();
}

//�)
void Insert(fstream& f)
{
    cout << "���������:\n";
    cout << "����� �� �������: (43000 - 43099) > ";
    int n;
    do
    cin >> n;
    while(n < 43000 || n > 43099);
    f.seekg((n - 43000)*sizeof(Product));
    Product Pr;
    f.read((char*)(&Pr), sizeof(Product));
    if(Pr.partNum == 0)
    {
        Pr.partNum = n;
        cout << "�������� �������� �� ������� > ";
        cin.ignore();
        cin.getline(Pr.description, 28);
        cout << "�������� ���� �� ������� > ";
        cin >> Pr.cost;
        f.seekp((n - 43000)*sizeof(Product));
        f.write((const char *)(&Pr), sizeof(Product));
    }
    else
    {
        cerr << "������� � ����� # " << n << " ���� ������� ����������.\n";
    }
    f.close();
}

//�)
void Delete(fstream& f)
{
    cout << "���������:\n";
    cout << "����� �� �������: (43000 - 43099) > ";
    int n;
    do
    cin >> n;
    while(n < 43000 || n > 43099);
    f.seekg((n - 43000)*sizeof(Product));
    Product Pr;
    f.read((char*)(&Pr), sizeof(Product));
    if(Pr.partNum != 0 )
    {
        Product blank = {"", 0, 0.0};
        f.seekp((n - 43000)*sizeof(Product));
        f.write((const char*)(&blank), sizeof(Product));
        cout << "������� � ����� # " << n << " � �������." << endl;
    }
    else
    {
        cerr << "������� � ����� # " << n << "� ������." << endl;
    }
    f.close();
}

int getRequest()
{
    cout << "\n�������� ����� �� ������\n"
         << "1 - �� ��������� �� ����\n"
         << "2 - �� ������������� �� ����\n"
         << "3 - �� ��������� �� ���� ����������\n"
         << "4 - �� ��������� �� ����������\n"
         << "5 - �� ����\n";
    int req;
    do
    { 
        cout << "������ (1 - 5): ";
        cin >> req;
    }while(req < 1 || req > 5);
    return req;
}

int main()
{
    ofstream f1("Products.dat", ios::out);
    if(!f1)
    {
        cerr << "������ �� ���� �� ���� �������!\n";
        return 1;
    }
    Create(f1);
    f1.open("Products.dat", ios::ate|ios::nocreate);
    if(!f1)
    {
        cerr << "������ �� ���� �� ���� �������!\n";
        return 1;
    }
    Modify(f1);
    fstream f;
    int request;
    while((request = getRequest()) != 5)
    {
        f.open("Products.dat", ios::in|ios::out|ios::nocreate);
        if(!f)
        {
            cerr << "������ �� ���� �� ���� �������!\n";
            return 1;
        }
        switch(request)
        {
        case 1: WriteFile(f); break;
        case 2: Update(f); break;
        case 3: Insert(f); break; 
        case 4: Delete(f);
        }
        f.clear();
    }
    return 0;
}
