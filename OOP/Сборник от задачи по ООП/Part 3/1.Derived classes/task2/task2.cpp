#include <iostream>

class base
{
private:
    int b1;
protected:
    int b2;
public:
    int b3();
} b;

class der1:public base
{
    private:
}