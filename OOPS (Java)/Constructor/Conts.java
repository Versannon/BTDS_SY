class Student
{
    String name;
    int age;

    Student()
    {
        name="Unknown";
        age=0;
    }

    void display()
    {
        System.out.println(name + " is " + age + " years old.");
    }
}
public class Conts {
    public static void main(String[]args)
    {
        Student s1=new Student();
        s1.display();
    }
}
