#include <iostream.h>
#include <iomanip.h>

int main()
{
    //�)
    cout << "12345" << endl;
    cout.width(5); cout.fill('*');
    cout << 123 << endl;
    //�)
    cout << setw(10) << setfill('$') << 1000 ;
    cout << endl;
    //�)
    cout << setw(8) << setfill('$') 
         << setprecision(5) << 1024.987654;
    cout << endl;
    //�)
    cout << setiosflags(ios::showbase) << oct << 99
         << endl << hex << 99;
    cout << dec << endl;
    //�)
    cout << 10000 << endl
         << setiosflags(ios::showpos) << 10000;
    cout << endl;
    //�)
    cout << setfill('$') << setw(10) << setprecision(2)
         << setiosflags(ios::scientific) << 444.93738 << endl;
    return 0;
}
