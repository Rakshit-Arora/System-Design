#include <iostream>
#include "../include/elevatorCreator.h"
#include "../include/externalDispatcher.h"
#include "../include/internalDispatcher.h"
#include "../include/floor.h"
#include "../include/internalButtons.h"
using namespace std;

int main() {
    // create 2 elevators (like original Java sample)
    ElevatorCreator creator(2);


    // build dispatchers
    ExternalDispatcher externalDispatcher(&creator);
    InternalDispatcher internalDispatcher(&creator);


    // create internal button interfaces for each elevator car
    InternalButtons inside0(&internalDispatcher, 10);
    InternalButtons inside1(&internalDispatcher, 10);


    // simulate floors
    Floor f1(1, &externalDispatcher);
    Floor f2(2, &externalDispatcher);
    Floor f3(3, &externalDispatcher);
    Floor f4(4, &externalDispatcher);
    Floor f5(5, &externalDispatcher);


    // simulate external requests
    f3.pressButton(Direction::UP);
    f5.pressButton(Direction::DOWN);
    f1.pressButton(Direction::UP);


    // simulate internal presses (user inside elevator 1 wants floor 4)
    inside0.pressButton(4, creator.cars[0]);
    inside1.pressButton(2, creator.cars[1]);


    // run controllers (single-threaded - call control on each)
    for (auto &ctrl : creator.controllers) {
        ctrl->controlElevatorOnce();
    }


    cout << "All requests processed.\n";
    return 0;
}