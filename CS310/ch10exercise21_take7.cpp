/* * * * * * * * * * * * * * * * * * * * * * * * * * */ 
/* CIS 310 - C++ Programming                         */
/* Ch10Exercise21.cpp                                */
/* Author: Leslie Brockman                           */
/* Date: 2025-11-01                                  */
/* Description:This program is Epic bank system 2.0. */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include <string>
#include <iomanip>
#include <termios.h> //for mac getch()
#include <unistd.h>  //THIS for STDIN_FILENO on Mac! cuss words
using namespace std;

// MAC getch() function definition - ADD THIS! (only in windows directly)
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}


// Base class - DECLARATIONS ONLY
class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    string accountType;
    double balance;
    double interestRate;
    double minimumBalance;
    double serviceCharge;
    static int nextCheckingAccountNumber;
    static int nextSavingsAccountNumber;

public:
    // Constructors
    BankAccount(string name, string type, double initialBalance, double rate, double minBalance, double charge);
    BankAccount();

    // Virtual function for polymorphism
    virtual void checkBalance();

    // Getters
    int getAccountNumber() const { return accountNumber; }
    string getName() const { return accountHolderName; }
    string getAccountType() const { return accountType; }
    double getBalance() const { return balance; }
    double getInterestRate() const { return interestRate; }
    double getMinimumBalance() const { return minimumBalance; }
    double getServiceCharge() const { return serviceCharge; }   

    // Method declarations ONLY
    void deposit(double amount);
    bool withdraw(double amount);
    void applyInterest();
    void displayAccountInfo();
    bool meetsMinimumBalance() const;
    void displayMinimumBalanceStatus() const;
};

// Initialize static members
int BankAccount::nextCheckingAccountNumber = 1001;
int BankAccount::nextSavingsAccountNumber = 2001;

// CheckingAccount class
class CheckingAccount : public BankAccount {
public:
    CheckingAccount(string name, double initialBalance, int accNum);
    void checkBalance() override;
    bool writeCheck(double amount, string payTo);
};

// SavingsAccount class  
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string name, double initialBalance, double interestRate, int accNum);//orginal 3
    void checkBalance() override;
};

// METHOD IMPLEMENTATIONS - OUTSIDE THE CLASSES
BankAccount::BankAccount(string name, string type, double initialBalance, double rate, double minBalance, double charge) {
    accountHolderName = name;
    accountType = type;
    balance = initialBalance;
    interestRate = rate;
    minimumBalance = minBalance;
    serviceCharge = charge;
    
    if (type == "checking") {
        accountNumber = nextCheckingAccountNumber++;
    } else {
        accountNumber = nextSavingsAccountNumber++;
    }
}

BankAccount::BankAccount() {
    accountNumber = 0;
    accountHolderName = "";
    accountType = "";
    balance = 0.0;
    interestRate = 0.0;
    minimumBalance = 0.0;
    serviceCharge = 0.0;
}

void BankAccount::checkBalance() {
    cout << "Account #" << accountNumber << " Balance: $" << fixed << setprecision(2) << balance << endl;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful! New balance: $" << fixed << setprecision(2) << balance << endl;
    } else {
        cout << "Invalid deposit amount!" << endl;
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawal successful! New balance: $" << fixed << setprecision(2) << balance << endl;
        return true;
    } else {
        cout << "Invalid withdrawal amount or insufficient funds!" << endl;
        return false;
    }
}

void BankAccount::applyInterest() {
    double interest = balance * interestRate;
    balance += interest;
    cout << "Interest applied! Interest earned: $" << fixed << setprecision(2) << interest << endl;
    cout << "New balance: $" << balance << endl;
}

void BankAccount::displayAccountInfo() {
    cout << fixed << setprecision(2);
    cout << "\n--- Account Information ---" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder: " << accountHolderName << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Interest Rate: " << (interestRate * 100) << "%" << endl;
    cout << "Minimum Balance: $" << minimumBalance << endl;
    cout << "Service Charge: $" << serviceCharge << endl;
    cout << "---------------------------" << endl;
}

bool BankAccount::meetsMinimumBalance() const {
    return balance >= minimumBalance;
}

