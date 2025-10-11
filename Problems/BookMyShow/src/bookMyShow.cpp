#include "../header/bookMyShow.h"

void BookMyShow:: run() {
    initialize();
    // user1
    createBooking(City::Bangalore, "BAAHUBALI");

    // user2
    createBooking(City::Bangalore, "BAAHUBALI");
}

void BookMyShow :: createBooking(City userCity, const string& movieName) {
    cout << "Searching movies in " << to_string(userCity) << "...\n";
    auto movies = movieController.getMovieByCity(userCity);

    shared_ptr<Movie> interestedMovie = nullptr;
    for (auto &m : movies) {
        if (m->getName() == movieName) {
            interestedMovie = m;
            break;
        }
    }

    if (!interestedMovie) {
        std::cout << "Movie not found in this city.\n";
        return;
    }

    auto showsTheatreWise = theatreController.getAllShow(interestedMovie, userCity);
    if (showsTheatreWise.empty()) {
        cout << "No shows available for movie in this city.\n";
        return;
    }

    // Pick the first theatre & show
    auto entry = *showsTheatreWise.begin();
    auto theatrePtr = entry.first;
    auto runningShows = entry.second;
    auto interestedShow = runningShows.front();

    int seatNumber = 30;
    if (!interestedShow->isSeatBooked(seatNumber)) {
        interestedShow->bookSeats(seatNumber);

        // find seat object by id from screen
        vector<shared_ptr<Seat>> myBookedSeats;

        for (auto &s : interestedShow->getScreen()->getSeats()) {
            if (s->getSeatId() == seatNumber) {
                myBookedSeats.push_back(s);
            }
        }

        // create a dummy payment (success)
        auto payment = make_shared<Payment>(1);

        // Create a Booking object (using constructor)
        Booking booking(interestedShow, payment, myBookedSeats);

        cout << "BOOKING SUCCESSFUL for seat " << seatNumber << " in theatre " << theatrePtr->getTheatreId() << "\n";

        // Print booking details
        booking.printBookingDetails();
    } else {
        cout << "Seat already booked, try again\n";
    }

}

void BookMyShow::initialize() {
    createMovie();
    createTheatre();
}

void BookMyShow::createMovie() {
    auto avengers = make_shared<Movie>(1, "AVENGERS", 128);
    auto baahubali = make_shared<Movie>(2, "BAAHUBALI", 180);

    movieController.addMovie(avengers, City::Bangalore);
    movieController.addMovie(avengers, City::Delhi);
    movieController.addMovie(baahubali, City::Bangalore);
    movieController.addMovie(baahubali, City::Delhi);
}

vector<shared_ptr<Screen>> BookMyShow ::createScreen() {
    vector<std::shared_ptr<Screen>> screens;
    auto screen1 = make_shared<Screen>(1, createSeats());
    screens.push_back(screen1);
    return screens;
}

shared_ptr<Show> BookMyShow :: createShow(int showId, const shared_ptr<Movie>& movie, const shared_ptr<Screen>& screen, int showStartTime) {
    return make_shared<Show>(showId, movie, screen, to_string(showStartTime));
}

std::vector<std::shared_ptr<Seat>> BookMyShow::createSeats() {
    std::vector<std::shared_ptr<Seat>> seats;

    // 0..39 SILVER
    for (int i = 0; i < 40; ++i) {
        seats.push_back(make_shared<Seat>(i, 0, SeatType::Silver));
    }
    // 40..69 GOLD
    for (int i = 40; i < 70; ++i) {
        seats.push_back(make_shared<Seat>(i, 0, SeatType::Gold));
    }
    // 70..99 PLATINUM
    for (int i = 70; i < 100; ++i) {
        seats.push_back(make_shared<Seat>(i, 0, SeatType::Platinum));
    }

    return seats;
}

void BookMyShow::createTheatre() {
    auto avengerMovie = movieController.getMovieByName("AVENGERS");
    auto baahubali = movieController.getMovieByName("BAAHUBALI");

    // INOX theatre (Bangalore)
    auto inoxTheatre = make_shared<Theatre>(1, "Bannergatta", City::Bangalore);
        for (auto& screen : createScreen()) {
            inoxTheatre->addScreen(screen);
    };

    inoxTheatre->addShow(createShow(1, avengerMovie, inoxTheatre->getScreens()[0], 8));
    inoxTheatre->addShow(createShow(2, baahubali, inoxTheatre->getScreens()[0], 16));

    // PVR theatre (Delhi)
    auto pvrTheatre = make_shared<Theatre>(2, "Chandni Chowk", City::Delhi);
        for(auto& screen : createScreen()) {
            pvrTheatre->addScreen(screen);
    };

    pvrTheatre->addShow(createShow(3, avengerMovie, pvrTheatre->getScreens()[0], 13));
    pvrTheatre->addShow(createShow(4, baahubali, pvrTheatre->getScreens()[0], 20));

    theatreController.addTheatre(inoxTheatre, City::Bangalore);
    theatreController.addTheatre(pvrTheatre, City::Delhi);
}
