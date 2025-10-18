#pragma once
#include "../atm.h"

class CashWithdrawProcessor {
public:     
    CashWithdrawProcessor* next;

    CashWithdrawProcessor(CashWithdrawProcessor* n) : next(n) {}

    virtual void withdraw(ATM* atm, int remainingAmount) {
        if (next) {
            next->withdraw(atm, remainingAmount);
        }
    }

    virtual ~CashWithdrawProcessor() = default;
};