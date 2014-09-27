//
//  account.h
//  MyBank
//
//  Created by Yimin Du on 24/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#ifndef MyBank_account_h
#define MyBank_account_h

#include"bankproduct.h"
class Account : public BankProduct
{
public:
    Account();
    Account(std::string productType, double init_balance, double interestRate);
    double getBalance();
    bool deposit(double amount);
    virtual bool withdraw(double amount);
protected:
    double balance;
};


#endif
