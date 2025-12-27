#include<iostream>
#include<string>
using namespace std;

class Employee{

    protected:
    int empID;
    string empName;

    public:
    void setEmployee(int id, string name)
    {
        empID = id;
        empName = name;
    }
    void displayEmployeeDetails()
    {

        cout << "CEO ID : " << empID << endl;
        cout << "CEO Name : " << empName << endl;
    }
}e;

class manager: public Employee{

    private:
    string department;
    float bonus;

    public:
    void setManagerDetails(string dept, float bon){
        department = dept;
        bonus = bon;
    }

    void getManagerDetails(){
        cout << "Manager Department : " << department << endl;
        cout << "Manager bonus : " << bonus << endl;
    }   

}m;

int main ()
{

    cout << "CEO Details" << endl;
    e.setEmployee(123456, "Soham");
    e.displayEmployeeDetails();
    cout << "Manager Details" << endl;
    m.setManagerDetails("ComputerScience", 3.14 );
    m.getManagerDetails();
    return 0;
}