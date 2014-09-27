//
//  creditAccount.h
//  MyBank
//
//  Created by Yimin Du on 24/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#ifndef MyBank_creditAccount_h
#define MyBank_creditAccount_h
#include"account.h"
class CreditAccount : public Account
{
public:
    CreditAccount();
    CreditAccount(double init_balance, double interestRate);
    void setInterestRate(double interestRate);
    double getCreditLimit();
    void setCreditLimit(int creditLimit);
    bool withdraw(double amount);
private:
    double creditLimit;
};



#endif
