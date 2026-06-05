//This program dmeonastrates base classes, child classes and inhertiance

//This program demonstrates base classes, child classes and inheritance

#include <iostream>
#include <iomanip>
using namespace std;

//Base Class: Account
class Account {
protected:  // Protected so child classes can access
    int accountNumber;
    double balance;

public:
    // Constructor
    Account(int accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }
    
    // Virtual function to check/display balance
    virtual void checkBalance() {
        cout << fixed << setprecision(2);
        cout << "Account #" << accountNumber << " Balance: $" << balance << endl;
    }
    
    // Getter functions
    int getAccountNumber() { return accountNumber; }
    double getBalance() { return balance; }
};// end of class--cuss words for semi colon

//Child Class 1: CheckingAccount
class CheckingAccount : public Account {

public:
    // Constructor
    CheckingAccount(int accNum, double bal) : Account(accNum, bal) {
    }

    // Override checkBalance function
    void checkBalance() override {
        cout << fixed << setprecision(2);
        cout << "CHECKING Account #" << accountNumber << " Balance: $" << balance << endl;
    }
}; // end of class--cuss words for semi colon

//Child Class 2: SavingsAccount  
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    // Constructor
    SavingsAccount(int accNum, double bal) : Account(accNum, bal) {
    }

    // Override checkBalance function--polymorphism
    void checkBalance() override {
        cout << fixed << setprecision(2);
        cout << "SAVINGS Account #" << accountNumber << " Balance: $" << balance << endl;
    }
    
};

int main() {
    cout << "=== SIMPLE ACCOUNT BALANCE ===" << endl;
    
    // Create accounts
    CheckingAccount checking(1001, 250.75);
    SavingsAccount savings(2001, 1500.50);
    
    cout << "\n--- Checking Balance ---" << endl
    checking.checkBalance();
    
    cout << "\n--- Savings Balance ---" << endl;
    savings.checkBalance();
    
    return 0
}











//Base Class: Account
//Account number
//Balance
//Basic constructor
//Virtual function to check/display balance

//Child Classes:
//CheckingAccount: Maybe add a simple feature like minimum balance
//SavingsAccount: Maybe add a simple feature like interest rate

//Create accounts
//Check balances
//Maybe one simple operation each
// 3 access levels of inheritance: private, protected, public
//private: only the class itself can access
//protected: the class and its children can access
//public: everyone can access
//gonna need iomanip for money display formatting
//setprecision(2) for 2 decimal places
//Polymorphism via virtual functions and overrides
//each account type displays balance info differently, and overrides help ignore the base class version and give that specific account type's version instead
