#pragma once

class Time
{
private:
    size_t hours, minutes, seconds;
public:
    Time(const size_t = 0, const size_t = 0, const size_t = 0);
    
    size_t getHours()const;
    size_t getMins()const;
    size_t getSecs()const;

    void setHours(const size_t);
    void setMins(const size_t);
    void setSecs(const size_t);

    void printTime()const;
};