#include "sportsVehicle.cpp"
#include "offRoadVehicle.cpp"
#include "goodsVehicle.cpp"
using namespace std;

int main() {
    SportsVehicle sportsVehicle;
    sportsVehicle.drive(); // Outputs: Sports Drive Capability

    OffRoadVehicle offRoadVehicle;
    offRoadVehicle.drive(); // Outputs: Sports Drive Capability

    GoodsVehicle goodsVehicle;
    goodsVehicle.drive(); // Outputs: Normal Drive Capability

    return 0;
}