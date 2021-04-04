#include "Date.h"

//des/constructors
Date::Date(const size_t _day, const size_t _month, const size_t _year):day(_day), month(_month), year(_year){}
Date::Date(const Date& other):day(other.getDay()), month(other.getMonth()), year(other.getYear()){}

//operators
Date& Date::operator=(const Date& other)
{
    if (this != &other)
    {
        day = other.getDay();
        month = other.getMonth();
        year = other.getYear();
    }
    return *this;
}

//getters
size_t Date::getDay()const
{
    return day;
}
size_t Date::getMonth()const
{
    return month;
}
size_t Date::getYear()const
{
    return year;
}

//setters
void Date::setDay(const size_t _day)
{
    day = _day;
}
void Date::setMonth(const size_t _month)
{
    month = _month;
}
void Date::setYear(const size_t _year)
{
    year = _year;
}

//funcs
void Date::printDate()const
{
    std::cout << "Date: ";
    if (day < 10)
    {
        std::cout << "0" << day << ".";
    }
    else
    {
        std::cout << day << ".";
    }
    
    if (month < 10)
    {
        std::cout << "0" << month << ".";
    }
    else
    {
        std::cout << month << ".";
    }
    std::cout << year << std::endl;
}