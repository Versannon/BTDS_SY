#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    int empId;
    string name;
    Employee(int id = 0, const string &n = "") : empId(id), name(n) {}
};

class Department {
public:
    string deptName;
    string location;
    Department(const string &d = "", const string &l = "") : deptName(d), location(l) {}
};

class Salary : public Employee, public Department {
public:
    double basic, hra, da;
    Salary(int id, const string &n, const string &dpt, const string &loc,
           double b, double h, double dd)
        : Employee(id, n), Department(dpt, loc), basic(b), hra(h), da(dd) {}
    double totalSalary() const { return basic + hra + da; }
    void display() const {
        cout << "EmpId: " << empId << " Name: " << name << " Dept: " << deptName
             << " Location: " << location << "\nBasic: " << basic << " HRA: " << hra
             << " DA: " << da << "\nTotal Salary: " << totalSalary() << endl;
    }
};

int main() {
    Salary s(501, "Charlie", "Engineering", "NY", 3000.0, 500.0, 200.0);
    s.display();
    return 0;
}
