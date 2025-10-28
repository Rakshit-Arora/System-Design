#pragma once
#include "../Implementor/breathingProcess.h"
#include <iostream>
using namespace std;

class GillBreating : public BreathingProcess {
public:
    void breathe() override {
        cout << "Breating through Gills" << endl;
    }
};