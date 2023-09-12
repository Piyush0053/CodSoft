#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Constants
const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.0;

// Function prototypes
void initializeSeats(vector<vector<char>>& seats);
void displayMenu();
void displaySeats(const vector<vector<char>>& seats);
bool bookSeat(vector<vector<char>>& seats, int row, int col);
double calculateTotalCost(const vector<vector<char>>& seats);
bool isValidSeat(int row, int col);

int main() {
    vector<vector<char>> seats(NUM_ROWS, vector<char>(NUM_COLS, 'O'));  // 'O' represents an available seat

    cout << "Welcome to the Summer Internship Movie Ticket Booking System!" << endl;

    while (true) {
        displayMenu();

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2: {
                int row, col;
                cout << "Enter the row and column of the seat you want to book: ";
                cin >> row >> col;

                if (isValidSeat(row, col)) {
                    if (bookSeat(seats, row - 1, col - 1)) {
                        cout << "Seat booked successfully!" << endl;
                    } else {
                        cout << "Seat is already booked. Please choose another seat." << endl;
                    }
                } else {
                    cout << "Invalid row or column. Please enter valid values." << endl;
                }
                break;
            }
            case 3:
                cout << fixed << setprecision(2);
                cout << "Total cost: $" << calculateTotalCost(seats) << endl;
                break;
            case 4:
                cout << "Thank you for using the Summer Internship Movie Ticket Booking System. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }

    return 0;
}

// Initialize the seats as available
void initializeSeats(vector<vector<char>>& seats) {
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            seats[i][j] = 'O';
        }
    }
}

// Display the main menu
void displayMenu() {
    cout << "Main Menu:" << endl;
    cout << "1. View Movie Listings" << endl;
    cout << "2. Book a Seat" << endl;
    cout << "3. Calculate Total Cost" << endl;
    cout << "4. Exit" << endl;
    cout << "Select an option: ";
}

// Display the current seat availability
void displaySeats(const vector<vector<char>>& seats) {
    cout << "Current Seat Availability:" << endl;

    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

// Book a seat if it's available
bool bookSeat(vector<vector<char>>& seats, int row, int col) {
    if (seats[row][col] == 'O') {
        seats[row][col] = 'X'; // 'X' represents a booked seat
        return true;
    }
    return false;
}

// Calculate the total cost based on the number of booked seats
double calculateTotalCost(const vector<vector<char>>& seats) {
    int bookedSeats = 0;

    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            if (seats[i][j] == 'X') {
                bookedSeats++;
            }
        }
    }

    return bookedSeats * TICKET_PRICE;
}

// Check if the seat coordinates are valid
bool isValidSeat(int row, int col) {
    return row >= 1 && row <= NUM_ROWS && col >= 1 && col <= NUM_COLS;
}
