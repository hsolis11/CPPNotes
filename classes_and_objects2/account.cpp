/**************************************
 * Name: Hector Solis
 * Coding 02
 * Purpose: Program will be a simple toy banking system
 * using classes and inheritance
 **************************************/

#include "account.h"

Account::Account(string name, double initial_deposit) {
    srand(time(NULL));

    set_name(name);
    deposit(initial_deposit);
    set_account_number();
}

Account::~Account() {
}

void Account::deposit(double amount) {

    if (amount > 0) {
        account_balance += amount;
    } else {
        throw amount;
    }
}

void Account::set_name(string name) {
    if (name != "") {
        customer_name = name;
    } else {
        throw name;
    }

}

void Account::set_account_number() {

    if(account_not_created){
        account_number = rand() % 10000;
        account_not_created = false;
    }
}

void Account::withdraw(double amount) {
    account_balance -= amount;
}

void Account::display_account_details() {
    cout << "customer name: " << get_customer_name() << endl;
    cout << "account: " << get_account_number() << endl;
    cout << "balance: " << get_balance() << endl;
}

double Account::get_balance() {
    return account_balance;
}

double Account::get_account_number() {
    return account_number;
}

string Account::get_customer_name() {
    return customer_name;
}