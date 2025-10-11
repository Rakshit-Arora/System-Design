#pragma once
#include <vector>
#include <memory>
#include "seat.h"
using namespace std;

class Screen {
private: 
    int screenId;
    vector<shared_ptr<Seat>> seats;

public:
    Screen(int screenId, const vector<shared_ptr<Seat>> &seats);
    int getScreenId() const;
    const vector<shared_ptr<Seat>>& getSeats() const;
};
