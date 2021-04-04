#include "Time.h"

//des/constructors
Time::Time(const size_t _hours, const size_t _mins, const size_t _secs)
    :hours(_hours), minutes(_mins), seconds(_secs){}
//operators

//getters
size_t Time::getHours()const
{
    return hours;
}
size_t Time::getMins()const
{
    return minutes;
}
size_t Time::getSecs()const
{
    return seconds;
}

//setters
void Time::setHours(const size_t _hours)
{
    hours = _hours;
}
void Time::setMins(const size_t _mins)
{
    minutes = _mins;
}
void Time::setSecs(const size_t _secs)
{
    seconds = _secs;
}

//funcs
void Time::printTime()const
{
    std::cout << "Time: ";
    if (hours < 10)
    {
        std::cout << "0" << hours << ":";
    }
    else
    {
        std::cout << hours << ":";
    }
    if (minutes < 10)
    {
        std::cout << "0" << minutes << ":";
    }
    else
    {
        std::cout << minutes << ":";
    }
    if (seconds < 10)
    {
        std::cout << "0" << seconds << std::endl;
    }
    else
    {
        std::cout << seconds << std::endl;
    }
}