class Animal
{
    void eat()
    {
        System.out.println("eating...");
    }
}
class Dog extends Animal{
    void bark()
    {
        System.out.println("barking...");
    }
}
public class sing_inheri 
{
    public static void main(String[] args)
    {
        Dog obj = new Dog();
        obj.eat();
        obj.bark();
    }
}
