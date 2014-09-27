//
//  bankproduct.h
//  MyBank
//
//  Created by Yimin Du on 25/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#ifndef MyBank_bankproduct_h
#define MyBank_bankproduct_h
#include<iostream>
class BankProduct
{
public:
    BankProduct();
    BankProduct(std::string pruductType, double interestRate);
    std::string getProductType();
    double getInterestRate();
    virtual bool withdraw(double);
protected:
    std::string productType;
    double interestRate;
};

#endif
