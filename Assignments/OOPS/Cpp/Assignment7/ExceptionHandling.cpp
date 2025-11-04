#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

double safeDivide(const string &aStr, const string &bStr) {
    try {
        double a = stod(aStr); // may throw invalid_argument
        double b = stod(bStr);
        if (b == 0.0) throw runtime_error("Division by zero");
        return a / b;
    } catch (const invalid_argument &) {
        throw invalid_argument("Invalid numeric input");
    }
}

int main() {
    string num = "10";
    string den = "0";         // try "a" to simulate invalid input
    try {
        double result = safeDivide(num, den);
        cout << "Result: " << result << endl;
    } catch (const invalid_argument &e) {
        cout << "Input error: " << e.what() << endl;
    } catch (const runtime_error &e) {
        cout << "Runtime error: " << e.what() << endl;
    } catch (...) {
        cout << "Unknown error\n";
    }
    return 0;
}
