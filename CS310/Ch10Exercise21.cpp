/* * * * * * * * * * * * * * * * * * * * * * * * * * */ 
/* CIS 310 - C++ Programming                         */
/* Ch10Exercise21.cpp                                */
/* Author: Leslie Brockman                           */
/* Date: 2025-11-01                                  */
/* Description: This program is Epic banking system. */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    static int nextAccountNumber; // Shared counter for auto-numbering--stores and adds 1
    
    int accountNumber;
    string accountHolderName;
    string accountType; // "checking" or "saving"
    double balance;
    double interestRate; // stored as decimal (0.05 = 5%)

public:
    // Constructor
    BankAccount(string name, string type, double initialBalance, double rate);

    // Default constructor for array initialization
    BankAccount() {
    accountNumber = 0;
    accountHolderName = "";
    accountType = "";
    balance = 0.0;
    interestRate = 0.0;
}
    
    // Banking operations
    void deposit(double amount);
    bool withdraw(double amount);   // returns false if insufficient funds--true otherwise
    void applyInterest();
    
    // Account management
    void displayAccountInfo();
    
    // Getters
    int getAccountNumber() { return accountNumber; }
    string getName() { return accountHolderName; }
    double getBalance() { return balance; }
    string getAccountType() { return accountType; }

};//cuss words for the semi colon--ends the class definition

// Initialize static member (required outside the class)
int BankAccount::nextAccountNumber = 1001;  // Starting account number

