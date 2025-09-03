#pragma once
#include "reservation.h"

class Bill {
public:
    Reservation reservation;
    double totalBillAmount;
    bool isBillPaid;

    Bill(Reservation res);
    double computeBillAmount();
};
