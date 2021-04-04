#pragma once
#include "Figure.h"

class Rectangle:public Figure
{
private:
    double a, b;
public:
    Rectangle(double = 0, double = 0, double = 0, double = 0);
    virtual void print()const;
    double perimeter()const override;
    double area()const override;
};