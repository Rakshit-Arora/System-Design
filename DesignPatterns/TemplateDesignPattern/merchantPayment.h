#pragma once
#include "paymentFlow.h"
#include <iostream>
using namespace std;

class MerchantPayment : public PaymentFlow {
public:
    void validateRequest() override {
        cout << "Specific Validation Logic for Merchant Payment" << endl;
    }

    void debitAmount() override {
        cout << "Specific Debit Amount Logic for Merchant Payment" << endl;
    }

    void calculateFees() override {
        cout << "Specific Calculate Fees Logic for Merchant Payment, 5% Fees is applied" << endl;
    }

    void creditAmount() override {
        cout << "Specific Credit Amount Logic for Merchant Payment, Full amount is credited" << endl;
    }
};
