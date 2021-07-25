/**************************************
 * Name: Hector Solis
 * Coding 02
 * Purpose: Program will be a simple toy banking system
 * using classes and inheritance
 **************************************/

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "account.h"

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;


class Savings_Account: public Account {
public:
    Savings_Account(string, double);
    void withdraw(double);

    double get_interest_rate();

    void display_account_details();

private:
    double interest_rate = 0.003;
};


#endif // SAVINGS_ACCOUNT_H
