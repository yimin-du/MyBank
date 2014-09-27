//
//  account.cpp
//  MyBank
//
//  Created by Yimin Du on 24/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#include "account.h"
#include <iostream>
using namespace std;

Account::Account(){}

Account::Account(string productType, double init_balance, double interestRate) : BankProduct(productType, interestRate)
{
    balance = init_balance;
}
double Account::getBalance()
{
    return balance;
}
bool Account::deposit(double amount)
{
    balance += amount;
    return true;
}
bool Account::withdraw(double amount)
{
    if(amount <= balance){
        balance -= amount;
        return true;
    }
    return false;
}
