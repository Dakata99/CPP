#include <iostream.h>
#include <math.h>

class Absolute
{ 
public:
    int ab(int);
    double ab(double);
};

int Absolute::ab(int x)
{
    return abs(x);
}

double Absolute::ab(double x)
{
    return fabs(x);
}

int main()
{ 
    Absolute num;
    cout << "����������� �������� �� �567 �: " << num.ab(-567)
         << endl << "����������� �������� �� �5.167 �: "
         << num.ab(-5.167) << endl;
    return 0;
}
