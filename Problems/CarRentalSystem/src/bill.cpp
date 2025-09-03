#include "../include/bill.h"

Bill:: Bill(Reservation res) : reservation(res), isBillPaid(false) { totalBillAmount = computeBillAmount();}

double Bill:: computeBillAmount() {
    // Logic to compute the total bill amount based on reservation details
    // For simplicity, let's assume a flat rate for demonstration purposes
    return 100.0; // Placeholder value
}