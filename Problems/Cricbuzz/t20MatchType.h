#pragma once
#include "matchType.h"

class T20MatchType : public MatchType {
public: 
    int noOfOvers() override {
        return 20;
    }

    int maxOverCountBowlers() override {
        return 5;
    }
};