#include <iostream>
using namespace std;

class Person 
{
    protected:
    string name;
    public:
    void setName(string n)
    {
        name=n;
    }
};

class Student : public Person 
{
    public:
    void display()
    {
        cout << "Name: " << name << endl;
    }
};

int main()
{
    Student s;
    s.setName("Student1");
    s.display();
    return 0;
}