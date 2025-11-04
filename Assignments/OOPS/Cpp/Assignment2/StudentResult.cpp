#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
    Person(const string &n = "", int a = 0) : name(n), age(a) {}
};

class Student : public Person {
public:
    int rollNo;
    string course;
    Student(const string &n = "", int a = 0, int r = 0, const string &c = "")
        : Person(n, a), rollNo(r), course(c) {}
};

class Exam : public Student {
public:
    int marks1, marks2, marks3;
    Exam(const string &n, int a, int r, const string &c, int m1, int m2, int m3)
        : Student(n, a, r, c), marks1(m1), marks2(m2), marks3(m3) {}
    int total() const { return marks1 + marks2 + marks3; }
    double average() const { return total() / 3.0; }
    void display() const {
        cout << "Name: " << name << " Age: " << age << " Roll: " << rollNo
             << " Course: " << course << "\nMarks: " << marks1 << ", "
             << marks2 << ", " << marks3 << "\nTotal: " << total()
             << " Avg: " << average() << endl;
    }
};

int main() {
    Exam e("Bob", 20, 12, "CS", 78, 85, 90);
    e.display();
    return 0;
}
