class Person {
    String name;
    int age;
    Person(String name, int age) { this.name = name; this.age = age; }
}
class Employee extends Person {
    int empId;
    double salary;
    Employee(String name, int age, int empId, double salary) {
        super(name, age);
        this.empId = empId;
        this.salary = salary;
    }
}
class Manager extends Employee {
    String department;
    Manager(String name, int age, int empId, double salary, String department) {
        super(name, age, empId, salary);
        this.department = department;
    }
    void display() {
        System.out.println("Name: " + name + " Age: " + age + " EmpId: " + empId
            + " Salary: " + salary + " Dept: " + department);
    }
}
public class InheritanceExample {
    public static void main(String[] args) {
        Manager m = new Manager("Frank", 35, 5001, 75000.0, "Sales");
        m.display();
    }
}
