#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateAccountNumber() { 
    srand(time(nullptr));
    string accNumber = "";
    for (int i = 0; i < 11; ++i) {
        accNumber += to_string(rand() % 10);
    }
    return accNumber;
}

int main() {
    string bankName = "A-NULL BANK"; 
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
            case 1: // OPEN ACCOUNT (FAITH MARIE LATINGGA)
                cout << "Enter First Name: ";
                cin >> newfirst;


                cout << "Enter Last Name: ";
                cin >> newlast;


                cout << "Enter Middle Name: ";
                cin >> newmiddle;


                cout << "Enter Address: ";
                cin.ignore();
                getline(cin, newaccountaddress);


                cout << "Enter Birth year: ";
                cin >> newbirthyear;


                if (newbirthyear >= 2005) {
                    cout << "You are not allowed to open an account at A-NULL BANK." << endl;
                    break;
                }


                cout << "Enter Gender (M/F): ";
                cin >> newgender;


                cout << "Enter Account Type (Savings Account [SA] or Current Account [CA]): ";
                cin >> newaccounttype;


                if (newaccounttype == "SA") {
                    newaccountSA = 5000;
                } else if (newaccounttype == "CA") {
                    newaccountCA = 10000;
                } else {
                    cout << "Invalid Account Type. Please choose SA or CA." << endl;
                    break;
                }


                cout << "Enter PIN: ";
                cin >> newaccountpin;


                accountNumber = generateAccountNumber(); 
                accounts.push_back(accountNumber); 


                accountCreated = true; 


                cout <<"\nAccount created successfully! Your account number is: " << accountNumber << endl;
                break;

            case 2: // BALANCE INQUIRY (JOHN ADRIAN GARRUCHA)
                if (accountCreated) 
                {
                    string accountnumberB;
                    bool account=false;

                    cout<<"Please Enter your 11-digit Account Number: ";
                    cin>>accountnumberB;

                    for(const string &acc : accounts) { // this runs the entered account number kung nasa loob ba siya ng vector of accounts na ginawa
                        if (acc == accountnumberB) {
                            account = true;
                            cout<< "Please Enter your 6-digit PIN: ";
                            string accountpin;
                            cin >> accountpin;

                            if (accountpin == newaccountpin) {
                                cout<<"Account Name    : "<<newfirst<<" "<<newmiddle<<" "<<newlast<<endl;
                                cout<<"Account Number  : "<<accountnumberB<<endl;
                                cout<<"Account Balance : "<<currentBalance<<endl;
                            } else {
                                cout<<"Incorrect PIN. Please try again.\n";
                            }
                            break;
            case 3: // DEPOSIT (RAI)
            case 4: // WITHDRAW (CJ)
            case 5: // 
            case 6:
            case 7:
