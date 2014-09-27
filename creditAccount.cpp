//
//  creditAccount.cpp
//  MyBank
//
//  Created by Yimin Du on 24/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#include "creditAccount.h"
#include <iostream>
using namespace std;

const double DEFAULT_CREDIT_LIMIT = 1000;
CreditAccount::CreditAccount(){}

CreditAccount::CreditAccount(double init_balance, double interestRate) :
               Account("Credit Account", init_balance, interestRate)
{
    creditLimit = DEFAULT_CREDIT_LIMIT;
}
double CreditAccount::getCreditLimit()
{
    return creditLimit;
}
void CreditAccount::setCreditLimit(int creditLimit)
{
    this->creditLimit = creditLimit;
}
bool CreditAccount::withdraw(double amount)
{
    if(amount <= balance){
        balance -= amount;
        return true;
    }
    else if(amount <= balance + creditLimit){
        creditLimit -= amount - balance;
        balance = 0;
        return true;
    }
    else{
        return false;
    }
        
}