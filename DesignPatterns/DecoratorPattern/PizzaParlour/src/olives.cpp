#include "../HeaderFile/olives.h"
#include <iostream>
using namespace std;

string Olives::getDescription() const {
    return pizza->getDescription() + ", Olives";
}   

double Olives::cost() const {
    return pizza->cost() + 30.0; // Olives cost an additional 30
}   

void Olives::prepare() const {
    pizza->prepare();
    cout << "Adding olives." << endl;
}   