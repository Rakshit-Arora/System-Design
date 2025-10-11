#include "../header/show.h"
#include <algorithm>

Show::Show(int showId, const shared_ptr<Movie> &movie, const shared_ptr<Screen> &screen, const string &startTime) : showId(showId), movie(movie), screen(screen), startTime(startTime) {}

int Show::getShowId() const { return showId; }

shared_ptr<Movie> Show::getMovie() const { return movie; }

shared_ptr<Screen> Show::getScreen() const { return screen; }

string Show::getStartTime() const { return startTime; }

bool Show::isSeatBooked(int seatId) const {
    return find(bookedSeatIds.begin(), bookedSeatIds.end(), seatId) != bookedSeatIds.end();
}

void Show::bookSeats(int seatId) {
    if (!isSeatBooked(seatId)) bookedSeatIds.push_back(seatId);
}