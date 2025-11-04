#include <iostream>
#include <cmath>
using namespace std;

// Overloaded functions
double area(double radius) { return M_PI * radius * radius; }
double area(double l, double b) { return l * b; }
double area(double base, double height, bool isTriangle) {
    return 0.5 * base * height;
}

// Runtime polymorphism
class Shape {
public:
    virtual double getArea() const { return 0.0; }
    virtual void displayArea() const { cout << "Shape area: " << getArea() << endl; }
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}
    double getArea() const override { return M_PI * r * r; }
    void displayArea() const override { cout << "Circle area: " << getArea() << endl; }
};
class Rectangle : public Shape {
    double l, b;
public:
    Rectangle(double L, double B) : l(L), b(B) {}
    double getArea() const override { return l * b; }
    void displayArea() const override { cout << "Rectangle area: " << getArea() << endl; }
};

int main() {
    cout << "Overloaded areas: circle(2)=" << area(2.0)
         << " rect(3,4)=" << area(3.0,4.0)
         << " tri(3,4)=" << area(3.0,4.0,true) << endl;

    Shape *s1 = new Circle(2.5);
    Shape *s2 = new Rectangle(3.0, 4.0);
    s1->displayArea();
    s2->displayArea();
    delete s1; delete s2;
    return 0;
}
