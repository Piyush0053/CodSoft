#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char>>& board);
void displayBoard(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, char player, int row, int col);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
bool playAgain();

int main() {
    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1;

    vector<vector<char>> board(3, vector<char>(3, ' '));

    cout << "Welcome to the Summer Internship Tic-Tac-Toe Game!" << endl;

    do {
        initializeBoard(board);
        int totalMoves = 0;

        while (true) {
            displayBoard(board);

            int row, col;
            do {
                cout << "Player " << currentPlayer << ", enter your move (row and column): ";
                cin >> row >> col;
            } while (!makeMove(board, currentPlayer, row, col));

            totalMoves++;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
                break;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw! The game is over." << endl;
                break;
            }

            currentPlayer = (currentPlayer == player1) ? player2 : player1;
        }
    } while (playAgain());

    cout << "Thank you for playing Tic-Tac-Toe! Goodbye!" << endl;

    return 0;
}

// Initialize the game board
void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Display the game board
void displayBoard(const vector<vector<char>>& board) {
    system("clear");  // Clear the console (for Linux/macOS, use "cls" for Windows)
    cout << "   0   1   2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << "  ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "  ---|---|---" << endl;
        }
    }
    cout << endl;
}

// Make a move on the board
bool makeMove(vector<vector<char>>& board, char player, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

// Check if the current player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;  // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;  // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;  // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;  // Diagonal win (top-right to bottom-left)
    }
    return false;
}

// Check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;  // There's an empty space, the game is not a draw yet
            }
        }
    }
    return true;  // All spaces are filled, it's a draw
}

// Ask if the players want to play again
bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
