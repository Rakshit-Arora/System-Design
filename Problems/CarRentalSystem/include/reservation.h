#pragma once
#include "user.h"
#include "vehicle.h"
#include "enums.h"

class Reservation {
public:
    int reservationId;
    ReservationStatus status;
    User user;
    Vehicle* vehicle;

    Reservation(int id, User u, Vehicle* v);
    void createReserve();
};
