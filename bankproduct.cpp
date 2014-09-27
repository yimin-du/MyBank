//
//  bankproduct.cpp
//  MyBank
//
//  Created by Yimin Du on 25/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#include "bankproduct.h"
#include <iostream>

BankProduct::BankProduct(){ }
BankProduct::BankProduct(std::string productType, double interestRate)
{
    this->productType = productType;
    this->interestRate = interestRate;
}

bool BankProduct::withdraw(double amount){return true;}
double BankProduct::getInterestRate()
{
    return interestRate;
}

std::string BankProduct::getProductType()
{
    return productType;
}
