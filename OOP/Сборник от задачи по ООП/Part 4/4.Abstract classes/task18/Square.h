#pragma once
#include "Figure.h"

class Square:public Figure
{
private:
    double side;
public:
    Square(double = 0, double = 0, double = 0);

    virtual void print()const;
    double perimeter()const override;
    double area()const override;
};