#include <iostream>
#include "roboticFactory.h"
#include "iRobot.h"
using namespace std;

int main() {
    cout << "----- Flyweight Design Pattern -----" << endl;
    RoboticFactory roboticFactoryObj;

    IRobot* humanoidRobot1 = roboticFactoryObj.createRobot("HUMANOID");
    humanoidRobot1->display(1, 2);

    IRobot* humanoidRobot2 = roboticFactoryObj.createRobot("HUMANOID");
    humanoidRobot2->display(10, 30);

    IRobot* dogRobot1 = roboticFactoryObj.createRobot("ROBOTIC_DOG");
    dogRobot1->display(2, 9);

    IRobot* dogRobot2 = roboticFactoryObj.createRobot("ROBOTIC_DOG");
    dogRobot2->display(11, 19);

    cout << "Total Robots Created: " << roboticFactoryObj.getTotalRobots() << endl;


    return 0;
}