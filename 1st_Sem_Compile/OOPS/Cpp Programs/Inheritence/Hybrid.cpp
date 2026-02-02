//Hybrid inheritance code
#include <iostream>
using namespace std;
class A
{
    public:
        void showA()
        {
            cout << "A\n";
        }
};
class B : public A
{
    public:
        void showB()
        {
            cout << "B\n";
        }
};
class C
{
    public:
        void showC()
        {
            cout << "C\n";
        }
};
class D : public B, public C
{
    public:
        void showD()
        {
            cout << "D\n";
        }
};
int main()
{
    D d;
    d.showA();
    d.showB();
    d.showC();
    d.showD(); 
    return 0;
}