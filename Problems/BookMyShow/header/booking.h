#pragma once
#include "show.h"
#include "enum.h"
#include "payment.h"
#include <vector>
#include <memory>
using namespace std;

class Booking {
private:
    shared_ptr<Show> show;
    shared_ptr<Payment> payment;
    vector<shared_ptr<Seat>> bookedSeats;

public:
    Booking(const shared_ptr<Show>& show, const shared_ptr<Payment>& payment, const vector<shared_ptr<Seat>>& bookedSeats);

    shared_ptr<Show> getShow() const;
    shared_ptr<Payment> getPayment() const;
    vector<shared_ptr<Seat>> getBookedSeats() const;

    void printBookingDetails() const;
};
