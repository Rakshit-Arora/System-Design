#pragma once
#include <iostream>
#include "observer.h"
#include <vector>
#include <string>
using namespace std;

class Subject{
    public:
        virtual ~Subject() = default;

        // Attach an observer to the subject
        virtual void add(Observer* observer) = 0;

        // Detach an observer from the subject
        virtual void remove(Observer* observer) = 0;

        // Notify all observers about a change in stock
        virtual void notify(const string& itemName, int quantity) = 0;
};