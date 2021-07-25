/**************************************
 * Name: Hector Solis
 * Coding 02
 * Purpose: Program will be a simple toy banking system
 * using classes and inheritance
 **************************************/

#include "main.h"

int main(int argc, char** argv) {

    Savings_Account savingsAccount("Hector Solis", 100);
    cout << "Initial savings account details" << endl;
    savingsAccount.display_account_details();

    cout << endl;
    cout << "Deposit 100 -> balance = 200" << endl;
    savingsAccount.deposit(100);
    savingsAccount.display_account_details();

    cout << endl;
    cout << "Attempt to deposit -100" << endl;
    try {
        savingsAccount.deposit(-100);
    } catch (double amount) {
        cout << "Invalid amount: Only values more than zero." << endl;
    }
    savingsAccount.display_account_details();

    cout << endl;
    cout << "Withdraw 100 -> balance = 100" << endl;
    savingsAccount.withdraw(100);
    savingsAccount.display_account_details();

    cout << endl;
    cout << "Attempt to withdraw more than balance" << endl;
    try {
        savingsAccount.withdraw(-110);
    } catch (double amount) {
        cout << "Insufficient funds or invalid amount: Unable to withdraw " << amount << endl;
    }
    savingsAccount.display_account_details();

    cout << endl;
    cout << "Change customer name from Hector Solis to John Doe" << endl;
    savingsAccount.set_name("John Doe");
    savingsAccount.display_account_details();

    cout << endl;
    cout << "Attempt to change customer name from John Doe to empty string" << endl;
    try {
        savingsAccount.set_name("");
    } catch (string name) {
        cout << "Name '" << name << "' is invalid" << endl;
    }

    savingsAccount.display_account_details();


    return 0;
}