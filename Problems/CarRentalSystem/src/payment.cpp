#include "../include/payment.h"

void Payment:: payBill(Bill &bill) {
    bill.isBillPaid = true;
    cout << "Bill of amount " << bill.totalBillAmount << " has been paid." << endl;
}