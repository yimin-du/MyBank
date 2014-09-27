//
//  bank.cpp
//  MyBank
//
//  Created by Yimin Du on 24/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#include "bank.h"
#include <iostream>
#include <string>
using namespace std;
const int CUSTOMER_NOT_FOUND = -1;

Bank::Bank()
{
    numCustomers = 0;
}

Bank& Bank::getBank()
{
    static Bank bank;
    return bank;
}
void Bank::addCustomer(std::string firstName, std::string lastName)
{
    Customer newCustomer(firstName, lastName);
    customers.push_back(newCustomer);
    numCustomers++;
}
int Bank::getNumOfCustomers()
{
    return numCustomers;
}
Customer& Bank::getCustomer(int index)
{
    
    if(index >= numCustomers || index < 0){
        throw invalidInput;
    }
    else
        return customers.at(index);
}
Customer& Bank::getCustomer(string firstName, string lastName)
{
    for(int i = 0; i < customers.size(); i++){
        if(firstName == customers.at(i).getFirstName()
           && lastName == customers.at(i).getLastName()){
            return customers.at(i);
        }
    }
    throw CUSTOMER_NOT_FOUND;
}


