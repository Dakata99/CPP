#include <iostream.h>
#include <stdlib.h>
#include <math.h>

// ��������� �� ���� Point
class Point
{
public:
    Point(double, double);                  // �����������
    void scale(double);                     // ����-������� �� ����������
    void translate(double, double);         // ����-������� �� ����������
    double distance(const Point&) const;    // �������� �� ���������� ����� ��� �����
    void print() const;                     // ��������� �� �����

private:
    double x, y;                            // ���������� �� �������
};

// �����������
Point::Point(double X, double Y)
{
    x = X;
    y = Y;
}

// ����-������� �� ����������
void Point::scale(double k)
{
    x = x * k;
    y = y * k;
}

// ����-������� �� ����������
void Point::translate(double h, double v)
{
    x = x + h;
    y = y + v;
}

// ����-������� �� �������� �� ���������� ����� ��� �����
double Point::distance(const Point& P) const
{
    double xdist = x - P.x;
    double ydist = y - P.y;
    return sqrt(xdist*xdist + ydist*ydist);
}

// ����-������� �� ��������� �� �����
void Point::print() const
{
    cout << "Point(" << x << ", " << y << ")\n";
}

// ��������� �� ���� Quadrilateral
class Quadrilateral
{
public:
    Quadrilateral(Point, Point, Point, Point);  // �����������
    void scale(double);                         // ����������
    void translate(double, double);             // ����������
    double perimeter() const;                   // �������� �� ���������� �� �������������
    double area() const;                        // �������� �� ������ �� �������������
    void print() const;                         // ��������� �� �������������

protected:
    Point p1, p2, p3, p4;                       // ������� �� �������������

private:
    // �������� �� ���� �� ����������
    double triangleArea(Point, Point, Point) const;
};

// �����������
Quadrilateral::Quadrilateral(Point pp1, Point pp2,
                             Point pp3, Point pp4)
                             : p1(pp1), p2(pp2), p3(pp3), p4(pp4)
{}

// ����-������� �� ����������
void Quadrilateral::scale(double k)
{
    p1.scale(k);
    p2.scale(k);
    p3.scale(k);
    p4.scale(k);
}

// ����-������� �� ����������
void Quadrilateral::translate(double h, double v)
{
    p1.translate(h, v);
    p2.translate(h, v);
    p3.translate(h, v);
    p4.translate(h, v);
}

// ����-������� �� �������� �� ���������� �� �������������
double Quadrilateral::perimeter() const
{
    return p1.distance(p2) + p2.distance(p3) +
           p3.distance(p4) + p4.distance(p1);
}

// ����-������� �� �������� �� ������ �� �������������
double Quadrilateral::area() const
{
    return triangleArea(p1, p2, p3) +
           triangleArea(p1, p3, p4);
}

// ����-������� �� �������� �� ������ �� ����������
double Quadrilateral::triangleArea(Point pp1, Point pp2, Point pp3) const
{
    double a = pp1.distance(pp2),
           b = pp1.distance(pp3),
           c = pp2.distance(pp3),
           pp = (a+b+c)/2;
    return sqrt(pp*(pp-a)*(pp-b)*(pp-c));
}

// ����-������� �� ��������� �� �������������
void Quadrilateral::print() const
{
    cout << "������������� � �������: \n";
    p1.print(); p2.print();
    p3.print(); p4.print();
}

// ��������� �� ���� Rectangle
class Rectangle : public Quadrilateral
{
public:
    Rectangle(Point, Point, Point, Point);  // �����������
    double perimeter() const;               // �������� �� ����������
    double area() const;                    // �������� �� ������
    double diagonal() const;                // �������� �� ���������
    void print() const;                     // ��������� �� ������������
    void print_diag() const;                // ��������� �� ��������� �� ������������
private:
    double diag;
};

// �����������
Rectangle::Rectangle(Point q1, Point q2, Point q3, Point q4) :
                     Quadrilateral(q1, q2, q3, q4)
{
    if (fabs(p1.distance(p3) - p2.distance(p4)) > 1.0e-14 ||
        fabs(p1.distance(p2) - p3.distance(p4)) > 1.0e-14 ||
								fabs(p1.distance(p4) - p2.distance(p3)) > 1.0e-14)
    {
        cout << "�� � ������������.\n";
        exit(1);
    }
    diag = p1.distance(p3);
}

