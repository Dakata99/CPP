#include <iostream.h>
#include <iomanip.h>

int main()
{
    //�) 
    cout << setprecision(3) << 1.92 << endl
         << 1.925 << endl << 1.9258 << endl;

    //�)
    cout << setw(10) << setiosflags(ios::right)
         << 12345 << endl;

    //�)
    cout << setw(15) << setiosflags(ios::left)
         << 40000 << endl;

    //�)
    cout << 250 << endl << setiosflags(ios::showpos)
         << 250 << endl;

    //�)
    cout << hex << setiosflags(ios::showbase)
         << 100 << endl;

    //�)
    cout << setw(9) << setfill('0')
         << 1.234 << endl;

    //�)
    for(int i = 1; i <= 5; i++)
        cout << setprecision(3+i) << 100.456273 << endl;

    return 0;
}
