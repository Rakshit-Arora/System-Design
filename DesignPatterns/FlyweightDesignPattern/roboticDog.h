#pragma once
#include "sprites.h"
#include "iRobot.h"
#include <iostream>
#include <string>
using namespace std;

class RoboticDog : public IRobot {
private:
    string type;
    Sprites* body;

public:
    RoboticDog(string type, Sprites* body) : type(type), body(body) {}

    string getType() {
        return type;
    }

    Sprites* getBody() {
        return body;
    }

    void display(int x, int y) override {
        cout << "Displaying " << type << " at " << x << " " << y << endl;
    }
};