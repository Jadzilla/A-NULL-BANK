#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;


string generateAccountNumber() {
    srand(time(nullptr));
    string accountNumber = "";
    for (int i = 0; i < 12; ++i) {
        if ((i + 1) % 5 == 0 && i != 11) {
            accountNumber += "-";
        } else {
            accountNumber += to_string(rand() % 10);
        }
    }
    return accountNumber;
}

int deposit(int myBalance, int amount) {
    return (myBalance += amount);
}


bool Confirmation() {
    string input;
    cout << "Do you want to proceed with the deposit? [y/n]: ";
    cin >> input;
    return input == "y";
}


int getValidAmount(int min, int maxRetries) {
    int amount;
    int retries = 0;
    do {
        cout << "Enter Amount to Deposit (min. " << min << "): ";
        cin >> amount;


        if (amount <= min) {
            cout << "[Deposit] Invalid amount. Minimum deposit is " << min << endl;
        } else if (amount < 0) {
            cout << "[Deposit] Invalid amount. Amount must be a positive value" << endl;
        } else {
            break;
        }
        retries++;
        cout << "[Retry: " << retries << "/3]\n";
    } while (retries < maxRetries);


    if (retries == maxRetries) {
        cout << "Exceeded the maximum number of retries. Transaction cancelled." << endl;
        return -1;
    }
    return amount;
}


