/* * * * * * * * * * * * * * * * * * * * * * * * * * */ 
/* CIS 310 - C++ Programming                         */
/* Ch08Exercise07.cpp                                */
/* Author: Leslie Brockman                           */
/* Date: 2025-10-26                                  */
/* Description: program calculates names & votes.    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

//This program collects the last names of five candidates in an election and their corresponding vote counts from the user.
//It then calculates and displays each candidate's percentage of the total votes and announces the winner.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string candidates[5];  // Store 5 last names--array 1
int votes[5];  // Store vote counts for each candidate--array 2

int main () {
    // Loop to get 5 candidate names
    for (int i = 0; i < 5; i++) {
        cout << "Enter last name of candidate " << (i + 1) << ": ";
        cin >> candidates[i];  // User types name, stores in array
    }

    // Loop to get vote counts for each candidate
    for (int i = 0; i < 5; i++) {
        cout << "Enter votes for " << candidates[i] << ": ";
        cin >> votes[i];  // User types vote count
    }

    int totalVotes = 0;
    for (int i = 0; i < 5; i++) {
        totalVotes += votes[i];
    }

    // Display results
    cout << fixed << setprecision(2);
    for (int i = 0; i < 5; i++) {
        double percentage = (static_cast<double>(votes[i]) / totalVotes) * 100;
        cout << "Candidate: " << candidates[i] << " - " << votes[i] << " votes (" << percentage << "%)" << endl;
    }

    // Find and display winner
        int winnerIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (votes[i] > votes[winnerIndex]) {
        winnerIndex = i;
    }
}
     // Display winner announcement - winner winner chicken dinner!
    double winnerPercentage = (static_cast<double>(votes[winnerIndex]) / totalVotes) * 100;
    cout << "\n========================================" << endl;//styling for the winner display--:)
    cout << "*** ELECTION WINNER ***" << endl;
    cout << "Winner: " << candidates[winnerIndex] << " with " << votes[winnerIndex] << " votes (" << winnerPercentage << "%)!" << endl;
    cout << "========================================" << endl;
    
    return 0;
}


//--- IGNORE--internal use only---
//5 candidate last names (strings)
//Number of votes for each candidate (integers)
//Calculate total votes cast
//Calculate each candidate's percentage
//Find the winner (most votes)--display winner's name and vote count, and percentage of total votes
//user inputs names and total votes-- divided by total votes to get percentage
//loop calculates through votes to get total votes
//loop to find winner by comparing votes
//Arrays (for storing names and votes)
//Loops (for input, processing, output)
//Mathematical calculations (percentages)
//Finding maximum value (winner)
//percentages need iomanip for setprecision and fixed
//percentage calculation using static_cast<double>
