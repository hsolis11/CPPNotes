/**************************************
 * Name: Hector Solis
 * Coding 02
 * Purpose: Program will be a simple toy banking system
 * using classes and inheritance
 **************************************/

#include "savings_account.h"

Savings_Account::Savings_Account(std::string customer_name, double initial_deposit): Account(customer_name, initial_deposit) {

}

void Savings_Account::withdraw(double amount) {

    if (amount < get_balance() && amount > 0) {
        Account::withdraw(amount);
    } else {
        throw amount;
    }
}

void Savings_Account::display_account_details() {
    Account::display_account_details();
    cout << "Interest Rate: " << get_interest_rate() << endl;
}

double Savings_Account::get_interest_rate() {
    return interest_rate;
}