#pragma once
#include "theatreController.h"
#include "movieController.h"
#include "booking.h"
#include <iostream>
using namespace std;

class BookMyShow {
private:
    MovieController movieController;
    TheatreController theatreController;

public:
   BookMyShow() = default;
   void run();

private:
   void createBooking(City userCity, const string& movieName);
   void initialize();
   void createMovie();
   vector<shared_ptr<Screen>> createScreen();
   shared_ptr<Show> createShow(int showId, const shared_ptr<Movie>& movie, const shared_ptr<Screen>& screen, int startTime);
   vector<shared_ptr<Seat>> createSeats();
   void createTheatre();
};