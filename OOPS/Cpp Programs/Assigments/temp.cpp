// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class bankaccount{
private:
    int accnum;
    double balance;
protected:
    string name;
    
public:
    void setAccDetails(int a,double b,string n){
        accnum=a;
        balance=b;
        name=n;
    }
    
    void displayaccdetails(){
            cout <<"account no.: " << accnum << endl;
            cout <<"account balance: " << balance << endl;
            cout <<"account holder name: " << name << endl;
    }
    
};
class savingsacc : public bankaccount{
    private:
        double interestR;
    public:
        void setinterestR(double r){
        interestR=r;
        }
        void displayI(){
            cout <<"interest rate for account: " << interestR << endl;
        }
        void displayN(){
            cout <<"protected name: " << name << endl;
        }
};
int main() {
    savingsacc s;
    s.setAccDetails(4294967296,899.86,"kartik");
    s.setinterestR(2.7);
    s.displayaccdetails();
    s.displayI();
    return 0;
}
