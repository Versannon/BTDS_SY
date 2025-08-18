#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized constructor
    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    // Operator overloading for +
    Complex operator+(const Complex& obj) {
        Complex result;
        result.real = real + obj.real;
        result.imag = imag + obj.imag;
        return result;
    }

    // Function to display the complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(10, 9), c2(7, 9), c3;
    c3 = c1 + c2;
    c3.display();
    return 0;
}
