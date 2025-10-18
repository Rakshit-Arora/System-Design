#pragma once
#include "cashWithdrawProcessor.h"
#include <iostream>
using namespace std;

class TwoThousandWithdrawProcessor : public CashWithdrawProcessor {
public:
    TwoThousandWithdrawProcessor(CashWithdrawProcessor *n) : CashWithdrawProcessor(n) {}

    void withdraw(ATM* atm, int remainingAmount) override {
        int required = remainingAmount / 2000;
        int balance = remainingAmount % 2000;

        if(required <= atm -> getNoOfTwoThousandNotes()) {
            atm -> deductTwoThousandNotes(required);
        }
        else {
            balance += (required - atm -> getNoOfTwoThousandNotes()) * 2000;
            atm -> deductTwoThousandNotes(atm -> getNoOfTwoThousandNotes());
        }

        if(balance > 0 && next) {
            next -> withdraw(atm, balance);
        }
    }
};