void BankAccount::displayMinimumBalanceStatus() const {
    if (meetsMinimumBalance()) {
        cout << "Account meets minimum balance requirement." << endl;
    } else {
        cout << "WARNING: Account balance ($" << fixed << setprecision(2) 
             << balance << ") is below minimum ($" << minimumBalance << ")." << endl;
    }
}

CheckingAccount::CheckingAccount(string name, double initialBalance, int accNum) 
    : BankAccount(name, "checking", initialBalance, 0.0, 100.0, 25.0) {
    accountNumber = accNum;
}

void CheckingAccount::checkBalance() {
    cout << "CHECKING Account #" << accountNumber << " Balance: $" << fixed << setprecision(2) << balance << endl;
}

bool CheckingAccount::writeCheck(double amount, string payTo) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "\n========== CHECK WRITTEN ==========" << endl;
        cout << "Pay to: " << payTo << endl;
        cout << "Amount: $" << fixed << setprecision(2) << amount << endl;
        cout << "New balance: $" << balance << endl;
        cout << "===================================" << endl;
        return true;
    } else {
        cout << "Invalid check amount or insufficient funds!" << endl;
        return false;
    }
}


SavingsAccount::SavingsAccount(string name, double initialBalance, double interestRate, int accNum)
    : BankAccount(name, "saving", initialBalance, interestRate, 50.0, 25.0) {
    accountNumber = accNum;
}
void SavingsAccount::checkBalance() {
    cout << "SAVINGS Account #" << accountNumber << " Balance: $" << fixed << setprecision(2) << balance << endl;
}

