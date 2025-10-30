#pragma once
#include <map>
#include "roboticDog.h"
#include "humanoidRobot.h"
#include "sprites.h"
#include "iRobot.h"
#include <string>
using namespace std;

class RoboticFactory {
private:
    map<string, IRobot*> roboticObjectCache;

public:
    IRobot* createRobot(string robotType) {
        if(roboticObjectCache.find(robotType) != roboticObjectCache.end()) {
            return roboticObjectCache[robotType];
        }
        else {
            if(robotType == "HUMANOID") {
                Sprites* humanoidSprite = new Sprites();
                IRobot* humanoidObject = new HumanoidRobot(robotType, humanoidSprite);

                // Adding into cache
                roboticObjectCache[robotType] = humanoidObject;

                return humanoidObject;
            }
            else if (robotType == "ROBOTIC_DOG") {
                Sprites* roboticDogSprite = new Sprites();
                IRobot* roboticDogObject = new HumanoidRobot(robotType, roboticDogSprite);

                // Adding into cache
                roboticObjectCache[robotType] = roboticDogObject;

                return roboticDogObject;
            }
        }

        throw invalid_argument("Invalid robot Type: " + robotType);
    }

    int getTotalRobots() {
        return roboticObjectCache.size();
    }
};