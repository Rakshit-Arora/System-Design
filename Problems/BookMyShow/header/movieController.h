#pragma once
#include "movie.h"
#include "enum.h"
#include <vector>
#include <memory>
#include <map>
using namespace std;

class MovieController {
private:
    map<City, vector<shared_ptr<Movie>>> cityVsMovies;
    vector<shared_ptr<Movie>> allMovies;

public: 
    void addMovie(const shared_ptr<Movie>& movie, City city);
    shared_ptr<Movie> getMovieByName(string name);
    vector<shared_ptr<Movie>> getMovieByCity(City city);
};