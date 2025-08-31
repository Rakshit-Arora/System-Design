#pragma once
#include "elevatorCreator.h"


class InternalDispatcher {
    ElevatorCreator* creator;
    public:
        InternalDispatcher(ElevatorCreator* c) : creator(c) {}
        
    // mapped from an elevator car pressing internal button
    void submitInternalRequest(int floor, int elevatorId) {
    // find matching elevator controller by id
        for (auto &ctrl : creator->controllers) {
            if (ctrl->elevator->id == elevatorId) {
                ctrl->submitRequest(floor);
                return;
            }
        }
    }
};