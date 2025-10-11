#include "../header/theatre.h"

Theatre::Theatre(int theatreId, const string& address, City city) : theatreId(theatreId), address(address), city(city) {}

int Theatre::getTheatreId() const { return theatreId; }

City Theatre::getCity() const { return city; }

string Theatre::getAddress() const { return address; }

void Theatre::addScreen(const shared_ptr<Screen>& screen) {
    screens.push_back(screen);
}

void Theatre::addShow(const shared_ptr<Show>& show) {
    shows.push_back(show);
}

vector<shared_ptr<Show>> Theatre::getShows() const {
    return shows;
}

vector<shared_ptr<Screen>> Theatre::getScreens() const {
    return screens;
}