int main() {
    BankAccount accounts[100];
    int accountCount = 0;
    const int MAX_ACCOUNTS = 100;
    int choice;

    cout << "================================================" << endl;
    cout << "  ++ WELCOME TO EPIC BANKING SYSTEM UPDATE 2.0++" << endl;
    cout << "================================================" << endl;

    do {
        cout << "\n---EPIC BANKING MENU UPDATED ---" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Display Account Info" << endl;
        cout << "3. Checking Account Options" << endl;
        cout << "4. Savings Account Options" << endl;
        cout << "5. Display All Accounts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        choice = getch() - '0'; // Convert char to int
        cout << choice << endl; // Echo the choice for user feedback

        switch (choice) {
            case 1: {
                if (accountCount >= MAX_ACCOUNTS) {
                    cout << "Maximum accounts reached! Had to add this for the bugs." << endl;
                    break;
                }

                string name, type;
                double initialBalance, rate;

                cout << "Enter account holder name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter account type (Enter C for checking or S for saving): ";
                cin >> type;

                cout << "Enter initial balance: $";
                cin >> initialBalance;

                cout << "Enter interest rate (as decimal, e.g., 0.05 for 5%): ";
                cin >> rate;

                if (type == "C" || type == "c") {
                    accounts[accountCount] = BankAccount(name, "checking", initialBalance, rate, 100.0, 25.0);
                    cout << "Checking account created successfully!" << endl;
                } else if (type == "S" || type == "s") {
                    accounts[accountCount] = BankAccount(name, "saving", initialBalance, rate, 50.0, 25.0);
                    cout << "Savings account created successfully!" << endl;
                } else {
                    cout << "Invalid account type! Creating checking account as default." << endl;
                    accounts[accountCount] = BankAccount(name, "checking", initialBalance, rate, 100.0, 25.0);
                }

                cout << "\n========== NEW ACCOUNT CREATED ==========" << endl;
                accounts[accountCount].displayAccountInfo();
                cout << "=========================================" << endl;

                accountCount++;

                cout << "\nPress any key to return to main menu...";
                getch();
                break;
            }

            case 2: {
                if (accountCount == 0) {
                    cout << "No accounts exist! Create an account first, or see your Epic Bank representative." << endl;
                    cout << "\nPress any key to return to main menu...";
                    getch();
                    break;
                }

                int accNum;
                cout << "Enter account number: ";
                cin >> accNum;

                bool found = false;
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
                        accounts[i].displayAccountInfo();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Account not found! Please see your Epic Bank representative." << endl;
                }

                cout << "\nPress any key to return to main menu...";
                 getch();
                break;
            }
            case 3: {
         // Checking Account Options
    if (accountCount == 0) {
        cout << "No accounts exist! Create an account first. Please contact your Epic bank representative." << endl;
        cout << "\nPress any key to return to main menu...";
        getch();
        break;
    }

    // FIRST SECURITY STEP: Get and verify checking account number
    int accNum;
    cout << "Enter checking account number for verification: ";
    cin >> accNum;
    
    bool found = false;
    int accountIndex = -1;
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].getAccountNumber() == accNum && accounts[i].getAccountType() == "checking") {
            found = true;
            accountIndex = i;
            break;
        }
    }
    
    if (!found) {
        cout << "Checking account not found! Access denied." << endl;
        cout << "Please contact your Epic Bank Representative for assistance." << endl;
        cout << "\nPress any key to return to main menu...";
        getch();
        break;
    }

    // ACCOUNT VERIFIED - Show sub-menu
    cout << "\nAccount verified! Welcome, " << accounts[accountIndex].getName() << "!" << endl;
    
    int typeChoice;
    cout << "\n--- Checking Account Options ---" << endl;
    cout << "1. Withdrawal" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Write a Check" << endl;
    cout << "4. Check Balance" << endl;
    cout << "Enter choice (1-4): ";
   typeChoice = getch() - '0';
   cout << typeChoice << endl; // Echo the choice for user feedback

    switch(typeChoice) {
        case 1: {
            // Withdrawal with minimum balance check
            double amount;
            cout << "Enter withdrawal amount: $";
            cin >> amount;
            
            if (accounts[accountIndex].withdraw(amount)) {
                // Display minimum balance status after withdrawal
                accounts[accountIndex].displayMinimumBalanceStatus();
                
                // Apply service charge if below minimum
                if (!accounts[accountIndex].meetsMinimumBalance()) {
                    cout << "\nSERVICE CHARGE APPLIED!" << endl;
                    cout << "Your account is below the $100 minimum balance." << endl;
                    cout << "A $25.00 service charge has been deducted." << endl;
                    accounts[accountIndex].withdraw(25.00);
                    cout << "Balance after service charge: $" << fixed << setprecision(2) 
                         << accounts[accountIndex].getBalance() << endl;
                }
            }
            break;
        }
        case 2: {
            // Deposit with minimum balance check
            double amount;
            cout << "Enter deposit amount: $";
            cin >> amount;
            accounts[accountIndex].deposit(amount);
            
            // Display minimum balance status after deposit
            accounts[accountIndex].displayMinimumBalanceStatus();
            break;
        }
        case 3: {
            // Write check with minimum balance check
            double amount;
            string payTo;
            cout << "Enter check amount: $";
            cin >> amount;
            cout << "Pay to: ";
            cin.ignore();
            getline(cin, payTo);
            
            CheckingAccount temp(accounts[accountIndex].getName(), accounts[accountIndex].getBalance(), accounts[accountIndex].getAccountNumber());
            if (temp.writeCheck(amount, payTo)) {
                // Update account balance
                accounts[accountIndex] = BankAccount(accounts[accountIndex].getName(), "checking", temp.getBalance(), 0.0, 100.0, 25.0);
                
                // Display minimum balance status after check
                accounts[accountIndex].displayMinimumBalanceStatus();
                
                // Apply service charge if below minimum
                if (!accounts[accountIndex].meetsMinimumBalance()) {
                    cout << "\n SERVICE CHARGE APPLIED!" << endl;
                    cout << "Your account is below the $100 minimum balance." << endl;
                    cout << "A $25.00 service charge has been deducted." << endl;
                    accounts[accountIndex].withdraw(25.00);
                    cout << "Balance after service charge: $" << fixed << setprecision(2) 
                         << accounts[accountIndex].getBalance() << endl;
                }
            }
            break;
        }
        case 4: {
            // Check balance with polymorphism
            CheckingAccount temp(accounts[accountIndex].getName(), accounts[accountIndex].getBalance(), accounts[accountIndex].getAccountNumber());
            temp.checkBalance();
            
            // Display minimum balance status
            accounts[accountIndex].displayMinimumBalanceStatus();
            break;
        }
        default:
            cout << "Invalid choice! Please enter a valid option (1-4)." << endl;
    }
    
    cout << "\nPress 0 to return to main menu...";
    choice = getch() - '0';
    break;
}

