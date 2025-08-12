#include "vehicle.cpp"
#include <iostream>
using namespace std;

class SportsVehicle : public Vehicle {
    public:
    void drive() {
        cout<<"Sports Drive Capability"<<endl;
    }
};
// This class overrides the drive method to provide sports vehicle specific functionality.