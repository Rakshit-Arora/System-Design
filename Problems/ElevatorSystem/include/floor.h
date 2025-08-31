#pragma once
#include "direction.h"
#include "externalDispatcher.h"

class ExternalDispatcher;

class Floor {
    private:
       int floorNumber;
        ExternalDispatcher* dispatcher;

    public:
        Floor(int n, ExternalDispatcher* d) : floorNumber(n), dispatcher(d) {}
        
        int getNumber() const { return floorNumber; }

        void pressButton(Direction dir) {
            dispatcher->submitExternalRequest(floorNumber, dir);
        }
};