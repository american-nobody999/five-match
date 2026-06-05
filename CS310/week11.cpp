
/* * * * * * * * * * * * * * * * * * * * * * * * * * */ 
/* CIS 310 - C++ Programming                         */
/* Ch10Exercise21.cpp                                */
/* Author: Leslie Brockman                           */
/* Date: 2025-11-17                                  */
/* Description:This program is Magical Bank Account  */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

//staying on theme here with a "magical" banking system
//features: template class, overloaded operator, exception handling, pointers
//Thank you Alexander for the mana magick inspiration!

#include <iostream>
#include <string>
#include <stdexcept>//eception handling 
#include <memory>//smart pointers
using namespace std;

// Template class for different account types
template <typename T>
class MagicalAccount {
private:
    string accountHolder;
    T balance;
    T* transactionHistory;  // Pointer #1
    int* transactionCount;  // Pointer #2
    int maxTransactions;

public:
    // Constructor
    MagicalAccount(string holder, T initialBalance, int maxTrans = 10) 
        : accountHolder(holder), balance(initialBalance), maxTransactions(maxTrans) {
        transactionHistory = new T[maxTransactions];
        transactionCount = new int(0);
    }

    // Copy constructor - DEEP COPY--fix "double free" error
MagicalAccount(const MagicalAccount& other) 
    : accountHolder(other.accountHolder), balance(other.balance), maxTransactions(other.maxTransactions) {
    
    // Create NEW memory (not copy pointers!)
    transactionHistory = new T[maxTransactions];
    transactionCount = new int(*other.transactionCount);
    
    // Copy the actual data
    for (int i = 0; i < *other.transactionCount; i++) {
        transactionHistory[i] = other.transactionHistory[i];
    }
}

    // Destructor
    ~MagicalAccount() {
        delete[] transactionHistory;
        delete transactionCount;
    }
    
    // Overloaded + operator for adding to balance
    MagicalAccount operator+(const T& amount) {
        MagicalAccount newAccount = *this;
        newAccount.balance += amount;
        return newAccount;
    }
    
    // Member function with exception handling
    //
    void withdraw(T amount) {
        try {
            if (amount <= 0) {
                throw invalid_argument("Amount must be positive");//throw invalid argument exception
            }
            if (amount > balance) {
                throw runtime_error("Insufficient funds");//throw runtime error exception
            }
            
            balance -= amount;
            
            // Add to transaction history
            if (*transactionCount < maxTransactions) {
                transactionHistory[*transactionCount] = amount;
                (*transactionCount)++;
            }
            
            cout << "Withdrawal successful! New balance: " << balance << endl;
            
        } catch (const invalid_argument& e) {
            cout << "Invalid argument error: " << e.what() << endl;
        } catch (const runtime_error& e) {
            cout << "Runtime error: " << e.what() << endl;
        }
    }
    
    // Display account info
    void displayAccount() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transaction Count: " << *transactionCount << endl;
        cout << "Transaction History: ";
        for (int i = 0; i < *transactionCount; i++) {
            cout << transactionHistory[i] << " ";
        }
        cout << endl;
    }
    
    // Getter for balance
    T getBalance() const { return balance; }
};

int main() {
    try {
        // Create magical accounts with different types
        MagicalAccount<double> goldAccount("Fair Lady", 1000.50);
        MagicalAccount<int> silverAccount("Free Willy", 500);
        MagicalAccount<float> manaAccount("Oxygono", 750.25f);
        
        cout << "=== MAGICAL BANKING SYSTEM ===" << endl;
        
        // Test overloaded operator
        cout << "\n--- Testing Overloaded + Operator ---" << endl;
        MagicalAccount<double> boostedGold = goldAccount + 200.0;
        cout << "Original Fair Lady balance: " << goldAccount.getBalance() << endl;
        cout << "Boosted Fair Lady balance: " << boostedGold.getBalance() << endl;

        // Test exception handling
        cout << "\n--- Testing Exception Handling ---" << endl;
        goldAccount.withdraw(100.0);  // Valid withdrawal
        goldAccount.withdraw(-50.0);  // Invalid - negative amount
        goldAccount.withdraw(5000.0); // Invalid - insufficient funds
        
        // Display accounts
        cout << "\n--- Account Information ---" << endl;
        goldAccount.displayAccount();
        silverAccount.displayAccount();
        manaAccount.displayAccount();
        
        // Test pointers
        cout << "\n--- Testing Pointer Operations ---" << endl;
        silverAccount.withdraw(100);
        silverAccount.withdraw(50);
        silverAccount.displayAccount();
        
    } catch (const exception& e) {
        cout << "Unexpected error in main: " << e.what() << endl;
    }
    
    cout << "\nMagical Banking System executed successfully!" << endl;
    return 0
;

//--- DEVELOPMENT NOTES ---
// FEATURES IMPLEMENTED:
// Template class MagicalAccount<T> for different data types
// Overloaded + operator for balance addition
// Exception handling in withdraw() member function
//get rid of the string and the cout statements
// Two pointers: transactionHistory* and transactionCount*
// Dynamic memory allocation and cleanup
// Multiple template instantiations (double, int, float)
// Professional error handling with try/catch blocks

// "Double free" error - this is a common issue with copy constructors and destructors!
//creates a temporary MagicalAccount object when returning by value
//Copy assignment copies the same pointers, Temporary object destructor runs and deletes the memory, destructor tries to delete the same memory again = CRASH! overloaded operator creates a copy -- add copy constructor to fix---DEEP COPY

//A constructor is called automatically when CREATE an object.
//Sets up initial values - account holder name, balance, allocates memory for transaction history and count
//A destructor is called automatically when an object goes out of scope or is deleted. (destroyed when main ends for stack objects)
//Frees up dynamically allocated memory to prevent memory leaks.
