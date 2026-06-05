/* * * * * * * * * * * * * * * * * * * * * * * * * * */ 
/* CIS 310 - C++ Programming                         */
/* Ch10Exercise21.cpp                                */
/* Author: Leslie Brockman                           */
/* Date: 2025-11-01                                  */
/* Description:This uses functional/exceptions to    */
/* handle chaos events in a random number generator. */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */
// "The Calm After the Storm"

#include <iostream>
#include <random>//for RNG
#include <exception>//exception handling
#include <iomanip>
#include <cmath>//for fmod() and abs()
using namespace std;

// Custom exception class
class ChaosException : public exception {
public:
    const char* what() const noexcept override {
        return "CHAOS MODE ACTIVATED: Number too perfect. Reality rejected it.";
    }
};

int main() {
    cout << "=== RNG Exception Demo ===\n";
    cout << "Generating 25 numbers between 10 and 100...\n\n";

    // C++11 RNG 
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(10.0, 100.0);//floating-point distribution

    int chaos_count = 0;

    for (int i = 1; i <= 25; ++i) {
        double num;
        try {
            num = dist(gen);

            // Throw if number is "too perfect" (e.g., ends in .00, .50, or is exactly 42)
            if (fmod(num, 1.0) < 0.01 || abs(fmod(num, 1.0) - 0.5) < 0.01 || abs(num - 42.0) < 0.01) {
                throw ChaosException();
            }

            cout << i << ": " << fixed << setprecision(2) << num << "  [safe]\n";
        }
        catch (const ChaosException& e) {
            chaos_count++;
            cout << i << ": " << fixed << setprecision(2) << num 
                 << "  [CHAOS DETECTED!] " << e.what() << "\n";
        }
    }

    cout << "\n=== SUMMARY ===\n";
    cout << "Numbers generated: 25\n";
    cout << "Chaos events: " << chaos_count << "\n";
    cout << "Reality survived... barely.\n";

    cout << "\nP.S. Programming was a blast.\n";
    return 0;
}

//Generate 25 random numbers between 10 and 100, and trigger a "chaos" exception if a number is "too perfect" (ends in .00, .50, or is exactly 42).
//Custom exception class ChaosException provides a specific error message when such a number is generated.
//what() methosd overridden to return the chaos message.
//for loop generates numbers, checks for "too perfect" conditions, and throws ChaosException if any are met.
//can extend for more chaos rules or different ranges as needed.
//A chaos rule is a condition that defines when a randomly generated number is considered "too perfect" or special, triggering a custom exception (ChaosException)
//chaos rules are: ends in .00, .50, or is exactly 42
