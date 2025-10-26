#pragma once
#include "./Player/playerBattingController.h"
#include "./Player/playerBowlingController.h"
#include "./Player/playerDetails.h"
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Team {
public:
    string teamName;
    queue<PlayerDetails*> playing11;
    vector<PlayerDetails*> bench;
    PlayerBattingController* battingController;
    PlayerBowlingController* bowlingController;
    bool isWinner;

    Team(string teamName, 
        queue<PlayerDetails*> playing11, 
        vector<PlayerDetails*> bench, 
        vector<PlayerDetails*> bowlers) 
    : teamName(teamName), 
      playing11(playing11),
      bench(bench),
      battingController(new PlayerBattingController(playing11)),
      bowlingController(new PlayerBowlingController(bowlers)),
      isWinner(false) {};

    string getTeamName() {
        return teamName;
    }

    void chooseNextBatsMan() {
        battingController -> getNextPlayer();
    }

    void chooseNextBowler(int maxOverCountPerBowler) {
        bowlingController -> getNextBowler(maxOverCountPerBowler);
    }

    PlayerDetails* getStriker() {
        return battingController -> getStriker();
    }

    PlayerDetails* getNonStriker() {
        return battingController -> getNonStriker();
    }

    void setStriker(PlayerDetails* player) {
        battingController -> setStriker(player);
    }

    void setNonStriker(PlayerDetails* player) {
        battingController -> setNonStriker(player);
    }

    PlayerDetails* getCurrentBowler() {
        return bowlingController -> getCurrentBowler();
    }

    void printBattingScoreCard() {
        queue<PlayerDetails*> temp = playing11;

        while(!temp.empty()) {
            PlayerDetails* player = temp.front();
            temp.pop();

            player -> pringBattingScoreCard();
        }
    }

    void printBowlingScoreCard() {
        queue<PlayerDetails*> temp = playing11;

        while(!temp.empty()) {
            PlayerDetails* player = temp.front();
            temp.pop();

            player -> printBowlingScoreCard();
        }
    }

    int getTotalRuns() {
        int totalRuns = 0;
        queue<PlayerDetails*> temp = playing11;

        while(!temp.empty()) {
            PlayerDetails* player = temp.front();
            temp.pop();

            totalRuns += player -> battingScoreCard->totalRuns;
        }

        return totalRuns;
    }

};