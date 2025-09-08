class Student {
String name;
int age;
void display() {
System.out.println(name + " is " + age + " years old.");
}
}

public class Student2 {
public static void main(String[] args) {
// Create first object
Student s1 = new Student();
s1.name="Amit";
s1.age=20;
s1.display();
// Create second object
Student s2 = new Student();
s2.name = "Priya";
s2.age = 22;
s2.display();
}
}