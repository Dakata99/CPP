#include "Circle.h"

Circle::Circle(double cx, double cy, double r):Figure(cx, cy), radius(r){}

void Circle::print()const
{
    std::cout << "Circle with radius " << radius << std::endl;
    Figure::print();
}
double Circle::perimeter()const 
{
    return 2*3.14*radius;
}
double Circle::area()const 
{
    return 3.14*radius*radius;
}