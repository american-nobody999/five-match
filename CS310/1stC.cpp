//This program is written with with weekly progressions//

#include <iostream> 

using namespace std;

//week 1 function//
void week1 () {
    cout << "Hello, C++!" << endl;
}

/*This program demostrates basic input and output operations in C++ using cin and cout*/
/*This program will contain two syntax errors as per assignment deliverables.*/
//week 2 function//

void week2 () {
    int num;
    cout << "Enter a number: ";
    cin >> num;>
    cout << "You entered: " << num << endl;
}

//Week 3 selection function synax errors using if/else/while//
void week3 () {
    //hint: You're stuck...//
    int choice;
    cout << "Enter a number other than 1: ";
    cin >> choice;
    if (choice = 1) {
        while (true) {
            cout << "You are stuck!\n"
}
else {
        cout << "You are free!\n" <<endl;
    }
}

void week4 () {
    //This program demonstrates a simple for loop in C++ using the repetition structure using for //
    for (int i = 1; i <= 5; i++) {
        cout << "Count to 5 " << i << endl;
    }
}
void week5 () {
    Of course\! That's a creative set of requirements. Here is a C++ program that incorporates all those ideas and includes the two intentional errors needed for your assignment.

### C++ Code with Two Errors:

```cpp
#include <iostream>
#include <string>

// This function is supposed to add numbers but has an error
int calculateValue(int a, int b)
{
    // ERROR 1: This function should return an integer, but it's returning a string.
    return "we are coming back";
}

int main()
{
    int result = calculateValue(7540, 0);

    // ERROR 2: This line tries to print a variable 'finalResult' that was never declared.
    std::cout << finalResult << std::endl;

    // This fulfills the requirement to return 7541 from the program
    return 7541;
}

int main() { 
    //week1();//comment out to run without// 
    //week2();// comment out to run without//
    //week3();//comment out to run without//
    //week4();//comment out to run without//
}
    return 0;
