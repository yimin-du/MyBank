//
//  customer.cpp
//  MyBank
//
//  Created by Yimin Du on 24/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#include "customer.h"
#include<string>
using namespace std;

Customer::Customer()
{ }
Customer::Customer(string firstName, string lastName)
{
    this->firstName = firstName;
    this->lastName = lastName;
    numOfProducts = 0;
}
string Customer::getFirstName()
{
    return firstName;
}
string Customer::getLastName()
{
    return lastName;
}
int Customer::getNumOfProducts()
{
    return numOfProducts;
}
BankProduct* Customer::getProduct(int index)
{
    return products.at(index);
}
void Customer::addProduct(BankProduct* product)
{
    products.push_back(product);
    numOfProducts++;
}