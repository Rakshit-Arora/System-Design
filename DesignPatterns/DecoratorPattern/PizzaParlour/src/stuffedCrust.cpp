#include "../HeaderFile/stuffedCrust.h"
#include <iostream>
using namespace std;

string StuffedCrust::getDescription() const {
    return pizza->getDescription() + ", Stuffed Crust";
}

double StuffedCrust::cost() const {
    return pizza->cost() + 80.0; // Stuffed crust costs an additional 80
}

void StuffedCrust::prepare() const {
    pizza->prepare();
    cout << "Preparing stuffed crust." << endl;
}   