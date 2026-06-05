
//This program calculates the billing amount for tax consulting services
//based on user input for income, consulting time, and hourly rate.
//It uses a user-defined function to perform the billing calculation.
//The billing rates differ for low-income(40) and regular (70clients.

#include <iostream>
#include <iomanip>
using namespace std;

double hourlyRate;
int consultingTimeInMinutes;
double income;
double billingAmount;

double calculateBilling(double hourlyRate, int consultingTimeInMinutes, bool isLowIncome) {
    double billingAmount = 0.0;
    if (isLowIncome) {
        if (consultingTimeInMinutes > 30) {
            billingAmount = ((consultingTimeInMinutes - 30) / 60.0) * hourlyRate * 0.40;
        }
    } else {
        if (consultingTimeInMinutes > 20) {
            billingAmount = ((consultingTimeInMinutes - 20) / 60.0) * hourlyRate * 0.70;
        }
    }
    return billingAmount;
}

int main() {
    // Get user input here
    cout << "Enter your annual income: $";
    cin >> income;
    cout << "You entered: $" << income << endl;  // Debug line
    
    cout << "Enter total consulting time (in minutes): ";
    cin >> consultingTimeInMinutes;
    cout << "You entered: " << consultingTimeInMinutes << " minutes" << endl;  // Debug line
    
    cout << "Enter hourly rate: $";
    cin >> hourlyRate;
    cout << "You entered: $" << hourlyRate << endl;  // Debug line

    // Calculate billing (call your function)
    bool isLowIncome = (income <= 25000);
    billingAmount = calculateBilling(hourlyRate, consultingTimeInMinutes, isLowIncome);

    // Display result
    cout << fixed << setprecision(2);
    cout << "Total billing amount: $" << billingAmount << endl;

    return 0;
}
    
