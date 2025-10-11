#pragma once
#include "enum.h"
using namespace std;

class Seat {
private:
    int seatId;
    int row;
    SeatType seatType;

public:
    Seat(int seatId, int row, SeatType seatType);
    int getSeatId() const;
    int getRow() const;
    SeatType getSeatType() const;
};