#pragma once
#include "paymentFlow.h"
#include <iostream>
using namespace std;

class BankTransfer : public PaymentFlow {
public:
    void validateRequest() override {
        cout << "Specific Validation Logic for Bank Transfer" << endl;
    }

    void debitAmount() override {
        cout << "Specific Debit Amount Logic for Bank Transfer" << endl;
    }

    void calculateFees() override {
        cout << "Specific Calculate Fees Logic for Bank Transfer, 0% Fees is applied" << endl;
    }

    void creditAmount() override {
        cout << "Specific Credit Amount Logic for Bank Transfer, Full amount is credited" << endl;
    }
};
