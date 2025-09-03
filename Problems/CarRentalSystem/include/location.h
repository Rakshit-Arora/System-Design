#pragma once
#include <string>
using namespace std;

class Location{
public:
    string address;
    string city;
    string state;
    string country;
    int pincode;

    Location(int pincode, string city, string state, string country);
};