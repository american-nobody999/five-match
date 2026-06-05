//this is a program demostrating enumeration types in C++//
//contains two syntax errors and demonstartes assigning sizes to enumvalues--keeps the code neat, tidy, and readable--its for the medium size shirt//
#include <iostream>
using namespace std;    

enum sizes {small = 1, medium = 2, large = 3, extra_large = 4};
int main() {
    sizes shirt_size;

    shirt_size = medium;

    if (shirt_size == medium) {
        cout << "The size of the shirt is medium." << endl
    } else {
        cout << "The size of the shirt is not medium." << endl
    }

    return 0;
}
