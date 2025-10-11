#pragma once
#include <string>
using namespace std;

class Movie {
private:
    int movieId;
    string name;
    int duration; // in minutes

public:
    Movie(int movieId, const string &name, int duration);
    int getId() const;
    string getName() const;
    int getDuration() const;
};