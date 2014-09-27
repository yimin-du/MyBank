//
//  businessloan.cpp
//  MyBank
//
//  Created by Yimin Du on 25/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#include "businessloan.h"

BusinessLoan::BusinessLoan(){}
BusinessLoan::BusinessLoan(double loanAmount, int loanTerm, double interestRate) : Loan("Business Loan", loanAmount, loanTerm, interestRate)
{ }