// ����-������� �� �������� �� ���������� �� ������������
double Rectangle::perimeter() const
{
    double a = p1.distance(p2),
           b = p1.distance(p4);
    return 2 * (a + b);
}

// ����-������� �� �������� �� ������ �� ������������
double Rectangle::area() const
{
    double a = p1.distance(p2),
           b = p1.distance(p4);
    return a * b;
}

// ����-������� �� �������� �� ��������� �� ������������
double Rectangle::diagonal() const
{
    return diag;
}

// ����-������� �� ��������� �� ������������
void Rectangle::print() const
{
    cout << "������������ � �������: \n";
    p1.print(); p2.print();
    p3.print(); p4.print();
}

// ����-������� �� ��������� �� ��������� �� ������������
void Rectangle::print_diag() const
{
    cout << "��������: " << diag << endl;
}

// ��������� �� ���� Square
class Square : public Rectangle
{
public:
    Square(Point, Point, Point, Point); // �����������
    double perimeter() const;           // �������� �� ����������
    double area() const;                // �������� �� ������
    void print() const;                 // ��������� �� �������
};

// �����������
Square::Square(Point q1, Point q2, Point q3, Point q4) :
               Rectangle(q1, q2, q3, q4)
{
    if(fabs(p1.distance(p2) - p2.distance(p3)) > 1.0e-7)
    {
        cout << "�� � �������.\n";
        exit(1);
    }
}

// ����-������� �� �������� �� ���������� �� �������
double Square::perimeter() const
{
    return 4 * p1.distance(p2);
}

// ����-������� �� �������� �� ������ �� �������
double Square::area() const
{
    double a = p1.distance(p2);
    return a * a;
}

// ����-������� �� ��������� �� �������
void Square::print() const
{
    cout << "������� � �������: \n";
    p1.print(); p2.print();
    p3.print(); p4.print();
}

int main()
{
    // ���������� �� �����
    Point P1(0, 0), P2(3, 1), P3(3, 0),
          P4(0, 1), P5(1, 1), P6(0, 3),
          P7(3, 3);

    // ��������� �� �������������
    Quadrilateral q(P1, P3, P2, P5);
    // ��������� �� ��������������
    q.print();
    // �������� � ��������� �� ����������
    // � ������ �� ��������������
    cout << "���������: " << q.perimeter() << endl
         << "����: " << q.area() << endl;
    // ����������� �� ��������������
    q.translate(2, 5);
    // ��������� �� ������������ �������������
    q.print();
    // �������� � ��������� �� ����������
    // � ������ �� ������������ �������������
    cout << "���������: " << q.perimeter() << endl
         << "����: " << q.area() << endl;
    // ���������� �� ������������ �������������
    q.scale(3);
    // ��������� �� ����������� �������������
    q.print();
    // �������� � ��������� �� ����������
    // � ������ �� ����������� �������������
    cout << "���������: " << q.perimeter() << endl
         << "����: " << q.area() << endl;
    
    // ��������� �� ������������
    Rectangle r(P1, P3, P2, P4);
    // ��������� �� �������������
    r.print();
    // �������� � ��������� �� ����������
    // � ������ �� �������������
    cout << "���������: " << r.perimeter() << endl
         << "����: " << r.area() << endl;
    // �������� �� ��������� �� �������������
    r.diagonal();
    // ��������� �� ��������� �� �������������
    r.print_diag();
    // ����������� �� �������������
    r.translate(2, 5);
    // ��������� �� ������������ ������������
    r.print();
    // ���������� �� ������������ ������������
    r.scale(3);
    // ��������� �� ����������� ������������
    r.print();

    // ��������� �� �������
    Square s(P1, P3, P7, P6);
    // ��������� �� ��������
    s.print();
    // �������� � ��������� �� ����������
    // � ������ �� �������a
    cout << "���������: " << s.perimeter() << endl
         << "����: " << s.area() << endl;
    // �������� �� ��������� �� ��������
    s.diagonal();
    // ��������� �� ��������� �� ��������
    s.print_diag();
    // ����������� �� ��������
    s.translate(2, 5);
    // ��������� �� ������������ �������
    s.print();
    // ���������� �� ������������ �������
    s.scale(3);
    // ��������� �� ����������� �������
    s.print();
    return 0;
}
