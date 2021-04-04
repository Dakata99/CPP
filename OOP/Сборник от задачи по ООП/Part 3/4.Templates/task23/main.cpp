#include <iostream>
#include "TVec.cpp"
#include "TVector.cpp"

void func()
{
    TVec<double> u(4);

    for (size_t i = u.lowerBound(); i <= u.upperBound(); i++)
    {
        std::cout << ">";std::cin >> u[i];
    }
    for (size_t i = u.lowerBound(); i <= u.upperBound(); i++)
    {
        std::cout << "error\n";
        std::cout << u[i];
    }
    std::cout << std::endl;

    TVector<double> v(26, 35);
    for (size_t i = v.lowerBound(); i <= u.upperBound(); i++)
    {
        std::cout << ">";std::cin >> v[i];
    }
    for (size_t i = v.lowerBound(); i <= u.upperBound(); i++)
    {
        std::cout << v[i];
    }
    
}

int main()
{
    func();

    return 0;
}