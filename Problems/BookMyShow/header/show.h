#pragma once
#include "movie.h"
#include "screen.h"
#include <vector>
#include <memory>
using namespace std;

class Show {
private:
    int showId;
    shared_ptr<Movie> movie;
    shared_ptr<Screen> screen;
    string startTime;
    vector<int> bookedSeatIds;

public:
    Show(int showId, const shared_ptr<Movie> &movie, const shared_ptr<Screen> &screen, const string &startTime);
    int getShowId() const;
    shared_ptr<Movie> getMovie() const;
    shared_ptr<Screen> getScreen() const;
    string getStartTime() const;
    bool isSeatBooked(int seatId) const;
    void bookSeats(int seatId);
}; 
