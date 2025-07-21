/*Create a base class named BankAccount with the following structure:
Create a base class named BankAccount with the following structure:
1: Private Members:
- int accountNumber
- double balance
2: Protected Member:
- string accountHolderName
3: Public Member Functions:
- void setAccountDetails(int accNo, double bal, string name)
void displayAccountDetails()
Now, create a derived class SavingsAccount that inherits publicly from BankAccount:
Private Member:
double interestRate
Public Member Functions:
void setInterestRate(double rate)
void displayInterestRate()
void showAccountHolderName() (access the protected member accountHolderName from base class)
In the main() function:
Create an object of SavingsAccount.
Set account details and interest rate.
Display account details, interest rate, and account holder’s name.
Try accessing accountNumber, balance, and accountHolderName directly from the object and comment the errors.






Account Number: 12345
Balance: 10000.50
Account Holder: ABC
Interest Rate: 4.5%
*/

#include <iostream>
using namespace std;


class BankAccount{
private:
    int Account_Number;
    double Balance;
protected:
    string Account_holder_Name;
public:
    string name;

    void setAccountDetails(int accNo, double bal, string name) {
        Account_Number = accNo;
        Balance = bal;
        Account_holder_Name = name;
    }

    int getAccountNumber() {
        return Account_Number;
    }

    double getBalance() {
        return Balance;
    }
};


class SavingsAccount : public BankAccount 
{
private:
    double interestRate;
public:
    void setInterestRate(double rate) 
    {
        interestRate = rate;
    }

    void displayInterestRate() {
        cout << "Interest Rate=" << interestRate << "%" << endl;
    }

    void showAccountHolderName() {
        cout << "Account Holder Name=" << Account_holder_Name << endl;
    }
};


int main()
{
    SavingsAccount sa;
    sa.setAccountDetails(1234567891, 50000, "Soham Kane");
    sa.setInterestRate(4.5);

    cout << "Account Number=" << sa.getAccountNumber() << endl;
    cout << "Balance=" << sa.getBalance() << endl;
    sa.showAccountHolderName();
    sa.displayInterestRate();
    printf("\n");
    return 0;
}
/*
This C++ program demonstrates the concept of **Inheritance**, **Access Specifiers**, and **Encapsulation** using a banking system example.

1. A base class `BankAccount` is created:
    - Private Data Members:
        - `accountNumber`: Stores the account number (private, so only accessible within the class).
        - `balance`: Stores the account balance (private).
    - Protected Data Member:
        - `accountHolderName`: Accessible in the base class and derived classes, but not outside the class.
    - Public Member Functions:
        - `setAccountDetails(int accNo, double bal, string name)`: Used to initialize account number, balance, and holder name.
        - `displayAccountDetails()`: Displays account number, balance, and account holder name.

2. A derived class `SavingsAccount` is created that **inherits publicly** from `BankAccount`:
    - Private Data Member:
        - `interestRate`: Stores the interest rate (private to SavingsAccount).
    - Public Member Functions:
        - `setInterestRate(double rate)`: Sets the interest rate for the savings account.
        - `displayInterestRate()`: Displays the current interest rate.
        - `showAccountHolderName()`: Accesses and displays the protected member `accountHolderName` from the base class.

3. In the `main()` function:
    - An object `s1` of `SavingsAccount` is created.
    - Account details are set using `setAccountDetails()`.
    - Interest rate is set using `setInterestRate()`.
    - The account details, interest rate, and account holder name (via a derived class function) are displayed.

4. Access Control Demonstration:
    - The last few lines (commented out) attempt to access private and protected members directly from `s1`:
        - `s1.accountNumber`, `s1.balance`: Cannot be accessed as they are **private** in `BankAccount`.
        - `s1.accountHolderName`: Cannot be accessed directly since it is **protected**, only accessible from inside the class or derived classes.
    - These lines are commented to prevent compiler errors, but demonstrate the importance of encapsulation and access specifiers.

5. Output of the Program:
    Account Details;
    Account Number: 12345  
    Balance: 10000.5  
    Account Holder: ABC  
    Interest Rate: 4.5%  
    Account Holder (from protected): ABC  

6. Key OOP Concepts Demonstrated:
    - **Encapsulation**: Using private and protected members to restrict access.
    - **Inheritance**: `SavingsAccount` inherits from `BankAccount`.
    - **Access Specifiers**: Shows the difference between private, protected, and public access.

This example is helpful for beginners to understand how object-oriented programming principles are applied in real-world scenarios.
*/