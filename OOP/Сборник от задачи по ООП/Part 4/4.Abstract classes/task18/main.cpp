#include <iostream>
#include "Figure.cpp"
#include "Circle.cpp"
#include "Square.cpp"
#include "Rectangle.cpp"

int main()
{
    Figure* figs[3];
    figs[0] = new Circle(0, 0, 1);
    figs[1] = new Square(0, 0, 1);
    figs[2] = new Rectangle(0, 0, 1, 1);

    figs[0]->print();
    std::cout << "Perimeter: " << figs[0]->perimeter() << " and area " << figs[0]->area() << std::endl;
    
    figs[1]->print();
    std::cout << "Perimeter: " << figs[1]->perimeter() << " and area " << figs[1]->area() << std::endl;
    
    figs[2]->print();
    std::cout << "Perimeter: " << figs[2]->perimeter() << " and area " << figs[2]->area() << std::endl;



    
    return 0;
}