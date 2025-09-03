#include "../include/location.h"

Location::Location(int pin, std::string city, std::string state, std::string country)
    : pincode(pin), city(city), state(state), country(country) {}
