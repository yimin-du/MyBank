//
//  loan.h
//  MyBank
//
//  Created by Yimin Du on 25/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#ifndef MyBank_loan_h
#define MyBank_loan_h
#include <iostream>
#include "bankproduct.h"
class Loan : public BankProduct
{
public:
    Loan();
    Loan(std::string productType, double loanAmount, int loanTerm, double interestRate);
    double getBalance();
    double getMonthlyRepayment();
    int getNumRepayments();
    void calculateMonthlyRepayment();
    void calculateBalance();
    void makeRepayment();
    bool withdraw(double amount);

protected:
    double loanAmount, monthlyRepayment, balance;
    int loanTerm, numRepayments;
};


#endif
