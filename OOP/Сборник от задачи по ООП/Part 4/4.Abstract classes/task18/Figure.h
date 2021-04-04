#pragma once

class Figure
{
protected:
    double x, y;
public:
    Figure(double = 0, double = 0);
    
    virtual double area()const = 0;
    virtual double perimeter()const = 0;
    virtual void print()const;
};