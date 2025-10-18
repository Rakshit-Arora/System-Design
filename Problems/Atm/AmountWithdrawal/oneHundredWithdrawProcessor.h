#pragma once 
#include "cashWithdrawProcessor.h"
#include <iostream>
using namespace std;

class OneHundredWithdrawProcessor : public CashWithdrawProcessor {
public:
    OneHundredWithdrawProcessor(CashWithdrawProcessor *n) : CashWithdrawProcessor(n) {} 
    
    void withdraw(ATM* atm, int remaniningAmount) override {
        int required = remaniningAmount / 100;
        int balance = remaniningAmount % 100;

        if(required <= atm -> getNoOfOneHundredNotes()) {
            atm -> deductOneHundredNotes(required);
        }
        else {
            balance += (required - atm -> getNoOfOneHundredNotes()) * 100;
            atm -> deductOneHundredNotes(atm -> getNoOfOneHundredNotes());
        }

        if(balance != 0) {
           cout<<"Something went wrong - remaining balance: "<<balance<<endl;
        }
    }
};