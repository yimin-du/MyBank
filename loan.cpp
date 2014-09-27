//
//  loan.cpp
//  MyBank
//
//  Created by Yimin Du on 25/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#include "loan.h"
#include "bankproduct.h"
#include <math.h>
#include <iostream>
using namespace std;

Loan::Loan() { }
Loan::Loan(std::string productType, double loanAmount, int loanTerm, double interestRate) : BankProduct(productType, interestRate)
{
    this->loanAmount = loanAmount;
    this->loanTerm = loanTerm;
    this->interestRate = interestRate;
    numRepayments = 0;
    balance = loanAmount;
    calculateMonthlyRepayment();
}
double Loan::getBalance()
{
    return balance;
}
double Loan::getMonthlyRepayment()
{
    return monthlyRepayment;
}
int Loan::getNumRepayments()
{
    return numRepayments;
}
void Loan::calculateMonthlyRepayment()
{
    double mRate = interestRate / 12.0;
    double numMonth = loanTerm * 12;
    monthlyRepayment = loanAmount * ((mRate * pow(1.0 + mRate, numMonth)) /
                                     (pow(1.0 + mRate, numMonth) - 1));
}
void Loan::calculateBalance()
{
    double mRate = interestRate / 12;
    balance = loanAmount * pow((1 + mRate / 12), numRepayments) - (monthlyRepayment / mRate * (pow(1 + mRate, numRepayments) - 1));

}
void Loan::makeRepayment()
{
    numRepayments++;
    calculateBalance();
    cout << "You have made " << numRepayments << " payments for your " << this->getProductType() << "." << endl;
}
bool Loan::withdraw(double amount)
{
    if(amount < monthlyRepayment * numRepayments){
        loanAmount += amount;
        balance += amount;
        calculateMonthlyRepayment();
        return true;
    }
    else{
        return false;
    }
    
}