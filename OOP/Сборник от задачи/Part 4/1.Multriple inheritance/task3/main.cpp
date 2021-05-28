#include <iostream>
#include "Date.cpp"
#include "Time.cpp"
#include "DateTime.cpp"

int main()
{
    DateTime d1(Date(3, 12, 1999), Time(23, 60, 60));
    d1.print();

    DateTime d2(21, 11, 8, 4, 35, 12);
    d2.print();

    return 0;
}