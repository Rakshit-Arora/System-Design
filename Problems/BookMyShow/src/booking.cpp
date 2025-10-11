#include "../header/booking.h"
#include <iostream>

Booking::Booking(const shared_ptr<Show>& show, const shared_ptr<Payment>& payment, const vector<shared_ptr<Seat>>& bookedSeats)
    : show(show), payment(payment), bookedSeats(bookedSeats) {}

shared_ptr<Show> Booking::getShow() const { return show; }

shared_ptr<Payment> Booking::getPayment() const { return payment; }

vector<shared_ptr<Seat>> Booking::getBookedSeats() const { return bookedSeats; }

void Booking::printBookingDetails() const {
    cout << "Booking Details:\n";
    cout << "Show ID: " << show->getShowId() << "\n";
    cout << "Movie: " << show->getMovie()->getName() << "\n";
    cout << "Screen ID: " << show->getScreen()->getScreenId() << "\n";
    cout << "Start Time: " << show->getStartTime() << "\n";
    cout << "Payment ID: " << payment->getPaymentId() << "\n";
    cout << "Booked Seats:\n";
    for (const auto& seat : bookedSeats) {
        cout << "  Seat ID: " << seat->getSeatId() << ", Row: " << seat->getRow() << ", Type: " << to_string(seat->getSeatType()) << "\n";
    }
}