int main() {
    BankAccount accounts[10];  // Array for up to 10 customers
    int accountCount = 0;  // Track how many accounts we have
    int choice;
    
    //I couldn't help it--I had to add a welcome message

    cout << "========================================" << endl;
    cout << "  ++ WELCOME TO EPIC BANKING SYSTEM ++    " << endl;
    cout << "========================================" << endl;
    
    do {
        cout << "\n--- BANKING MENU ---" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Apply Interest" << endl;
        cout << "5. Display Account Info" << endl;
        cout << "6. Display All Accounts" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        
               switch (choice) {
           case 1: {
    // Create new account
    if (accountCount < 10) {
        string name, type;
        double initialBalance, rate;
        
        cout << "Enter account holder name: ";
        cin.ignore(); // Clear input buffer--cuss words
        getline(cin, name);
        
        cout << "Enter account type (checking/saving): ";
        cin >> type;
        
        cout << "Enter initial balance: $";
        cin >> initialBalance;
        
        cout << "Enter interest rate (as decimal, e.g., 0.05 for 5%): ";
        cin >> rate;
        
        accounts[accountCount] = BankAccount(name, type, initialBalance, rate);
        
        // Display the new account information
        cout << "\n========== NEW ACCOUNT CREATED ==========" << endl;
        accounts[accountCount].displayAccountInfo();
        cout << "=========================================" << endl;
        
        accountCount++;
        
        // Pause and prompt user to continue--gotta go have a way for the user to go back to the main menu
        cout << "\nPress Enter to return to main menu...";
        cin.ignore(); // Clear any leftover input
        cin.get();    // Wait for user to press Enter
        
    } else {
        cout << "Maximum of 10 accounts reached!" << endl;
    }
    break;
}
            case 2: {
                // Deposit money
                if (accountCount == 0) {
                    cout << "No accounts exist! Create an account first." << endl;
                    break;
                }
                
                int accNum;
                double amount;
                cout << "Enter account number: ";
                cin >> accNum;
                
                bool found = false;
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
                        cout << "Enter deposit amount: $";
                        cin >> amount;
                        accounts[i].deposit(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 3: {
                // Withdraw money
                if (accountCount == 0) {
                    cout << "No accounts exist! Create an account first." << endl;
                    break;
                }
                
                int accNum;
                double amount;
                cout << "Enter account number: ";
                cin >> accNum;
                
                bool found = false;
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
                        cout << "Enter withdrawal amount: $";
                        cin >> amount;
                        accounts[i].withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 4: {
                // Apply interest
                if (accountCount == 0) {
                    cout << "No accounts exist! Create an account first." << endl;
                    break;
                }
                
                int accNum;
                cout << "Enter account number: ";
                cin >> accNum;
                
                bool found = false;
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].getAccountNumber() == accNum) {
                        accounts[i].applyInterest();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 5: {
                // Display specific account
                if (accountCount == 0) {
                    cout << "No accounts exist! Create an account first." << endl;
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
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 6: {
                // Display all accounts
                if (accountCount == 0) {
                    cout << "No accounts exist! Create an account first." << endl;
                } else {
                    cout << "\n========== ALL ACCOUNTS ===========" << endl;
                    for (int i = 0; i < accountCount; i++) {
                        accounts[i].displayAccountInfo();
                    }
                    cout << "===================================" << endl;
                }
                break;
            }
            case 7:
                cout << "Thank you for banking with us!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
           
        }  // Close switch statement
    } while (choice != 7);  // Close do-while loop

    return 0;
}


// Constructor implementation--back end
//creates account with auto-assigned number--case 1
BankAccount::BankAccount(string name, string type, double initialBalance, double rate) {
    accountNumber = nextAccountNumber; // Take current number
    nextAccountNumber++;   // Increment for next account
    accountHolderName = name;
    accountType = type;
    balance = initialBalance;
    interestRate = rate;
    
    cout << "Account created successfully! Account #" << accountNumber << endl;
}

// Deposit money-- Case 2
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposited $" << fixed << setprecision(2) << amount 
             << ". New balance: $" << balance << endl;
    } else {
        cout << "Invalid deposit amount. Must be positive!" << endl;
    }
}

// Withdraw money with validation--case 3--bool return type
bool BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        cout << "Invalid withdrawal amount. Must be positive!" << endl;
        return false;
    }
    if (amount > balance) {
        cout << "Insufficient funds! Current balance: $" << fixed << setprecision(2) << balance << endl;
        return false;
    }
    //old bal minus amount=new balance
    balance -= amount;
    cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
    return true;
}

// Apply interest--case 4
void BankAccount::applyInterest() {
    double interest = balance * (interestRate / 12);  // Monthly interest 
    balance += interest;
    cout << "Interest applied: $" << fixed << setprecision(2) << interest 
         << ". New balance: $" << balance << endl;
}

// Display account info--case 6
void BankAccount::displayAccountInfo() {
    cout << fixed << setprecision(2);
    cout << "\n--- Account Information ---" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder: " << accountHolderName << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Interest Rate: " << (interestRate * 100) << "%" << endl;
    cout << "-------------------------" << endl;
}



//IGNORE--Internal Notes:

//Static member for auto-assigning account numbers--stores the next account number to be assigned//
//Array of 10 bankAccount objects to handle multiple customers--fixed size for simplicity//
//Appropriate member functions (constructor, getters, setters, deposit, withdraw, etc.)

//REGULAR MEMBERS:
//Each object has its OWN copy
//Access with object.member
//Different values for each object
 
//STATIC MEMBERS:
//ONE copy shared by ALL objects of the class
//Access with ClassName::member (no object needed!)
//Same value for ALL objects

//EPIC Banking simiulation program with classes and static members-- lets go wild with it--
//complete with account creation, deposits, withdrawals, interest calculation, and account info display
//interactive menu for user actions
//multiple bank accounts managed in an array
//account search and management functions

//Implement the constructor and methods
//Initialize the static member
//Create the array of 10 accounts
//Build the interactive menu system
//Add all the banking operations
//design the user interface first, then implement the backend to support it

//switch statement to handle menu choices--fancy cleaner than if/else chains--cuz thats a mess--switch is neater.
//case 1: = "if choice equals 1, do this"
//break; = "stop here, don't continue to next case"
//default: = "if choice doesn't match any case, do this"
//use 12 for monthly interest, could have used 4 for quarterly, 1 for yearly, etc.--realistic banking logic


//cin.ignore() to clear input buffer before getline() to avoid skipping input--cuss words.
//User types 1 and presses ENTER
//cin >> choice reads the 1 but leaves the \n (newline) sitting in the input buffer
//getline(cin, name) immediately grabs that leftover \n and thinks the user pressed ENTER with no input
//Result: name becomes an empty string
//Mixing cin >> with getline() always needs cin.ignore() between them.

//going to have use this with each case incase someone tries to input and no imputs exist--ie:
//if (accountCount == 0) {
                   // cout << "No accounts exist! Create an account first." << endl;
                    //break;
