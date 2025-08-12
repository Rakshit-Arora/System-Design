#pragma once
#include "driveStrategy.h"

class SportsDriveStrategy : public DriveStrategy {
public:
    void drive() override {
        cout << "Sports Drive Capability" << endl;
    }
};
