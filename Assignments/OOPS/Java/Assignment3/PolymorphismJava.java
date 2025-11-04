import java.util.*;
class Shape {
    double getArea() { return 0; }
    void draw() { System.out.println("Drawing shape"); }
}
class Circle extends Shape {
    double r;
    Circle(double r) { this.r = r; }
    double getArea() { return Math.PI * r * r; }
    void draw() { System.out.println("Drawing circle area=" + getArea()); }
}
class Rectangle extends Shape {
    double l, b;
    Rectangle(double l, double b) { this.l = l; this.b = b; }
    double getArea() { return l * b; }
    void draw() { System.out.println("Drawing rectangle area=" + getArea()); }
}
public class PolymorphismJava {
    // Overloaded area methods
    static double area(double r) { return Math.PI * r * r; }
    static double area(double l, double b) { return l * b; }
    static double area(double base, double height, boolean tri) { return 0.5 * base * height; }

    public static void main(String[] args) {
        System.out.println("Overloaded: circle=" + area(2.0) + " rect=" + area(3.0,4.0));
        Shape s1 = new Circle(2.5);
        Shape s2 = new Rectangle(3.0, 4.0);
        s1.draw();
        s2.draw();
    }
}
