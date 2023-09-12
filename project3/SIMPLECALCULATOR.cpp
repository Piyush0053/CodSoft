#include <iostream>
#include <cmath> // Include the cmath library for mathematical functions

using namespace std;

// Function prototypes
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);

int main() {
    double num1, num2;
    char operation;

    cout << "Welcome to the Summer Internship Calculator!" << endl;

    while (true) {
        cout << "\nEnter the first number: ";
        cin >> num1;

        cout << "Enter the second number: ";
        cin >> num2;

        cout << "Choose an operation (+, -, *, /, q to quit): ";
        cin >> operation;

        switch (operation) {
            case '+':
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case '-':
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case '*':
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << divide(num1, num2) << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            case 'q':
                cout << "Thank you for using the Summer Internship Calculator. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid operation! Please choose +, -, *, /, or q to quit." << endl;
                break;
        }
    }

    return 0;
}

// Function to perform addition
double add(double x, double y) {
    return x + y;
}

// Function to perform subtraction
double subtract(double x, double y) {
    return x - y;
}

// Function to perform multiplication
double multiply(double x, double y) {
    return x * y;
}

// Function to perform division
double divide(double x, double y) {
    return x / y;
}
