#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    int marks;
    Student() : name("Unknown"), rollNo(0), marks(0) {
        cout << "Default constructor called\n";
    }
    Student(const string &n, int r, int m) : name(n), rollNo(r), marks(m) {
        cout << "Parameterized constructor called\n";
    }
    Student(const Student &other) : name(other.name), rollNo(other.rollNo), marks(other.marks) {
        cout << "Copy constructor called\n";
    }
    ~Student() {
        cout << "Destructor called for " << name << "\n";
    }
    void display() const {
        cout << "Name: " << name << " Roll: " << rollNo << " Marks: " << marks << endl;
    }
};

int main() {
    Student s1;
    s1.display();
    Student s2("Diana", 21, 88);
    s2.display();
    Student s3 = s2; // copy
    s3.display();
    return 0;
}
