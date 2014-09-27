//
//  homeloan.h
//  MyBank
//
//  Created by Yimin Du on 25/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#ifndef MyBank_homeloan_h
#define MyBank_homeloan_h
#include "loan.h"

class HomeLoan : public Loan
{
public:
    HomeLoan();
    HomeLoan(double loanAmount, int loanTerm, double interestRate, bool firstHomeBuyer);
    bool isFirstHomeBuyer();
    double getFirstHomeBuyerGrant();
private:
    double firstHomeBuyerGrant;
    bool firstHomeBuyer;
    
};

#endif
