#include "../header/movie.h"

Movie::Movie(int movieId, const string &name, int duration) 
    : movieId(movieId), name(name), duration(duration) {}

int Movie::getId() const { return movieId; }
string Movie::getName() const { return name; }
int Movie::getDuration() const { return duration; }