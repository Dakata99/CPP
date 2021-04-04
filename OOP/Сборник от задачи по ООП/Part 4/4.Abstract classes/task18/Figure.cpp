#include "Figure.h"

Figure::Figure(double cx, double cy):x(cx), y(cy){}

void Figure::print()const
{
    std::cout << "x: " << x << " y: " << y << std::endl;
}