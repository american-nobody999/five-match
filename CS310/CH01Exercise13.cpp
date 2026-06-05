//This algorithm calculates the weighted average of four test scores--requires inputs from users before calculation//

# include <iostream>
# include <iomanip> 

using namespace std;

int main()
{
    int testScore1, testScore2, testScore3, testScore4;
    double weight1, weight2, weight3, weight4;
    double average;

   
    //this section gets the  input (cin) test scores from the user//
    cout << "Enter the first test score: ";
    cin >> testScore1;

    /*this is an if/else statement that determines the weight by the users input score itself, if its this, then its this, if not, then this--*/
    if (testScore1 >= 90) {
        weight1 = 0.4;
    } else if (testScore1 >= 80) {
        weight1 = 0.3;
    } else if (testScore1 >= 70) {
        weight1 = 0.2;
    } else {
        weight1 = 0.1;
    }
    cout << "Enter the second test score: ";
    cin >> testScore2;
   
    if (testScore2 >= 90) {
        weight2 = 0.4;
    } else if (testScore2 >= 80) {
        weight2 = 0.3;
    } else if (testScore2 >= 70) {
        weight2 = 0.2;
    } else {
        weight2 = 0.1;
    }
    cout << "Enter the third test score: ";
    cin >> testScore3;
   
    if (testScore3 >= 90) {
        weight3 = 0.4;
    } else if (testScore3 >= 80) {
        weight3 = 0.3;
    } else if (testScore3 >= 70) {
        weight3 = 0.2;
    } else {
        weight3 = 0.1;
    }

    cout << "Enter the fourth test score: ";
    cin >> testScore4;
   
    if (testScore4 >= 90) {
        weight4 = 0.4;
    } else if (testScore4 >= 80) {
        weight4 = 0.3;
    } else if (testScore4 >= 70) {
        weight4 = 0.2;
    } else {
        weight4 = 0.1;
    }

    //this formula calculates the weighted average from user input//
    average = (testScore1 * weight1 + testScore2 * weight2 + testScore3 * weight3 + testScore4 * weight4) / (weight1 + weight2 + weight3 + weight4);

    //this line formats the output to 2 decimal places//
    cout << fixed << setprecision(2);//from the iomanip library//
    cout << "The weighted average test score is: " << average << endl;


    return 0;
}
