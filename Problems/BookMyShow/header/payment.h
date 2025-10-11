#pragma once

class Payment {
private:
    int paymentId;
public:
    Payment(int paymentId);
    int getPaymentId() const;
};