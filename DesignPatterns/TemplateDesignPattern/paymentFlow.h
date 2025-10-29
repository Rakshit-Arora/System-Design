#pragma once
#include <iostream>
using namespace std;

class PaymentFlow {
public:
    virtual ~PaymentFlow() = default;
    virtual void validateRequest() = 0;
    virtual void debitAmount() = 0;
    virtual void calculateFees() = 0;
    virtual void creditAmount() = 0;

    void sendMoney() {
        // step 1
        validateRequest();

        // step 2
        debitAmount();

        // step 3
        calculateFees();

        // step 4
        creditAmount();
    }

    bool requiresOtpAuth() {
        return false;
    }

    void logTransaction() {
        cout<< "Transaction Completed!" << endl;
    }
};