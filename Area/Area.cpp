#include "Area.h"
#include <iostream>
#include <iomanip>
using namespace std;
void displayFunctionTypes();
void testDifferentFunctions();
void testPolynomialIntegration();
void demonstrateConstructors();
void compareIntervals();
void interactiveMode();


void displayFunctionTypes() {
    cout << "\nAvailable Function Types:" << endl;
    cout << "1. f(x) = x²" << endl;
    cout << "2. f(x) = sin(x)" << endl;
    cout << "3. f(x) = e^x" << endl;
    cout << "4. f(x) = 1/(1+x)" << endl;
    cout << "5. f(x) = sqrt(x)" << endl;
    cout << "6. f(x) = x³" << endl;
    cout << "7. f(x) = cos(x)" << endl;
    cout << "8. f(x) = ln(x)" << endl;
    cout << "9. f(x) = e^(x²)" << endl;
}

void testDifferentFunctions() {
    cout << "\n=== Testing Different Function Types ===" << endl;
    Area calculator(0, 2, 100);
    for(int funcType = 1; funcType <= 9; funcType++) {
        double result = calculator.areaTrapeze(0, 2, 100, funcType);
        cout << "Function type " << funcType << ": Area = " << fixed << setprecision(6) << result << endl;
    }
}

void testPolynomialIntegration() {
    cout << "\n=== Testing Polynomial Integration ===" << endl;
    Area calculator;
    double coefficients[] = {1.0, 3.0, 2.0};
    int degree = 2;
    double result = calculator.areaTrapeze(0, 2, 100, coefficients, degree);
    cout << "Polynomial 2x² + 3x + 1 from 0 to 2: Area = " << fixed << setprecision(6) << result << endl;
    double coefficients2[] = {5.0, -2.0, 0.0, 1.0};
    int degree2 = 3;
    result = calculator.areaTrapeze(0, 3, 200, coefficients2, degree2);
    cout << "Polynomial x³ - 2x + 5 from 0 to 3: Area = " << fixed << setprecision(6) << result << endl;
}

void demonstrateConstructors() {
    cout << "\n=== Demonstrating Constructor Usage ===" << endl;
    Area calc1(1, 3, 50, 2);
    double result1 = calc1.areaTrapeze(1, 3, 50);
    cout << "Constructor with parameters (sin(x), 1 to 3): Area = " << fixed << setprecision(6) << result1 << endl;
    Area calc2;
    calc2.setFunctionType(3);
    double result2 = calc2.areaTrapeze(0, 1, 100);
    cout << "Default constructor + setFunctionType (e^x, 0 to 1): Area = " << fixed << setprecision(6) << result2 << endl;
}

void compareIntervals() {
    cout << "\n=== Comparing Different Interval Counts ===" << endl;
    Area calculator;
    int intervals[] = {10, 50, 100, 500, 1000};
    cout << "Function: x² from 0 to 2" << endl;
    cout << "Intervals\tApproximation\tError*" << endl;
    cout << "----------------------------------------" << endl;
    double exact = 8.0/3.0;
    for(int i = 0; i < 5; i++) {
        double result = calculator.areaTrapeze(0, 2, intervals[i], 1);
        double error = abs(result - exact);
        cout << intervals[i] << "\t\t" << fixed << setprecision(6) << result << "\t\t" << error << endl;
    }
    cout << "*Error compared to exact value: " << exact << endl;
}

void interactiveMode() {
    cout << "\n=== Interactive Mode ===" << endl;
    Area calculator;
    int choice;
    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Calculate area with built-in functions" << endl;
        cout << "2. Calculate area with polynomial" << endl;
        cout << "3. Display function types" << endl;
        cout << "0. Exit interactive mode" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                int a, b, n, funcType;
                cout << "Enter lower bound (a): ";
                cin >> a;
                cout << "Enter upper bound (b): ";
                cin >> b;
                cout << "Enter number of intervals (n): ";
                cin >> n;
                displayFunctionTypes();
                cout << "Enter function type (1-9): ";
                cin >> funcType;
                double result = calculator.areaTrapeze(a, b, n, funcType);
                cout << "Result: " << fixed << setprecision(6) << result << endl;
                break;
            }
            case 2: {
                int a, b, n, degree;
                cout << "Enter lower bound (a): ";
                cin >> a;
                cout << "Enter upper bound (b): ";
                cin >> b;
                cout << "Enter number of intervals (n): ";
                cin >> n;
                cout << "Enter polynomial degree: ";
                cin >> degree;

                double* coefficients = new double[degree + 1];
                cout << "Enter coefficients (constant term first): ";
                for(int i = 0; i <= degree; i++) {
                    cin >> coefficients[i];
                }

                double result = calculator.areaTrapeze(a, b, n, coefficients, degree);
                cout << "Result: " << fixed << setprecision(6) << result << endl;

                delete[] coefficients;
                break;
            }
            case 3:
                displayFunctionTypes();
                break;
            case 0:
                cout << "Exiting interactive mode..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 0);
}

int main() {
    cout << "=== Area Calculator Using Trapezoidal Rule ===" << endl;
    cout << "This program demonstrates the usage of the Area class." << endl;
    testDifferentFunctions();
    testPolynomialIntegration();
    demonstrateConstructors();
    compareIntervals();
    char runInteractive;
    cout << "\nWould you like to run interactive mode? (y/n): ";
    cin >> runInteractive;
    if(runInteractive == 'y' || runInteractive == 'Y') {
        interactiveMode();
    }
    cout << "\nProgram completed successfully!" << endl;
    return 0;
}