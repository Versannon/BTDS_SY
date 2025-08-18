#include <iostream>
using namespace std;

class Animal
{
    public:
    virtual void sound()
    {
        cout << "Animal make sound" << endl;
    }
};
class Dog : public Animal
{
    public:
    void sound() override
    {
        cout << "Dog barks" << endl;
    }
};
class Cat : public Animal
{
    public:
    void sound() override
    {
        cout << "Cat meows" << endl;
    }
};
int main()
{
    Animal *a;
    Dog d;
    Cat c;
    a = &d;
    a->sound();
    a = &c;
    a->sound();
    return 0;
}