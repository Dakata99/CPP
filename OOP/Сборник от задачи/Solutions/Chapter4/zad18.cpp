#include <iostream.h>

const double PI = 3.14159265;

class Figure
{
public:
    Figure(double cx, double cy) : x(cx), y(cy)
    {};

    // ����� �� ��������� �� ������
    virtual void print() const
    {
        cout << "x: " << x << " y: " << y << endl;
    }

    // ����� �� �������� �� ��������� �� ������
    virtual double perimeter() const = 0;

    // ����� �� �������� �� ���� �� ������
    virtual double surface() const = 0;

protected:
    double x, y;   		// ���������� �� �����������
};

class Circle : public Figure
{
public:
    Circle(double cx, double cy, double r) :
      Figure(cx, cy),radius(r)
    {};

    virtual void print() const
    {
      cout << "������: " << radius << endl;
      Figure::print();
    }

    double perimeter() const
    { 
      return 2*PI*radius;
    }

    double surface() const
    {
      return PI*radius*radius;
    }

private:
    double radius;
};

class Square : public Figure
{ 
public:
    Square(double cx, double cy, double s) :
           Figure(cx, cy), side(s)
    {};

    virtual void print() const
    {	
      cout << "side: " << side << endl;
      Figure::print();
    }

    double perimeter() const
    { 
      return 4*side;
    }

    double surface() const
    { 
      return side*side;
    }

private:
    double side;
};

class Rectangle : public Figure
{ 
public:
    Rectangle(double cx, double cy, double a, double b) : 
              Figure(cx, cy), sideA(a), sideB(b)
    {};

    virtual void print() const
    {	
        cout << "side a: " << sideA << " side b: "
             << sideB << endl;
        Figure::print();
    }

    double perimeter() const
    { 
        return 2*(sideA + sideB);
    }

    double surface() const
    { 
        return sideA*sideB;
    }

private:
    double sideA, sideB;
};

int main()
{    
    Figure* figs[3];
    // ��������� �� ��� �������� ������
    figs[0] = new Circle(0, 0, 1);
    figs[1] = new Square(0, 0, 1);
    figs[2] = new Rectangle(0, 0, 1, 1);
    // �������� �� ������ �� ����������� � ������ ��
    double sumPerims   = 0,
           sumSurfaces = 0;
    for(int i = 0; i < 3; i++)
    { 
        sumPerims += figs[i]->perimeter();
        sumSurfaces += figs[i]->surface();
    }
    cout << "P: " << sumPerims
         << ", S: " << sumSurfaces << endl;
    return 0;
}
