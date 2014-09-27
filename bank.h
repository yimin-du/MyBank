//
//  bank.h
//  MyBank
//
//  Created by Yimin Du on 24/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#ifndef MyBank_bank_h
#define MyBank_bank_h

#include "customer.h"
#include <vector>
const int invalidInput = 43;
class Bank
{
public:
    Bank();
    void addCustomer(std::string firstName, std::string lastName);
    int getNumOfCustomers();
    Customer& getCustomer(int index);
    Customer& getCustomer(std::string firstName, std::string lastName);

    static Bank& getBank();
    
private:
    std::vector<Customer> customers;
    int numCustomers;
};


#endif
