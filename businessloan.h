//
//  businessloan.h
//  MyBank
//
//  Created by Yimin Du on 25/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#ifndef MyBank_businessloan_h
#define MyBank_businessloan_h
#include "loan.h"
class BusinessLoan : public Loan
{
public:
    BusinessLoan();
    BusinessLoan(double loanAmount, int loanTerm, double interestRate);
    
};

#endif
