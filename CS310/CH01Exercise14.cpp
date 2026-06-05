/* I modified this from number of pennies in a coin to a real world application of basically how a coin star might work, because who is asking for pennies back and I had to cash in my change today. I thought we got rid of the penny, and I got lost down the rabbit hole trying to recreate a receipt and this was as close as I could get because the no css in programming. I only used the iomanip library for formatting. I'm trying to use as less code as possible, so, why add a string, another lib, when we can use different features of the existing libraries? */

//This program calculates the total monetary value of a collection of coins.//



# include <iostream>
# include <iomanip>
    
using namespace std;

int main() {
    int numPennies, numNickels, numDimes, numQuarters;
    double totalDollars, fee;//for the decimals and 10 percent fee//

    // Get user input for the number of each type of coin
    cout << "Enter the number of pennies: ";//promts the user//
    cin >> numPennies;//goes innie to the computer to be stored//
    cout << "Enter the number of nickels: ";
    cin >> numNickels;
    cout << "Enter the number of dimes: ";
    cin >> numDimes;
    cout << "Enter the number of quarters: ";
    cin >> numQuarters;

    //Calculate the total amount in dollars, number of coins times value of its self, the () are the order of operations, figure out the problem--then write it out in word format--Please Exuse My Dear Aunt Sally//
    totalDollars = (numPennies * 0.01) + (numNickels * 0.05) + (numDimes * 0.10) + (numQuarters * 0.25);

    // fee has to come after the totalDollars calculation because it has to get the total first before getting the 10 percent.//
    fee = totalDollars * 0.10; //calculates the 10 percent fee//

    // the double doesn't matter if its at the top, and because the other two parts have to happen first, we can declare it here, and then just do the clalculation using the convential = and - in the same line, can declare variables anywhere, but cant use them before.//
    double totalAmount = totalDollars - fee; //calculates the total amount after the fee is taken out//
    // Display the total amount--Recipet//
    cout << "\n--- Receipt ---\n";
    cout << fixed << setprecision(2);//sets output to look like whole dollar and cents, instead of scientific notation//
    cout << "Total amount: $" <<setw(12)<< totalAmount << endl;
    //setw() sets the line of charachters to line this up pretty, used from imomanip lib, so do not need to use any strings//
    cout << "Subtotal:  $" << setw(12) <<totalDollars << endl;
    cout << "Fee (10%): $" << setw(12) << fee << endl;
    cout << "__________________\n";
    cout << "Total:     $" << setw(12) << totalAmount << endl;    
    return 0;
}

  
  