case 4: {
    // Savings Account Options
    if (accountCount == 0) {
        cout << "No accounts exist! Create an account first. Please contact your Epic bank representative." << endl;
        cout << "\nPress any key to return to main menu...";
        getch();
        break;
    }

    // FIRST SECURITY STEP: Get and verify savings account number
    int accNum;
    cout << "Enter savings account number for verification: ";
    cin >> accNum;
    
    bool found = false;
    int accountIndex = -1;
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].getAccountNumber() == accNum && accounts[i].getAccountType() == "saving") {
            found = true;
            accountIndex = i;
            break;
        }
    }
    
    if (!found) {
        cout << "Savings account not found! Access denied." << endl;
        cout << "Please contact your Epic Bank Representative for assistance." << endl;
        cout << "\nPress any key to return to main menu...";
        getch();
        break;
    }

    // ACCOUNT VERIFIED - Show sub-menu
    cout << "\nAccount verified! Welcome, " << accounts[accountIndex].getName() << "!" << endl;
    
    int typeChoice;
    cout << "\n--- Savings Account Options ---" << endl;
    cout << "1. Withdrawal" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Apply Interest" << endl;
    cout << "4. Check Balance" << endl;
    cout << "Enter choice (1-4): ";
    cin >> typeChoice;

    switch(typeChoice) {
        case 1: {
            // Withdrawal with minimum balance check
            double amount;
            cout << "Enter withdrawal amount: $";
            cin >> amount;
            
            if (accounts[accountIndex].withdraw(amount)) {
                // Display minimum balance status after withdrawal
                accounts[accountIndex].displayMinimumBalanceStatus();
                
                // Apply service charge if below minimum
                if (!accounts[accountIndex].meetsMinimumBalance()) {
                    cout << "\nSERVICE CHARGE APPLIED!" << endl;
                    cout << "Your account is below the $100 minimum balance." << endl;
                    cout << "A $25.00 service charge has been deducted." << endl;
                    accounts[accountIndex].withdraw(25.00);
                    cout << "Balance after service charge: $" << fixed << setprecision(2) 
                         << accounts[accountIndex].getBalance() << endl;
                }
            }
            break;
        }
        case 2: {
            // Deposit with minimum balance check
            double amount;
            cout << "Enter deposit amount: $";
            cin >> amount;
            accounts[accountIndex].deposit(amount);
            
            // Display minimum balance status after deposit
            accounts[accountIndex].displayMinimumBalanceStatus();
            break;
        }
        case 3: {
            // Apply interest
            accounts[accountIndex].applyInterest();
            break;
        }
        case 4: {
            // Check balance with polymorphism
            SavingsAccount temp(accounts[accountIndex].getName(), accounts[accountIndex].getBalance(), accounts[accountIndex].getInterestRate(), accounts[accountIndex].getAccountNumber());
            temp.checkBalance();
            
            // Display minimum balance status
            accounts[accountIndex].displayMinimumBalanceStatus();
            break;
        }
        default:
            cout << "Invalid choice! Please enter a valid option (1-4)." << endl;
    }
    
    cout << "\nPress 0 to return to main menu...";
    choice = getch() - '0';
    break;
}

case 5: {
    // Display all accounts
    cout << "\n--- All Bank Accounts ---" << endl;
    for (int i = 0; i < accountCount; i++) {
        accounts[i].displayAccountInfo();
        cout << "-------------------------" << endl;
    }
    cout << "\nPress any key to return to main menu...";
    getch();
    break;
}

case 6:
    cout << "Exiting Epic Banking System. Goodbye!" << endl;
    break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
//getch() function 
//Instant menu selection
//"Press any key to continue" - Just like real banking systems
//Mixed input strategy - Simple choices use getch(), complex data uses cin
