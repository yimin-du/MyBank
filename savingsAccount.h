//
//  savingsAccount.h
//  MyBank
//
//  Created by Yimin Du on 24/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#ifndef MyBank_savingsAccount_h
#define MyBank_savingsAccount_h
#include"account.h"
#include <iostream>
using namespace std;
class SavingsAccount : public Account
{
public:
    SavingsAccount();
    SavingsAccount(double init_balance, double interestRate);
    void setInterestRate(double interestRate);
};


#endif
