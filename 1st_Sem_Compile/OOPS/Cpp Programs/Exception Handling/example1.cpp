#include <iostream>
using namespace std;
int main()
{
    try
    {
        int age=15;
        if (age>=18)
        {
            cout << "Access Granted";
        }
        else
        {
            throw(age);
        }
    }
    catch(int Mynum)
    {
        cout << "Access Denied. Age is " << Mynum << "." << endl;
    }
    return 0;
}