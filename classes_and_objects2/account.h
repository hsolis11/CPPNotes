/**************************************
 * Name: Hector Solis
 * Coding 02
 * Purpose: Program will be a simple toy banking system
 * using classes and inheritance
 **************************************/

#ifndef ACCOUNT_H
#define ACCOUNT_H

// Account - balance, deposit, withdraw
// Savings Account - balance, deposit, withdraw, interest rate,
// Checking Account - balance, deposit, withdraw, minimum balance, per check fee

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;
using std::string;

class Account {

public:
    Account(std::string, double);
    ~Account();
    void deposit(double);
    void withdraw(double);
    void set_name(std::string);

    double get_balance();
    double get_account_number();
    string get_customer_name();

    void display_account_details();






private:
    string customer_name;
    int account_number;
    double account_balance;
    bool account_not_created = true;

    void set_account_number();
};


#endif //ACCOUNT_H
