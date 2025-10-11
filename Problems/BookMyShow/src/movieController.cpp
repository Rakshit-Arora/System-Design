#include "../header/movieController.h"

void MovieController::addMovie(const shared_ptr<Movie>& movie, City city) {
    cityVsMovies[city].push_back(movie);
    allMovies.push_back(movie);
}

shared_ptr<Movie> MovieController::getMovieByName(string name) {
    for (const auto& movie : allMovies) {
        if (movie->getName() == name) {
            return movie;
        }
    }
    return nullptr; // Return nullptr if movie not found
}

vector<shared_ptr<Movie>> MovieController::getMovieByCity(City city) {
    if (cityVsMovies.find(city) != cityVsMovies.end()) {
        return cityVsMovies[city];
    }
    return {}; // Return empty vector if no movies found for the city
}