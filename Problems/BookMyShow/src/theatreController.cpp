#include "../header/theatreController.h"

void TheatreController::addTheatre(const shared_ptr<Theatre>& theatre, City city) {
    cityVsTheatres[city].push_back(theatre);
    allTheatres.push_back(theatre);
}

map<shared_ptr<Theatre>, vector<shared_ptr<Show>>> TheatreController::getAllShow(shared_ptr<Movie> movie, City city) {

    map<shared_ptr<Theatre>, vector<shared_ptr<Show>>> theatreVsShows;

    if (cityVsTheatres.find(city) != cityVsTheatres.end()) {

        for (const auto& theatre : cityVsTheatres[city]) {
            vector<shared_ptr<Show>> showsForMovie;

            for (const auto& show : theatre->getShows()) {
                if (show->getMovie()->getId() == movie->getId()) showsForMovie.push_back(show);
            }

            if (!showsForMovie.empty()) theatreVsShows[theatre] = showsForMovie;
        }
    }
    return theatreVsShows;
}