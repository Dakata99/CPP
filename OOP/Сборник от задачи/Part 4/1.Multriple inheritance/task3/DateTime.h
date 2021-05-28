#pragma once
#include "Date.h"
#include "Time.h"

class DateTime:public Date, public Time
{
private:
    Date d;
    Time t;
    void simplify();
public:
    DateTime(const size_t = 1, const size_t = 1, const size_t = 1999, const size_t = 0, const size_t = 0, const size_t = 0);
    DateTime(const Date, const Time);

    void print();
};