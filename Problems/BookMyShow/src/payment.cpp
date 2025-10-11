#include "../header/payment.h"

Payment::Payment(int paymentId) : paymentId(paymentId) {}

int Payment::getPaymentId() const { return paymentId; }