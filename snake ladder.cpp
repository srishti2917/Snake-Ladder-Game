#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Define the board with snakes and ladders
int board[101];

void setupBoard() {
    // Initialize board with default values
    for (int i = 0; i <= 100; i++)
        board[i] = i;
    
    // Ladders (start -> end)
    board[3] = 22;
    board[5] = 8;
    board[11] = 26;
    board[20] = 29;
    board[17] = 4;
    board[19] = 7;
    board[27] = 1;
    board[21] = 9;
    
    // Snakes (start -> end)
    board[34] = 1;
    board[47] = 19;
    board[62] = 24;
    board[56] = 53;
    board[87] = 36;
    board[93] = 73;
    board[95] = 75;
    board[98] = 78;
}

int rollDice() {
    return (rand() % 6) + 1;
}

void playGame() {
    int position = 1;
    char choice;
    
    while (position < 100) {
        cout << "Press 'r' to roll the dice: ";
        cin >> choice;
        
        if (choice == 'r' || choice == 'R') {
            int dice = rollDice();
            cout << "You rolled a " << dice << "!" << endl;
            
            if (position + dice <= 100) {
                position += dice;
                position = board[position]; // Adjust for snakes or ladders
            }
            
            cout << "You are now at position " << position << "\n";
        }
    }
    
    cout << "Congratulations! You reached 100 and won the game!" << endl;
}

int main() {
    srand(time(0)); // Seed for random number generation
    setupBoard();
    cout << "Welcome to Snake and Ladder Game!" << endl;
    playGame();
    return 0;
}
