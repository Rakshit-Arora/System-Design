#include "../header/seat.h"

Seat::Seat(int seatId, int row, SeatType seatType) 
    : seatId(seatId), row(row), seatType(seatType) {}

int Seat::getSeatId() const { return seatId; }
int Seat::getRow() const { return row; }
SeatType Seat::getSeatType() const { return seatType; }