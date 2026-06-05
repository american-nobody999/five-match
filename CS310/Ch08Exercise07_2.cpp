/* * * * * * * * * * * * * * * * * * * * * * * * * * */ 
/* CIS 310 - C++ Programming                         */
/* Ch08Exercise07_Dynamic.cpp                        */
/* Author: Leslie Brockman                           */
/* Date: 2025-11-15                                  */
/* Description: Dynamic array election program       */
/* Calculates names & votes for ANY number of       */
/* candidates using dynamic memory allocation        */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

// This program collects last names and vote counts for ANY number of candidates in an election.
// It uses dynamic arrays to handle flexible candidate counts.
// It calculates and displays each candidate's percentage and announces the winner.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main () {
    // Ask user for number of candidates - THIS IS THE KEY CHANGE!
    int numCandidates;
    cout << "========================================" << endl;
    cout << "*** DYNAMIC ELECTION RESULTS UPDATE  ***" << endl;
    cout << "========================================" << endl;
    cout << "How many candidates are running in this election? ";
    cin >> numCandidates;
    
    // Input validation
    while (numCandidates <= 0) {
        cout << "Please enter a positive number of candidates: ";
        cin >> numCandidates;
    }
    
    // CREATE DYNAMIC ARRAYS - Based on user input!
    string* candidates = new string[numCandidates];  // Dynamic string array
    int* votes = new int[numCandidates];            // Dynamic int array
    
    cout << "\n--- CANDIDATE REGISTRATION ---" << endl;
    
    // Loop to get candidate names (now flexible!)
    for (int i = 0; i < numCandidates; i++) {
        cout << "Enter last name of candidate " << (i + 1) << ": ";
        cin >> candidates[i];  // Same syntax as before!
    }
    
    cout << "\n--- VOTE COLLECTION ---" << endl;
    
    // Loop to get vote counts for each candidate
    for (int i = 0; i < numCandidates; i++) {
        cout << "Enter votes for " << candidates[i] << ": ";
        cin >> votes[i];  // Same syntax as before!
    }
    
    // Calculate total votes
    int totalVotes = 0;
    for (int i = 0; i < numCandidates; i++) {
        totalVotes += votes[i];
    }
    
    // Display results header
    cout << "\n--- ELECTION RESULTS ---" << endl;
    cout << "Total Votes Cast: " << totalVotes << endl;
    cout << "========================================" << endl;
    
    // Display results for each candidate
    cout << fixed << setprecision(2);
    for (int i = 0; i < numCandidates; i++) {
        double percentage = (static_cast<double>(votes[i]) / totalVotes) * 100;
        cout << "Candidate: " << candidates[i] << " - " << votes[i] << " votes (" << percentage << "%)" << endl;
    }

    // Find winner (same logic, works with any array size, which is the point of dynamic arrays.)
    int winnerIndex = 0;
    for (int i = 1; i < numCandidates; i++) {
        if (votes[i] > votes[winnerIndex]) {
            winnerIndex = i;
        }
    }
    
    // Display winner announcement - winner winner chicken dinner!
    double winnerPercentage = (static_cast<double>(votes[winnerIndex]) / totalVotes) * 100;
    cout << "\n========================================" << endl;
    cout << "*** ELECTION WINNER ***" << endl;
    cout << "Winner: " << candidates[winnerIndex] << " with " << votes[winnerIndex] << " votes (" << winnerPercentage << "%)!" << endl;
    cout << "========================================" << endl;
    
    // IMPORTANT: Free dynamic memory!
    delete[] candidates;
    delete[] votes;

    cout << "\nThank you for using the Dynamic Election Update!" << endl;

    return 0;
}

//--- ignore/ internal notes only ---
//Switch to dynamic arrays for more flexibility with number of candidates--flexible--memory efficient--scalable solutions
// User-specified number of candidates
// Dynamic memory allocation with new[]
// Same logic works for any array size  
// Memory cleanup with delete[]
// Input validation for positive candidate count
// Flexible for any election size (3 candidates to 50)
//Ask user for number of candidates
//Replace static arrays with dynamic allocation
//Change all 5 to numCandidates in loops
//Add memory cleanup at the end
//I got too many annoying assignments pulling me from converting my epic banking system into modern fortran and its distracting.
