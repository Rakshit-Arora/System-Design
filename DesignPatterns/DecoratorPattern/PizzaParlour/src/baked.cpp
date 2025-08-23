#include "../HeaderFile/baked.h"
#include <iostream>
using namespace std;

string Baked::getDescription() const {
    return pizza->getDescription() + ", Baked";
}

double Baked::cost() const {
    return pizza->cost() + 20.0; // Baking costs an additional 20
}

void Baked::prepare() const {
    pizza->prepare();
    cout << "Baking the pizza." << endl;
}

