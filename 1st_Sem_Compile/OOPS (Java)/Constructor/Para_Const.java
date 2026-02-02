class Student
{
    String name;
    int age;

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
public class Para_Const 
{
    public static void main(String[]args)
    {
        Student s1=new Student("Alice",21);
        Student s2=new Student("Bob",22);
        s1.display();
        s2.display();
    }
}
