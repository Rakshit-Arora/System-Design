#include <iostream>
#include "HeaderFile/vehicleFactory.h"
using namespace std;

int main() {
    vector<string> types = {"car", "bike", "truck"};

    for (auto& type : types) {
        auto vehicle = VehicleFactory::create(type);
        cout << vehicle->getType() << endl;
        vehicle->start();
        vehicle->drive();
        cout << "-----" << endl;
    }

    return 0;
}