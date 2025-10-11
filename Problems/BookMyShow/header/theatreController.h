#pragma once
#include "theatre.h"
#include <map>
using namespace std;

class TheatreController {
private:
    map<City, vector<shared_ptr<Theatre>>> cityVsTheatres;
    vector<shared_ptr<Theatre>> allTheatres;

public:
    void addTheatre(const shared_ptr<Theatre>& theatre, City city);
    map<shared_ptr<Theatre>, vector<shared_ptr<Show>>> getAllShow(shared_ptr<Movie> movie, City city);
};