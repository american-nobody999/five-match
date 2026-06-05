#include iostream
using namespace std;

//declare a function to display the board borders and positions
void displayBoard(char board[3][3]) {
    cout << "Current Board:" << endl;
    cout << "+---+---+---+" << endl;  // Top border
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << "| " << board[row][col] << " ";
        }
        cout << "|" << endl;  // Right border
        cout << "+---+---+---+" << endl;  // Row border
    }
}


int main()
{
    char board[3][3];  // 3x3 grid for the board

    //loopy d loops to fill the board with positions 1-9
    int position = 1;  // Start counting from 1

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            // Convert position number to character and store it
            board[row][col] = position + '0';  // Converts int to char
            position++;  // Move to next position (2, 3, 4, etc.)
        }
   }

   displayBoard(board);  // This will show your grid!


// Get user input
int userInput;
cout << "Enter a position (1-9) to mark: ";
cin >> userInput;

// Update the board array
if (userInput >= 1 && userInput <= 9) {
    int row = (userInput - 1) / 3; //math on the rows and columns
    int col = (userInput - 1) % 3;
    board[row][col] = 'X';  // Mark the position with 'X'
} else {
    // Handle invalid input--I said 1 thru 9--this is too fun
    cout << "Invalid position. Please enter a number between 1 and 9." << endl;
}
// Display updated board
displayBoard(board);
cout << "Thank you for playing! This is the end of your demo and my code I'm writing for this assignment!" << endl;
return 0;

}

//rinse and repeat for more functional moves









//int main() {    // Declare 2D array
    // Fill the array (somehow)
    // Display the array as a grid
    //return 0;
//}

//To create borders:
//cout statements to print the border characters
//Loops to repeat patterns
//Spacing to align everything nicely

// Use nested loops with a counter--easier for user to pick positions and the compiler to manage--cleaner code.
// Loop through rows and columns
// Keep track of position number (1-9)
// Convert number to character
//First iteration: position = 1 → board[0][0] = '1' → position++ makes it 2
//Second iteration: position = 2 → board[0][1] = '2' → position++ makes it 3--so on

// After displaying the initial board:
// Get user input
// Update the board array
// Display updated board

// math for position conversion:
// Example: Position 5 → row = (5-1)/3 = 1, col = (5-1)%3 = 1 → center square!
