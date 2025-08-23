#include "../HeaderFile/pepperoni.h"
#include <iostream>
using namespace std;

string Pepperoni::getDescription() const {
    return pizza->getDescription() + ", Pepperoni";
}

double Pepperoni::cost() const {
    return pizza->cost() + 100.0; // Pepperoni costs an additional 100
}

void Pepperoni::prepare() const {
    pizza->prepare();
    cout << "Adding pepperoni slices." << endl;
}