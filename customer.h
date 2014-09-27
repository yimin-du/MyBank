//
//  customer.h
//  MyBank
//
//  Created by Yimin Du on 24/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#ifndef MyBank_customer_h
#define MyBank_customer_h

#include<iostream>
#include<vector>
#include"account.h"
#include"bankproduct.h"
class Customer
{
public:
    Customer(std::string firstName, std::string lastName);
    Customer();
    std::string getFirstName();
    std::string getLastName();
    BankProduct* getProduct(int index);
    void addProduct(BankProduct* product);
    int getNumOfProducts();
private:
    std::string firstName;
    std::string lastName;
    std::vector<BankProduct*> products;
    int numOfProducts;
};


#endif
