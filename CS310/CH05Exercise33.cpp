#include <iostream>
using namespace std;
int a;              // Time for first dish (in minutes)
int b;              // Additional time for each following dish
int t;              // Total time available
int dishCount;      // Number of dishes prepared (starts at 0)
int totalTimeUsed;  // Running total of time spent (starts at 0)
int currentDishTime; // Time needed for the current dish being considered
int main() {
    // Get user input
    cout << "Enter time for first dish (in minutes): ";
    cin >> a;
    cout << "Enter additional time for each following dish (in minutes): ";
    cin >> b;
    cout << "Enter total time available (in minutes): ";
    cin >> t;

    // Initialize variables
    dishCount = 0;
    totalTimeUsed = 0;
    currentDishTime = a;

    // Loop to prepare dishes while time allows
    while (totalTimeUsed + currentDishTime <= t) {
        totalTimeUsed += currentDishTime; // Update total time used
        dishCount++;                       // Increment dish count
        currentDishTime += b;              // Update time for next dish
    }

    // Output the result
    cout << "Number of dishes that can be prepared: " << dishCount << endl;

    return 0;
}   
