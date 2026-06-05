/* * * * * * * * * * * * * * * * * * * * * * * * * * */ 
/* CIS 310 - C++ Programming                        */
/* Ch04Exercise16.cpp                                */
/* Author: Leslie Brockman                           */
/* Date: 2025-09-27                                  */
/* Description: This program calculates book prices. */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

/*I apologize for the lateness in this assignment, im not going to waste your time emailing you about it. I misread and thought it was do Sunday. My mistake. Now thats it already late Im going to play with it*/

/* CCCCCCCC          ++                ++          */
/* CC                ++                ++          */
/* CC          ++++++++++++++    ++++++++++++++    */
/* CC          ++++++++++++++    ++++++++++++++    */
/* CC                ++                ++          */
/* CCCCCCCC          ++                ++          */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

/* option 1 */
  
    /*declaring the magic numbers so others know what they are, promising the compiler I wont change any of these through out the program by using const--i tired just using the percentages, but it kept throwing out warnings.*/
    const double option1_deliveryPayment = 5000.0;
    const double option1_publishPayment = 20000.0;
    const double option2_rate = 0.125;
    const double option3_first_threshold = 4000;
    const double option3_first_rate = 0.10;
    const double option3_second_rate = 0.14;
    int numCopies;
    double netPrice;


    cout << "Enter the number of copies sold: ";
    cin >> numCopies;
    cout << "Enter the net price of the book: ";
    cin >> netPrice;

/* option 1 */
/* adding option 1 to compare with options 2 and 3*/
     double fixedRoyalties = (option1_deliveryPayment + option1_publishPayment);

/* option 2--first 4000 at 10 percent, then subtract 4000 from numb of copies over 4000 to get the remaining at 14. */
    double royaltiesOption2; 
    royaltiesOption2 = (numCopies) * (netPrice) * (option2_rate);

    double royaltiesOption3 = 0;
    if (numCopies <= 4000) {
        royaltiesOption3 = numCopies * netPrice * option3_first_rate;
    } else {
        royaltiesOption3 = (4000 * netPrice * option3_first_rate) + ((numCopies - 4000) * netPrice * option3_second_rate);
    }

    cout << fixed << setprecision(2);
    cout << "Royalties for Option 1: $" << fixedRoyalties << endl;
    cout << "Royalties for Option 2: $" << royaltiesOption2 << endl;
    cout << "Royalties for Option 3: $" << royaltiesOption3 << endl;

    //comparing the three options to see which is best, && is going to to check to make sure we get true, both sides need to be true to be true//
    if (fixedRoyalties >= royaltiesOption2 && fixedRoyalties >= royaltiesOption3) {
        cout << "Option 1 is the best choice." << endl;
    } else if (royaltiesOption2 >= fixedRoyalties && royaltiesOption2 >= royaltiesOption3) {
        cout << "Option 2 is the best choice." << endl;
        //if its not 1 or 2, then its 3 and no math is needed//
    } else {
        cout << "Option 3 is the best choice." << endl;
    }

    return 0;
}

