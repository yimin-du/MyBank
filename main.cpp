//
//  main.cpp
//  MyBank
//
//  Created by Yimin Du on 24/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#include <iostream>
#include"account.h"
#include"customer.h"
#include"bank.h"
#include"savingsAccount.h"
#include"creditAccount.h"
#include"customerReport.h"
#include"loan.h"
#include"homeloan.h"
#include"businessloan.h"

using namespace std;
void mainMenu();
void menuNewAccount();
void menuLoan();
void menuSavings();
void menuCredit();
void menuHomeLoan();
void menuBusinessLoan();
void menuLogin();

Bank& bank = Bank::getBank();
Customer* currentCustomer;
SavingsAccount sa(100, 0.045);
CreditAccount ca(100, 0.045);
HomeLoan hl(300000, 30, 0.052, true);
BusinessLoan bl(100000, 10, 0.065);

void mainMenu()
{
    cout << "=============================================== \n";
    cout << "||  please choose an item on the menu below  || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||               (1) Create New Account      || \n";
    cout << "||               (2) Apply for a loan        || \n";
    cout << "||               (3) Withdraw                || \n";
    cout << "||               (4) Deposit                 || \n";
    cout << "||               (5) Loan Repayment          || \n";
    cout << "||               (6) Account Report          || \n";
    cout << "||               (7) Log out                 || \n";
    cout << "=============================================== \n";
    cout << "Your Choice: ";
}


void menuNewAccount()
{
    cout << "=============================================== \n";
    cout << "||  please choose an account type from below || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||               (1) Savings Account         || \n";
    cout << "||               (2) Credit Account          || \n";
    cout << "||               (3) Back to main menu       || \n";
    cout << "=============================================== \n";
    cout << "Your Choice: ";
    int choice = -1;
    cin >> choice;
    switch(choice){
        case 1:
            menuSavings();
            break;
        case 2:
            menuCredit();
            break;
        case 3:
            break;
        default:
            cout << "invalid input. please choose again: " << endl;
            break;
            
    }
    
    
}

void menuLoan()
{
    cout << "=============================================== \n";
    cout << "||  please choose an loan type from below    || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||               (1) Home Loan               || \n";
    cout << "||               (2) Business Loan           || \n";
    cout << "||               (3) Back to main menu       || \n";
    cout << "=============================================== \n";
    cout << "Your Choice: ";
    
    int choice = -1;
    cin >> choice;
    switch(choice){
        case 1:
            menuHomeLoan();
            break;
        case 2:
            menuBusinessLoan();
            break;
        case 3:
            break;
        default:
            cout << "invalid input. please choose again: " << endl;
            break;
            
    }
}

void menuLogin()
{
    cout << "=============================================== \n";
    cout << "||             Customer Login in             || \n";
    cout << "=============================================== \n";
    cout << "Are you a new customer? Yes(y) | No(n) ";
    char choice;
    string firstName, lastName;
    cin >> choice;
    cout << "\nPlease input your full name: ";
    cin >> firstName >> lastName;
    while(choice != 'y' && choice != 'n'){
        cout << "please input y or n.";
    }
    if(choice == 'y'){
        bank.addCustomer(firstName, lastName);
        cout << "Thanks for banking with us, " << firstName << lastName <<
            "!" << endl;
        cout << "You have logged in!" << endl;
        currentCustomer = &bank.getCustomer(bank.getNumOfCustomers()-1);
    }
    else{
        try{
            currentCustomer = &bank.getCustomer(firstName, lastName);
            cout << "You have logged in, " << firstName << " " << lastName
            << "!" << endl;
        }
        catch(int e){
            cout << "customer not exist. please log in again!\n";
            menuLogin();
        }
    }
}
void menuSavings()
{
    cout << "=============================================== \n";
    cout << "||  Savings Account                          || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||        (1)  Account Fee: $5 / month       || \n";
    cout << "||        (2)  Interest Rate: %4.5           || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||  Create Savings Account? yes(y) | no(n)   || \n";
    cout << "=============================================== \n";
    cout << "Your Choice: ";
    char choice;
    cin >> choice;
    
    switch(choice){
        case 'y':{
            currentCustomer->addProduct(&sa);
            cout << "You have created a new Savings Account!\n";
            break;}
        case 'n':
            menuNewAccount();
            break;
        default:
            cout << "invalid input. please choose again: " << endl;
    }
    
}
void menuCredit()
{
    cout << "=============================================== \n";
    cout << "||  Credit Account                           || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||    (1)  Account Fee: $50 / year           || \n";
    cout << "||    (2)  Interest Rate: %3.5               || \n";
    cout << "||    (3)  Credit Limit: $5000               || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||  Create Credit Account? yes(y) | no(n)    || \n";
    cout << "=============================================== \n";
    cout << "Your Choice: ";
    
    char choice;
    cin >> choice;
    
    switch(choice){
        case 'y':{
            ca.setCreditLimit(5000);
            currentCustomer->addProduct(&ca);
            cout << "You have created a new Credit Account!\n";
            break;}
        case 'n':
            break;
        default:
            cout << "invalid input. please choose again: " << endl;
    }

}
void menuHomeLoan()
{
    cout << "=============================================== \n";
    cout << "||  Home Loan                                || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||    (1)  Max loan term: 30 years           || \n";
    cout << "||    (2)  Interest Rate: %5.2               || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||  Get Home Loan? yes(y) | no(n)            || \n";
    cout << "=============================================== \n";
    cout << "Your Choice: ";
    
    char choice;
    cin >> choice;
    
    switch(choice){
        case 'y':{
            currentCustomer->addProduct(&hl);
            cout << "You have got a new Home Loan!\n";
            break;}
        case 'n':
            break;
        default:
            cout << "invalid input. please input y or n: " << endl;
    }

}

