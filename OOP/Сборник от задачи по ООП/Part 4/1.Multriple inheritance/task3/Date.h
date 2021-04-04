#pragma once

class Date
{
private:
    size_t day, month, year;
public:
//des/constructors
    Date(const size_t = 1, const size_t = 1, const size_t = 1999);
    Date(const Date&);

//operators
    Date& operator=(const Date&);
//getters
    size_t getDay()const;
    size_t getMonth()const;
    size_t getYear()const;

//setters
    void setDay(const size_t);
    void setMonth(const size_t);
    void setYear(const size_t);

//funcs
    void printDate()const;
};