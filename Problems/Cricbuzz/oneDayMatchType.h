#pragma once
#include "matchType.h"

class OneDayMatchType : public MatchType {
public:
    int noOfOvers() override {
        return 50;
    }

    int maxOverCountBowlers() override {
        return 10;
    }
};