#include "Square.h"

Square::Square(double cx, double cy, double _side):Figure(cx, cy), side(_side){}

void Square::print()const
{
    std::cout << "Square with side " << side << std::endl;
    Figure::print();
}
double Square::perimeter()const 
{
    return 4*side;
}
double Square::area()const
{
    return side*side;
}