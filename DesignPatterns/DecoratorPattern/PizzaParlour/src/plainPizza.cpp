#include<iostream>
#include "../HeaderFile/plainPizza.h"
using namespace std;

string to_string(Size s) {
    switch (s) {
        case Size::Small: return "Small";
        case Size::Medium: return "Medium";
        case Size::Large: return "Large";
    }
    return "Medium";
}

PlainPizza::PlainPizza(Size s) : size(s) {}

string PlainPizza::getDescription() const {
    return to_string(size) + " Plain Pizza (dough, tomato sauce, cheese)";
}

double PlainPizza::cost() const {
    switch (size) {
        case Size::Small: return 200.0;
        case Size::Medium: return 350.0;
        case Size::Large: return 500.0;
    }
    return 350.0; // Default to Medium if size is unrecognized
}

void PlainPizza::prepare() const {
    cout<<"Preparing " << getDescription()<< endl;
}