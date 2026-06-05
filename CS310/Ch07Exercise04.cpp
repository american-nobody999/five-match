//This program will compare a string and remove vowels from strings
#include <iostream>
#include <string>
#include <cstring> //for strchr function

using namespace std;

// Function to check if a character is a vowel
bool isVowel (char c) {
    return strchr("AEIOUaeiou", c) != nullptr;
}
// Function to remove vowels from a string
string removeVowel(const string& input) {
    string output;
    for (char c : input) {
        if (!isVowel(c)) {
            output += c;
        }
    }
    return output;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string output = removeVowel(input);
    cout << "Your string without vowels is: " << output << endl;

    return 0;
}

//variable scope--declare variables as close as possible to where you first use them--and in most limited scope as possible--global variables should be avoided in simple programs.

//int main() {
// string input;     // Declare right before you use it
//string output;    // Declare right before you use it
    // ... rest of your code
//}. put the string in the main
//gonna use getline instead of cin--cin only stores the first word, so getline(cin, input)
//Reads the entire line including spaces
//Stops only at the Enter key
//If user types "Hello World", it stores "Hello World"
//line 8--Checks both uppercase and lowercase vowels
//Returns true if vowel found, false if not
//line 12--removes the vowels, second function needed for the output.
