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
class Student{
private:
      int RollNo;

protected:
      string grade;

public:
      string name;
      
      void setRollNo(int roll)
      {
            RollNo=roll;
      }

      int getRollNo()
      {
            return RollNo;
      }

      void setgrade(string Grade)
      {
            grade=Grade;
      }

};

class Result : public Student{
public:
      void display()
      {
            cout <<"Grade of the Student="<<grade<<endl;
      }

};

int main()
{
      Result r;
      r.setRollNo(47);
      r.setgrade("A+");
      r.name="Soham";

      cout <<"\nRoll Number of the Student="<<r.getRollNo()<<endl;
      cout <<"Name of the Student="<<r.name<<endl;
      r.display();
      printf("\n");

        return 0;
}