void menuBusinessLoan()
{
    cout << "=============================================== \n";
    cout << "||  Business Loan                            || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||    (1)  Max loan term: 10 years           || \n";
    cout << "||    (2)  Interest Rate: %6.5               || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||  Get Business Loan? yes(y) | no(n)        || \n";
    cout << "=============================================== \n";
    cout << "Your Choice: ";
    
    char choice;
    cin >> choice;
    
    switch(choice){
        case 'y':{
            currentCustomer->addProduct(&bl);
            cout << "You have got a new Business Loan!\n";
            break;}
        case 'n':
            break;
        default:
            cout << "invalid input. please input y or n: " << endl;
    }

}

void menuWithdraw()
{
    
    cout << "=============================================== \n";
    cout << "||               Withdraw                    || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||    Please select the account:             || \n";
    cout << "||-------------------------------------------|| \n";
    for(int i = 0; i < currentCustomer->getNumOfProducts(); i++){
        string type = currentCustomer->getProduct(i)->getProductType();
        cout << "      ("<<i+1<<")  "<< type << "                   \n";
    }
    cout << "=============================================== \n";
    cout << "Your Choice: ";
    if(currentCustomer->getNumOfProducts() == 0){
        cout << "You have no account in this bank.\n";
        return;
    }
    int choice;
    cin >> choice;
    while(choice < 1 || choice > currentCustomer->getNumOfProducts()){
        cout << "invalid input. select again: ";
        cin >> choice;
    }
    cout << "Please input the amount to withdraw: ";
    double amount;
    cin >> amount;
    BankProduct* product = currentCustomer->getProduct(choice - 1);
    string type = product->getProductType();
    if(product->withdraw(amount)){
        cout << "You just withdrew $" << amount << "from your " << type << endl;
    }
    else{
        cout << "insufficient funds in your " << type << endl;
    }
}

void menuDeposit()
{
    int numAccounts = 0;
    cout << "=============================================== \n";
    cout << "||               Deposit                     || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||    Please select the account:             || \n";
    cout << "||-------------------------------------------|| \n";
    for(int i = 0; i < currentCustomer->getNumOfProducts(); i++){
        string type = currentCustomer->getProduct(i)->getProductType();
        if(type == "Savings Account" || type == "Credit Account"){
            cout << "      ("<<i+1<<")  "<< type << "                   \n";
            numAccounts++;
        }
    }
    cout << "=============================================== \n";
    cout << "Your Choice: ";
    if(numAccounts == 0){
        cout << "You have no account in this bank.\n";
        cout << "Deposit can not proceed!\n";
        return;
    }
    int choice;
    cin >> choice;
    while(choice < 1 || choice > currentCustomer->getNumOfProducts()){
        cout << "invalid input. select again: ";
        cin >> choice;
    }
    cout << "Please input the amount to deposit: ";
    double amount;
    cin >> amount;
    Account* acc = (Account*)currentCustomer->getProduct(choice - 1);
    acc->deposit(amount);
}

void menuLoanRepay()
{
    int numLoans = 0, loanIndex1 = -1, loanIndex2 = -1;
;
    cout << "=============================================== \n";
    cout << "||               Repay your loan             || \n";
    cout << "||-------------------------------------------|| \n";
    cout << "||    Please select the loan type:           || \n";
    cout << "||-------------------------------------------|| \n";
    for(int i = 0; i < currentCustomer->getNumOfProducts(); i++){
        string type = currentCustomer->getProduct(i)->getProductType();
        if(type == "Home Loan" || type == "Business Loan"){
            cout << "      ("<<i+1<<")  "<< type << "                   \n";
            if(loanIndex1 == -1)
                loanIndex1 = i;
            else
                loanIndex2 = i;
            numLoans++;
        }
    }
    cout << "=============================================== \n";
    cout << "Your Choice: ";
    if(numLoans == 0){
        cout << "You have no loan in this bank.\n";
        cout << "Transaction can not proceed!\n";
        return;
    }
    int choice;
    cin >> choice;
    while(choice < 1 || choice > numLoans){
        cout << "invalid input. select again: ";
        cin >> choice;
    }
    int loanIndex;
    if(choice == 1)
        loanIndex = loanIndex1;
    else
        loanIndex = loanIndex2;
    Loan* loan = (Loan*)currentCustomer->getProduct(loanIndex);
    loan->makeRepayment();
}


int main()
{
    int menuChoice = -1;
    menuLogin();
    while(true){
        mainMenu();
        cin >> menuChoice;
        switch(menuChoice){
            case 1:
                menuNewAccount();
                break;
            case 2:
                menuLoan();
                break;
            case 3:
                menuWithdraw();
                break;
            case 4:
                menuDeposit();
                break;
            case 5:
                menuLoanRepay();
                break;
            case 6:{
                CustomerReport report;
                report.printReport(currentCustomer);
                break;}
            case 7:
                cout << "Thanks for using our service. Bye bye!" << endl;
                menuLogin();
                break;
            default:
                cout << "invalid input. please choose again: " << endl;
        }
    }
}

