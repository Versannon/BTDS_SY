#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter 1st number :";
    cin >> a;
    cout << "Enter 2nd number :";
    cin >> b;
    try
    {
        if (b == 0)
            throw b;
        cout << "Division is : " << a / b << endl;
    }
    catch (int)
    {
        cout << "Division by zero error" << endl;
    }
    return 0;
}