#include <iostream>
#include <memory>
#include "HeaderFile/plainPizza.h"
#include "HeaderFile/extraCheese.h"
#include "HeaderFile/pepperoni.h"
#include "HeaderFile/olives.h"
#include "HeaderFile/stuffedCrust.h"
#include "HeaderFile/baked.h"
using namespace std;

string rupees (double a) {
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "₹%.2f", a); // This basically formats amount into string with rupee symbol upto 2 decimal points, and snprintf in this the n signifies the size of the buffer in our case 50 to avoid overflow
    return string(buffer);
}

int main() {
   // Order 1: Medium plain + extra cheese + pepperoni + bake
    unique_ptr<Pizza> order1 = make_unique<Baked>(
        make_unique<Pepperoni>(
            make_unique<ExtraCheese>(
                make_unique<PlainPizza>(Size::Medium))));

    cout << "[Order 1]\n";
    cout << order1->getDescription() << "\n";
    order1->prepare();
    cout << "Total: " << rupees(order1->cost()) << "\n\n";

    // Order 2: Large plain + stuffed crust + extra cheese + olives + bake
    unique_ptr<Pizza> order2 = make_unique<Baked>(
        make_unique<Olives>(
            make_unique<ExtraCheese>(
                make_unique<StuffedCrust>(
                    make_unique<PlainPizza>(Size::Large)))));

    cout << "[Order 2]\n";
    cout << order2->getDescription() << "\n";
    order2->prepare();
    cout << "Total: " << rupees(order2->cost()) << "\n\n";

    // Order 3: Small plain + bake
    unique_ptr<Pizza> order3 = make_unique<Baked>(
        make_unique<PlainPizza>(Size::Small));

    cout << "[Order 3]\n";
    cout << order3->getDescription() << "\n";
    order3->prepare();
    cout << "Total: " << rupees(order3->cost()) << "\n";

    return 0;
}