#include "../include/reservation.h"

Reservation:: Reservation(int id, User u, Vehicle* v) : reservationId(id), user(u), vehicle(v), status(ReservationStatus::SCHEDULED) {};

void Reservation:: createReserve() {
    // Logic to create a reservation
    status = ReservationStatus::INPROGRESS;
}