#pragma once
#include <queue>
#include <stdexcept>

class PlayerDetails;
using namespace std;

class PlayerBattingController {
private:
    queue<PlayerDetails*> yetToPlay;
    PlayerDetails* striker;
    PlayerDetails* nonStriker;

public: 
    PlayerBattingController(queue<PlayerDetails*> playing11) : striker(nullptr),
                                                               nonStriker(nullptr) {
                                                                yetToPlay = playing11;
                                                               }

    void getNextPlayer() {
        if(yetToPlay.empty()) {
            throw runtime_error("No Players Left to Play!");
        }

        if(striker == nullptr && !yetToPlay.empty()) {
            striker = yetToPlay.front();
            yetToPlay.pop();
        }

        if(nonStriker == nullptr && !yetToPlay.empty()) {
            nonStriker = yetToPlay.front();
            yetToPlay.pop();
        }
    }

    PlayerDetails* getStriker() const {
        return striker;
    }

    PlayerDetails* getNonStriker() const {
        return nonStriker;
    }

    void setStriker(PlayerDetails* playerDetails) {
        striker = playerDetails;
    }

    void setNonStriker(PlayerDetails* playerDetails) {
        nonStriker = playerDetails;
    }
};