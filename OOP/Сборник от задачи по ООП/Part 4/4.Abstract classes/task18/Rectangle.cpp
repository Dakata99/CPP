#include "Rectangle.h"

Rectangle::Rectangle(double cx, double cy, double _a, double _b):Figure(cx, cy), a(_a), b(_b){}

void Rectangle::print()const
{
    std::cout << "Rectangle with sides " << a << " and " << b << std::endl;
    Figure::print();
}
double Rectangle::perimeter()const
{
    return 2*a + 2*b;
}
double Rectangle::area()const
{
    return a*b;
}