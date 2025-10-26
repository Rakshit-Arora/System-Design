#pragma once
#include <queue>
#include <map>
#include <stdexcept>
#include <vector>
#include "playerDetails.h"
using namespace std;

class PlayerBowlingController {
private:
    deque<PlayerDetails*> bowlerList;
    map<PlayerDetails*, int> bowlerVsOverCount;
    PlayerDetails* currentBowler;

public:
    PlayerBowlingController(vector<PlayerDetails*>& bowlers) : currentBowler(nullptr) {
        for(auto* bowler: bowlers) {
            bowlerList.push_back(bowler);
            bowlerVsOverCount[bowler] = 0;
        }
    }

    void getNextBowler(int maxOverCountPerBowler) {
        if(bowlerList.empty()) {
            throw runtime_error("No Bowlers Available!");
        }

        // pick next bowler
        PlayerDetails* player = bowlerList.front();
        bowlerList.pop_front();

        // increment overs count
        bowlerVsOverCount[player]++;

        currentBowler = player;

        // push back only if bowler has remaining overs
        if(bowlerVsOverCount[player] < maxOverCountPerBowler) {
            bowlerList.push_back(player);
        }
    }

    PlayerDetails* getCurrentBowler() const {
        return currentBowler;
    }
};