int main() {
    string bankName = "WELCOME TO A-NULL BANK";
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

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout<<"Invalid input. Please enter a number between 1 and 7 ONLY."<<endl;
            continue;
        }

        switch (choice) {
            case 1:
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

                if (newgender != "M" && newgender != "F") {
                    cout<<"Invalid gender. Please enter 'M' for Male or 'F' for Female."<<endl;
                    break;
                    }
                
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

                if (newaccountpin.length() != 6) {
                        cout << "Invalid PIN length. Please enter a 6-digit PIN." << endl;
                        break;
                    } else {

                accountNumber = generateAccountNumber();
                accounts.push_back(accountNumber);
           
                accountCreated = true;  


                cout <<"\nAccount created successfully!\n"<<"Your account number is: " << accountNumber << endl;
                    }
                break;


            case 2:
                if (accountCreated)
                {
                    string accountnumberB;
                    bool account = false;

                    cout<<"<---------------------------------------------------------------------------->"<<endl;
                    cout<<"Please Enter your 10-digit Account Number: ";
                    cin>>accountnumberB;


                    for(const string &acc : accounts)
                    {
                        if (acc == accountnumberB)
                        {
                            account = true;
                            cout<<"<---------------------------------------------------------------------------->"<<endl;
                            cout<< "Please Enter your PIN: ";
                            string accountpin;
                            cin >> accountpin;


                            if (accountpin == newaccountpin) 
                            {
                                cout<<"<---------------------------------------------------------------------------->"<<endl;

                                cout<<"Account Name    : "<<newfirst<<" "<<newmiddle<<" "<<newlast<<endl;
                                cout<<"Account Number  : "<<accountnumberB<<endl;
                                cout<<"Account Balance : "<<currentBalance<<endl;
                            } else {
                                cout<<"Incorrect PIN. Please try again."<<endl;
                            }
                            break;
                        }
                    }


                    if (!account)
                    {
                        cout << "Invalid Account Number. Please try again.\n";
                    }
                } else
                {
                    cout << "No account found. Please open an account first." << endl;
                }
                break;


            case 3:
    if (accountCreated) {
        string accountType;
        int myBalance;
        int Amount;
        int min;
        int retries=3;
        string accountnumberB;
        bool account = false;

        cout << "<---------------------------------------------------------------------------->" << endl;
        cout << "Please Enter your 10-digit Account Number: ";
        cin >> accountnumberB;

        for (const string &acc : accounts) {
            if (acc == accountnumberB) {
                account = true;
                cout << "<---------------------------------------------------------------------------->" << endl;
                cout << "Please Enter your PIN: ";
                string accountpin;
                cin >> accountpin;

                if (accountpin == newaccountpin) {
                    cout << "<---------------------------------------------------------------------------->" << endl;
                    cout << "Enter Account Type (Savings Account [SA] or Current Account [CA]): ";
                    cin >> accountType;

                    if ((accountType == "SA" && newaccounttype == "SA") || (accountType == "CA" && newaccounttype == "CA")) {
                        if (accountType == "SA") {
                            myBalance = currentBalance;
                            min = 300;
                        } else if (accountType == "CA") {
                            myBalance = currentBalance;
                            min = 500;
                        }

                        do {
                            Amount = getValidAmount(min, retries);
                            if (Amount <= 0) {
                                break;
                            }
                            if (Confirmation()) {
                                currentBalance = deposit(myBalance, Amount);
                                cout << "<---------------------------------------------------------------------------->" << endl;
                                cout << "Transaction successful. Current balance: " << currentBalance << endl;
                                break;
                            } else {
                                cout << "<---------------------------------------------------------------------------->" << endl;
                                cout << "Transaction Cancelled" << endl;
                                break;
                            }
                        } while (true);
                    } else {
                        cout << "<---------------------------------------------------------------------------->" << endl;
                        cout << "Invalid Account type!!." << endl;
                    }
                } else {
                    cout << "<---------------------------------------------------------------------------->" << endl;
                    cout << "Incorrect PIN. Please try again." << endl;
                }
                break;
            }
        }

        if (!account) {
            cout << "<---------------------------------------------------------------------------->" << endl;
            cout << "Invalid Account Number. Please try again." << endl;
        }
    } else {
        cout << "<---------------------------------------------------------------------------->" << endl;
        cout << "No account found. Please open an account first." << endl;
    }
    break;

case 4:
    if (accountCreated) {
        string accountType, accountnumberB;
        double myBalance;
        double Amount;
        int min;
        bool account = false;

        cout << "<---------------------------------------------------------------------------->" << endl;
        cout << "Please Enter your 10-digit Account Number: ";
        cin >> accountnumberB;

        for (const string &acc : accounts) {
            if (acc == accountnumberB) {
                account = true;
                cout << "<---------------------------------------------------------------------------->" << endl;
                cout << "Please Enter your PIN: ";
                string accountpin;
                cin >> accountpin;

                if (accountpin == newaccountpin) {
                    cout << "<---------------------------------------------------------------------------->" << endl;
                    cout << "Enter Account Type (Savings Account [SA] or Current Account [CA]): ";
                    cin >> accountType;

                    if ((accountType == "SA" && newaccounttype == "SA") || (accountType == "CA" && newaccounttype == "CA")) {
                        if (accountType == "SA") {
                            myBalance = currentBalance;
                            min = 300;
                        } else if (accountType == "CA") {
                            myBalance = currentBalance;
                            min = 500;
                        }

                        cout << "<---------------------------------------------------------------------------->" << endl;
                        cout << "Enter the amount you want to withdraw (Minimum: " << min << "): ";
                        cin >> Amount;

                        while (Amount <= 0 && Amount < min) {
                            cout << "<---------------------------------------------------------------------------->" << endl;
                            cout << "\nInvalid Input, please enter the right amount you wish to withdraw (Minimum: " << min << "): ";
                            cin >> Amount;
                        }

                        if (Amount < 0) {
                            cout << "<---------------------------------------------------------------------------->" << endl;
                            cout << "\nAmount can't be negative, Transaction has been cancelled." << endl;
                        } else if (Amount > currentBalance) {
                            cout << "<---------------------------------------------------------------------------->" << endl;
                            cout << "\nInsufficient Balance, Transaction has been cancelled." << endl;
                        } else {
                            cout << "<---------------------------------------------------------------------------->" << endl;
                            cout << "\nTransaction successful." << endl;
                            currentBalance = (myBalance - Amount);
                            cout << "<---------------------------------------------------------------------------->" << endl;
                            cout << "Remaining balance: " << currentBalance << endl;
                            cout << "<---------------------------------------------------------------------------->" << endl;
                        }
                    } else {
                        cout << "<---------------------------------------------------------------------------->" << endl;
                        cout << "Invalid Account type!!." << endl;
                    }
                } else {
                    cout << "<---------------------------------------------------------------------------->" << endl;
                    cout << "Incorrect PIN. Please try again." << endl;
                }
                break;
            }
        }

        if (!account) {
            cout << "<---------------------------------------------------------------------------->" << endl;
            cout << "Invalid Account Number. Please try again." << endl;
        }
    } else {
        cout << "<---------------------------------------------------------------------------->" << endl;
        cout << "No account found. Please open an account first." << endl;
    }
    break;
            case 5:
                 if (accountCreated) 
                {
                    string accountnumberI;
                    bool account = false;

                    cout<<"<---------------------------------------------------------------------------->"<<endl;
                    cout<<"Please Enter your 10-digit Account Number: ";
                    cin>>accountnumberI;
                    cout << "Account Information:\n";
                    cout << "Account Holder: " << newfirst << " " << newmiddle << " " << newlast << endl;
                    cout << "Birthyear: "<<newbirthyear<<endl;
                    cout << "Gender: "<<newgender<<endl;
                    cout << "Account Number: " << accountNumber << endl;
                    cout << "Account type: "<<newaccounttype<<endl;
                    cout << "Current Balance: " << currentBalance << endl;
                } 
                else    {
                        cout << "No account found. Please open an account first." << endl;
                        }
    break;
                   
                
            case 6: 
                if (accountCreated) {
                string accountNumberToClose;
                bool accountFound = false;


                cout << "Enter your 10-digit Account Number: ";
                cin >> accountNumberToClose;

                for (auto it = accounts.begin(); it != accounts.end(); ++it) {
                if (*it == accountNumberToClose) {
                      accountFound = true;
                      cout << "Enter your PIN: ";
                      string enteredPIN;
                      cin >> enteredPIN;


                if (enteredPIN == newaccountpin) {
                    accounts.erase(it);
                    accountCreated = false;
                    cout << "Account closed successfully." << endl;
                } else {
                    cout << "Incorrect PIN. Account closure failed." << endl;
                }
                break;
            }
        }


               if (!accountFound) {
                   cout << "Account not found. Unable to close account." << endl;
        }
               } else {
                   cout << "No account found. Please open an account first." << endl;
    }
                break;


            case 7:
            
                cout << "Exiting program. Thank you for using A-NULL BANK." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;

            
        };
    }while (choice != 7);
    
    

return 0;
}
