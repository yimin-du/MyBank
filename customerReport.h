//
//  customerReport.h
//  MyBank
//
//  Created by Yimin Du on 25/09/2014.
//  Copyright (c) 2014 UoA. All rights reserved.
//

#ifndef MyBank_customerReport_h
#define MyBank_customerReport_h
#include "bank.h"

class CustomerReport
{
public:
    CustomerReport();
    void printReport(Customer* cus);
    void generateReport();
    void generateReport(std::string, std::string);
private:
    Bank bank;
};

#endif
