#pragma once
#include <vector>
#include "floor.h"


class Building {
    private:
        vector<Floor> floors;
    public:
        Building(vector<Floor>&& f) : floors(move(f)) {}
        
        void addFloor(Floor &&fl) { floors.push_back(move(fl)); }
};