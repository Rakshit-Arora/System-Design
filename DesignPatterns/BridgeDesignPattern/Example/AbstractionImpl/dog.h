#pragma once
#include <iostream>
#include "../Abstraction/livingThings.h"
using namespace std;

class Dog : public LivingThings {
public:
    explicit Dog(shared_ptr<BreathingProcess> process) : LivingThings(move(process)) {}

    void breathe() override {
        cout<<"Dog: ";
        breathingProcess -> breathe();
    }
};