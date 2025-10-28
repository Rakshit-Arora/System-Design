#pragma once
#include <iostream>
using namespace std;

class AirConditioner {
private:
    bool isOn;
    int temperature;

public: 
    void turnOn() {
        isOn = true;
        cout << "Air Conditioner is On" << endl;
    }

    void turnOff() {
        isOn = false;
        cout << "Air Conditioner is Off" << endl;
    }

    bool isAcOn() {
        return isOn;
    }

    void setOn(bool on) {
        isOn = on;
    }

    int getTemperature() {
        return temperature;
    }

    void setTemperature(int temp) {
        temperature = temp;
        cout << "Air Conditioner temperature set up to: " << temperature << "°C" << endl;
    }
};