//
//  savingsAccount.cpp
//  MyBank
//
//  Created by Yimin Du on 24/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#include "savingsAccount.h"

SavingsAccount::SavingsAccount(){}
SavingsAccount::SavingsAccount(double init_balance, double interestRate) :
                Account("Savings Account", init_balance, interestRate) { }
void SavingsAccount::setInterestRate(double interestRate)
{
    this->interestRate = interestRate;
}