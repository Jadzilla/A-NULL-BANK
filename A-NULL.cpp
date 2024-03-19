#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateAccountNumber() { // ACCOUNT NUMBER GENERATOR TOHH OKAYYY?? OKAY!!!
    srand(time(nullptr));
    string accNumber = "";
    for (int i = 0; i < 11; ++i) {
        accNumber += to_string(rand() % 10);
    }
    return accNumber;
}

int main() {
    string bankName = "A-NULL BANK"; // OFFICIAL BANK NAME A-NULL WALANG LALABAN 
    cout << bankName << endl;

    string newfirst, newlast, newmiddle, newaccountaddress, newgender, newaccounttype, newaccountpin, accountNumber;
    int newbirthyear, month, day, newaccountSA, newaccountCA;
    double initialDeposit = 0.0, currentBalance = 0.0;

    bool accountCreated = false;
    vector<string> accounts;

    int choice;
    do {
        cout << "\n\nMenu:\n";
        cout << "1. Open a New Account\n";
        cout << "2. Balance Inquiry\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. View Account Information\n";
        cout << "6. Close Account\n";
        cout << "7. Exit Program\n";

        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1: // OPEN ACCOUNT (FAITH MARIE LATINGGA LEADER***)
            case 2: // BALANCE INQUIRY (JOHN ADRIAN GARRUCHA)
            case 3: // DEPOSIT (RAI)
            case 4: // WITHDRAW (CJ)
            case 5: // 
            case 6:
            case 7:
