// This program calculates the interest on a credit card balance//

#include <iostream>//for cin and cout--dont need <string>//
#include <iomanip>//for setprecision() and the decimals//

using namespace std;//dont need std:: before every cin and cout//
//declaring the variables//
//this is the equivlant of <body> in html, everything "seen" needs to be in here//

int main()
{
    int d1, d2;//whole numbers//
    double netBalance, payment, averageDailyBalance, interestRate = 0.0152, interest; //decimals//


//getting the users imput for the variables--needed to calaculate the interest//
    cout << "Enter net balance: ";
    cin >> netBalance;
    cout << "Enter payment: ";
    cin >> payment;
    cout << "Enter number of days in billing cycle (d1): ";
    cin >> d1;
    cout << "Enter number of days payment is made before billing cycle (d2): ";
    cin >> d2;
    

    //this is the formula for the interest//
    averageDailyBalance = (netBalance * d1 - payment * d2) / d1;
    interest = averageDailyBalance * interestRate;
    
    //this is the output at two decimals and the reason for the include iomanip--//
    cout << fixed << setprecision(2);
    cout << "The interest is: $" << interest << endl;
    return 0;//just need the one//
}
