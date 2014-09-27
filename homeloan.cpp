//
//  homeloan.cpp
//  MyBank
//
//  Created by Yimin Du on 25/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#include "homeloan.h"
const double FIRST_HOME_GRANT = 5000;
HomeLoan::HomeLoan(){}
HomeLoan::HomeLoan(double loanAmount, int loanTerm, double interestRate, bool firstHomeBuyer) : Loan("Home Loan", loanAmount, loanTerm, interestRate)
{
    this->firstHomeBuyer = firstHomeBuyer;
    if(firstHomeBuyer)
        firstHomeBuyerGrant = FIRST_HOME_GRANT;
        loanAmount -= firstHomeBuyerGrant;
}

bool HomeLoan::isFirstHomeBuyer(){
    return firstHomeBuyer;
}
double HomeLoan::getFirstHomeBuyerGrant(){
    return firstHomeBuyerGrant;
}
