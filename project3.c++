#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double initialPrincipal, monthlySavings, annualInterestRate;
    int years;
    cout << "===========================================\n";
    cout << "Enter initial principal amount: ";
    cin >> initialPrincipal;
    cout << "Enter monthly saving amount: ";
    cin >> monthlySavings;
    cout << "Enter annual interest rate (%): ";
    cin >> annualInterestRate;
    cout << "Enter number of years: ";
    cin >> years;

    double monthlyInterestRate = annualInterestRate / 100 / 12;

    cout << fixed << setprecision(2);
    cout << "===========================================\n";
    cout << "Year\t\tFuture Value\n";
    cout << "-------------------------------------------\n";

    double futureValue = initialPrincipal;
    for (int year = 1; year <= years; ++year) {
        for (int month = 1; month <= 12; ++month) {
            futureValue = futureValue * (1 + monthlyInterestRate) + monthlySavings;
        }
        cout << year << "\t\t" << futureValue << endl;
    }
    cout << "-------------------------------------------";
    cout << "\nFinal value after " << years << " years: " << futureValue << endl;
    cout << "===========================================\n";

    return 0;
}