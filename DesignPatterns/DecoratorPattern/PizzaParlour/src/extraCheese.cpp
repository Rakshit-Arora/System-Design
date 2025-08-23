#include "../HeaderFile/extraCheese.h"
#include <iostream>
using namespace std;

string ExtraCheese::getDescription() const {
    return pizza->getDescription() + ", Extra Cheese";
}

double ExtraCheese::cost() const {
    return pizza->cost() + 50.0; // Extra cheese costs an additional 50
}

void ExtraCheese::prepare() const {
    pizza->prepare();
    cout << "Adding extra cheese." << endl;
}  

