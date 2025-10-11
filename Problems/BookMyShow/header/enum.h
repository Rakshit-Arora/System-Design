#pragma once 
#include <string>
using namespace std;

enum class City {
    Bangalore,
    Delhi,
};

inline :: string to_string(City c) {
    switch(c) {
        case City::Bangalore: return "Bangalore";
        case City::Delhi: return "Delhi";
        default: return "Unknown";
    }
}

enum class SeatType {
    Gold,
    Silver,
    Platinum,
};

inline :: string to_string(SeatType s) {
    switch(s) {
        case SeatType::Gold: return "Gold";
        case SeatType::Silver: return "Silver";
        case SeatType::Platinum: return "Platinum";
        default: return "Unknown";
    }
};