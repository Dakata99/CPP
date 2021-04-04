#include "DateTime.h"

void DateTime::simplify()
{
    if (t.getSecs() >= 60)
    {
        t.setSecs(t.getSecs() - 60);
        t.setMins(t.getMins() + 1);
    }
    if (t.getMins() >= 60)
    {
        t.setMins(t.getMins() - 60);
        t.setHours(t.getHours() + 1);
    }
    if (t.getHours() >= 24)
    {
        t.setHours(t.getHours() - 24);
        d.setDay(d.getDay() + 1);
    }
    if (d.getDay() > 31)
    {
        d.setDay(1);
        d.setMonth(d.getMonth() + 1);
    }
    if (d.getMonth() > 12)
    {
        d.setMonth(1);
        d.setYear(d.getYear() + 1);
    }
}

DateTime::DateTime(const size_t _day, const size_t _month, const size_t _year, const size_t _hours, const size_t _mins, const size_t _secs)
    :d(_day, _month, _year), t(_hours, _mins, _secs){}

DateTime::DateTime(const Date date, const Time time):d(date), t(time){}

void DateTime::print()
{
    simplify();
    d.printDate();
    t.printTime();
}