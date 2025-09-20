#include <iostream>
#include <iomanip>

using namespace std;

void calculateRetirementSavings() {
    int currentAge, retirementAge, lifespanAge;
    double monthlyExpense, totalSavingsNeeded, monthlySavings;

    // รับข้อมูลจากผู้ใช้
    cout << "Please enter your current age: ";  //อายุปัจจุบัน
    cin >> currentAge;

    cout << "Please enter your desired retirement age: "; //อายุที่จะเกษียน
    cin >> retirementAge;

    cout << "Please enter your expected lifespan: "; //คาดเดาอายุไข
    cin >> lifespanAge;

    cout << "Please enter your estimated monthly expenses after retirement (Baht): "; //เงินที่อยากจะใช้หลังเกษียณ ต่อเดือน
    cin >> monthlyExpense;

    // ตรวจสอบความถูกต้องของข้อมูล
    if (retirementAge <= currentAge) {
        cout << "Retirement age must be greater than current age.\n";  //อายุเกษียณจะต้องมากกว่าอายุปัจจุบัน
        return;
    }
    if (lifespanAge <= retirementAge) {
        cout << "Lifespan must be greater than retirement age.\n"; //อายุขัยต้องมากกว่าอายุเกษียณ
        return;
    }
    if (monthlyExpense <= 0) {
        cout << "Monthly expenses must be greater than 0.\n";  //รายจ่ายรายเดือนต้องมากกว่า 0.
        return;
    }

    // คำนวณ
    int yearsToRetirement = retirementAge - currentAge;
    int monthsToRetirement = yearsToRetirement * 12;
    int yearsAfterRetirement = lifespanAge - retirementAge;
    int monthsAfterRetirement = yearsAfterRetirement * 12;

    totalSavingsNeeded = monthlyExpense * monthsAfterRetirement;
    monthlySavings = totalSavingsNeeded / monthsToRetirement;

    // แสดงผลลัพธ์ในรูปแบบตาราง
    cout << "\nRetirement Savings Plan\n";
    cout << "---------------------------------------------------------\n";
    cout << setw(30) << left << "Years until retirement:" << setw(15) << right << yearsToRetirement << endl;  //จำนวนปีจนถึงเกษียณ:
    cout << setw(30) << left << "Years after retirement:" << setw(15) << right << yearsAfterRetirement << endl;  //จำนวนปีหลังเกษียณอายุ:
    cout << setw(30) << left << "Total savings needed:" << setw(15) << right << fixed << setprecision(2) << totalSavingsNeeded << " Baht" << endl; //รวมเงินออมที่ต้องออม:
    cout << setw(30) << left << "Monthly savings required:" << setw(15) << right << monthlySavings << " Baht" << endl; //เงินออมที่ต้องออมต่อเดือน:
    cout << "---------------------------------------------------------\n";
}

int main() {
    int choice;
    do {
        calculateRetirementSavings();
        cout << "\nEnter 1 to exit, or any other key to continue: ";
        cin >> choice;
    } while (choice != 1);

    return 0;
}