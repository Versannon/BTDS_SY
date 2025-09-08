class Student
{
    String name;
    int age;

    Student()
    {
        name="Unknown";
        age=0;
    }

    Student(String n, int a)
    {
        name=n;
        age=a;
    }
    void display()
    {
        System.out.println(name + " is " + age + " years old.");
    }
}
public class Const_overloading 
{
    public static void main(String[] args)
    {
        Student s1=new Student();
        Student s2=new Student("Bob",22);
        s1.display();
        s2.display();
    }
}