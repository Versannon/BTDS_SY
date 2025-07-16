/*Assigment 1:
1: Create a class Student with the following members:
 - private : int rollNo
 - protected: string grade
 - public : string name
2: Write public methods to:
 - Set values for all attributes.
 - Display al the student details.
3: Create a derived class 'Result' that inherits 'Student' and adds a method to display only the grade.
4: In 'main()', demonstrate access to:
 - public data members directly.
 - private and protected members through 'methods'.*/
#include <iostream>
using namespace std;

class Student 
{
private:
    int rollNo;
protected:
    string grade;
public:
    string name;
    void setVal(int r, string g, string n)
    {
        rollNo = r;
        grade = g;
        name = n;
    }
    void dispdetails(
        {
            cout << "Rl. NO: " << 
        }
    )
}