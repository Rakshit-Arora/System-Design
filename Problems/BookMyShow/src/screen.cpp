#include "../header/screen.h"

Screen :: Screen(int screenId, const vector<shared_ptr<Seat>> &seats) : screenId(screenId), seats(seats) {}

int Screen::getScreenId() const { return screenId; }
const vector<shared_ptr<Seat>>& Screen::getSeats() const { return seats; }