#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void calculateSavingsPlan() {
    string savingsGoal;
    double currentSavings, targetSavings, yearsToSave;

    // รับข้อมูลจากผู้ใช้
    cout << "Enter your savings goal (e.g., buying a car, buying a house): ";
    getline(cin, savingsGoal);

    // ตรวจสอบและรับค่าเงินออมปัจจุบัน
    do {
        cout << "Enter your current savings (Baht): ";
        cin >> currentSavings;
        if (!cin) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (currentSavings < 0);

    // ตรวจสอบและรับค่าเงินออมเป้าหมาย
    do {
        cout << "Enter your target savings (Baht): ";
        cin >> targetSavings;
        if (!cin || targetSavings <= currentSavings) {
            cout << "Invalid input. Target savings must be greater than current savings.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (targetSavings <= currentSavings);

    // ตรวจสอบและรับจำนวนปี
    do {
        cout << "Enter the number of years you plan to save: ";
        cin >> yearsToSave;
        if (!cin || yearsToSave <= 0) {
            cout << "Invalid input. Please enter a positive number for years.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (yearsToSave <= 0);

    // คำนวณ
    double amountToSave = targetSavings - currentSavings;
    double yearlySaving = amountToSave / yearsToSave;
    double monthlySaving = yearlySaving / 12;

    // แสดงผลลัพธ์ในรูปแบบตาราง
    cout << "\nSavings Plan Summary\n";
    cout << "---------------------------------------------------------\n";
    cout << setw(25) << left << "Savings Goal:" << setw(15) << right << savingsGoal << endl;
    cout << setw(25) << left << "Total Amount to Save:" << setw(15) << right << fixed << setprecision(2) << amountToSave << " Baht" << endl;
    cout << setw(25) << left << "Yearly Savings Required:" << setw(15) << right << yearlySaving << " Baht" << endl;
    cout << setw(25) << left << "Monthly Savings Required:" << setw(15) << right << monthlySaving << " Baht" << endl;
    cout << "---------------------------------------------------------\n";
}

int main() {
    int choice;
    do {
        calculateSavingsPlan();
        cout << "\nEnter 1 to exit, or any other key to continue: ";
        cin >> choice;
    } while (choice != 1);

    return 0;
}