#include <iostream>
#include <string>
using namespace std;
class Bank {
private:
    string name;
    long long accnumber;
    string type;
    long long balance;
    int pin;                        // Variable to store the PIN
    int failedAttempts;
    bool isLocked;

public:
    // Constructor to initialize balance, pin, failedAttempts, and isLocked
    Bank() : balance(0), pin(0), failedAttempts(0), isLocked(false) {}

    // Function to set the person's data
    void setvalue() {
        cout << "Enter name: ";
       
        getline(cin, name);                         // Read the full name including spaces
        cout << "Enter Account number: ";
        cin >> accnumber;

        cout << "Enter Account type: ";
        cin.ignore();  // Clear newline character before reading string
        getline(cin, type);  // Read the account type

        cout << "Enter Initial Balance: ";
        cin >> balance;

        cout << "Set your PIN (4 digits): ";
        cin >> pin;
    }
    // Function to verify the PIN
    bool verifyPin(int enteredPin) {
        if (isLocked) {
            cout << "Account is locked due to multiple failed PIN attempts.\n";
            return false;
        }
        if (enteredPin == pin) {
            failedAttempts = 0;  // Reset failed attempts on successful login
            return true;
        } else {
            failedAttempts++;
            if (failedAttempts >= 3) {
                isLocked = true;
                cout << "Account is locked due to multiple failed PIN attempts.\n";
            } else {
                cout << "Invalid PIN. Attempts left: " << (3 - failedAttempts) << endl;
            }
            return false;
        }
    }

    // Function to get the user's name
    string getName() const {
        return name;
    }

    // Function to change the PIN
    void changePin() {
        if (isLocked) {
            cout << "Account is locked. Cannot change PIN.\n";
            return;
        }
        int currentPin, newPin;
        cout << "Enter your current PIN: ";
        cin >> currentPin;
        if (verifyPin(currentPin)) {
            cout << "Enter your new PIN (4 digits): ";
            cin >> newPin;
            pin = newPin;
            cout << "PIN changed successfully.\n";
        } else {
            cout << "Invalid current PIN.\n";
        }
    }
    // Function to display the required data
    void showdata() const {
        cout << "Name: " << name << endl;
        cout << "Account No: " << accnumber << endl;
        cout << "Account type: " << type << endl;
        cout << "Balance: " << balance << endl;
    }
    // Function to withdraw the amount from ATM
    void withdrawl() {
        long long amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient funds.\n";
        } else {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
    }
    // Function to show the balance amount
    void showbal() const {
        cout << "Total balance is: " << balance << endl;
    }
};
// Driver Code
int main() {
    Bank b;
    int choice;
    int enteredPin;
    // Ensure user enters account details before accessing main operations
    cout << "Please set up your account details.\n";
    b.setvalue();
    // Display a welcome message with user's name
    cout << "\n             Welcome, " << b.getName() << "!\n";
    // Prompt the user to enter their PIN to access the main menu
    cout << "Enter your PIN to access your account: ";
    cin >> enteredPin;
    // Verify PIN before accessing the main menu
    if (!b.verifyPin(enteredPin)) {
        return 1;
    }
    while (true) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~WELCOME~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~\n\n";
        cout << "Enter Your Choice\n";
        cout << "\t1. Balance Enquiry\n";
        cout << "\t2. Show Total Balance\n";
        cout << "\t3. Withdraw Money\n";
        cout << "\t4. Change PIN\n";
        cout << "\t5. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1:
            b.showdata();
            break;
        case 2:
            b.showbal();
            break;
        case 3:
            b.withdrawl();
            break;
        case 4:
            b.changePin();
            break;
        case 5:
            cout << "Exiting... Thank You\n";
            return 0;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }
