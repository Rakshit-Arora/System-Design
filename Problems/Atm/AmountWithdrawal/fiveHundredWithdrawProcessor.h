#pragma once
#include "cashWithdrawProcessor.h"
#include <iostream>
using namespace std;

class FiveHundredWithdrawProcessor : public CashWithdrawProcessor {
public:
    FiveHundredWithdrawProcessor(CashWithdrawProcessor *n) : CashWithdrawProcessor(n) {} 
    
    void withdraw(ATM* atm, int remaniningAmount) override {
        int required = remaniningAmount / 500;
        int balance = remaniningAmount % 500;

        if(required <= atm -> getNoOfFiveHundredNotes()) {
            atm -> deductFiveHundredNotes(required);
        }
        else {
            balance += (required - atm -> getNoOfFiveHundredNotes()) * 500;
            atm -> deductFiveHundredNotes(atm -> getNoOfFiveHundredNotes());
        }

        if(balance > 0 && next) {
            next -> withdraw(atm, balance);
        }
    }
};