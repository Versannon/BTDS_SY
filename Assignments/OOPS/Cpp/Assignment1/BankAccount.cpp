#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;
public:
    void init(int accNo, const string &nm, double bal) {
        accountNumber = accNo;
        name = nm;
        balance = bal;
    }
    void deposit(double amt) {
        if (amt > 0) balance += amt;
    }
    bool withdraw(double amt) {
        const double MIN_BAL = 500.0;
        if (amt <= 0) return false;
        if (balance - amt < MIN_BAL) return false;
        balance -= amt;
        return true;
    }
    void display() const {
        cout << "Account No: " << accountNumber << "\nName: " << name
             << "\nBalance: " << balance << endl;
    }
};

int main() {
    BankAccount a;
    a.init(101, "Alice", 1000.0);
    a.deposit(200.0);
    bool ok = a.withdraw(600.0); // leaves 600 -> OK
    cout << "Withdraw successful: " << (ok ? "Yes" : "No") << endl;
    ok = a.withdraw(200.0); // would go below MIN_BAL -> fail
    cout << "Withdraw successful: " << (ok ? "Yes" : "No") << endl;
    a.display();
    return 0;
}
