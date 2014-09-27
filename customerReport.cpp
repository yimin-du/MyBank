//
//  customerReport.cpp
//  MyBank
//
//  Created by Yimin Du on 25/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#include "customerReport.h"
#include "bank.h"
#include "customer.h"
#include "savingsAccount.h"
#include "creditAccount.h"
#include "homeloan.h"
#include "businessloan.h"
#include <iostream>
using namespace std;

CustomerReport::CustomerReport()
{
    bank = Bank::getBank();

}

void CustomerReport::printReport(Customer* cus)
{
    cout << cus->getFirstName() << " " << cus->getLastName() << endl;
    for(int j = 0; j < cus->getNumOfProducts(); j++){
        BankProduct* product = cus->getProduct(j);
        string type = product->getProductType();
        if(type == "Savings Account"){
            SavingsAccount *sa = (SavingsAccount*)product;
            cout << "Savings Account\t" << "interest rate: "
            << sa->getInterestRate() << "\t" << "balance: " << sa->getBalance() << endl;
        }
        else if(type == "Credit Account"){
            CreditAccount *ca = (CreditAccount*)product;
            cout << "Credit Account\t" << "balnace: "
            << ca->getBalance() << "\t"
            << "remaining credit: " << ca->getCreditLimit() << endl;          }
        else if(type == "Home Loan"){
            HomeLoan *hl = (HomeLoan*)product;
            cout << "Home Loan\t" << "monthly repayment: " << hl->getMonthlyRepayment() << "\t remaining balance: " << hl->getBalance() << endl;
        }
        else if(type == "Business Loan"){
            BusinessLoan *bl = (BusinessLoan*)product;
            cout << "Business Loan\t" << "monthly repayment: " << bl->getMonthlyRepayment() << "\t remaining balance: " << bl->getBalance() << endl;
        }
    }

}

void CustomerReport::generateReport(string firstName, string lastName)
{
    cout << "\t\t\t" << "Customers Report" << endl;
    Customer cus;
    for(int i = 0; i < bank.getNumOfCustomers(); i++){
        cus = bank.getCustomer(i);
        if(firstName == cus.getFirstName() && lastName == cus.getLastName()){
            printReport(&cus);
            break;
        }
    }
}

void CustomerReport::generateReport()
{
    cout << "\t\t\t" << "Customers Report" << endl;
    Customer cus;
    for(int i = 0; i < bank.getNumOfCustomers(); i++){
        cus = bank.getCustomer(i);
        printReport(&cus);
    }
}