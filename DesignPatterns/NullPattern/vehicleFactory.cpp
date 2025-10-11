#include "HeaderFile/vehicleFactory.h"
#include "HeaderFile/car.h"
#include "HeaderFile/bike.h"
#include "HeaderFile/nullVehicle.h"
using namespace std;

shared_ptr<Vehicle> VehicleFactory::create(string& type) {
    if(type == "Car" || type == "car") {
        return make_shared<Car>();
    } else if(type == "Bike" || type == "bike") {
        return make_shared<Bike>();
    } else {
        return make_shared<NullVehicle>(); // The Main Null Object;
    }
}

