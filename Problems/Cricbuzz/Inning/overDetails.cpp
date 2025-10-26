#include "overDetails.h"
#include "ballDetails.h"
#include "../Team/Player/playerDetails.h"
#include "../Team/team.h"
#include <iostream>

using namespace std;

OverDetails::OverDetails(int overNumber, PlayerDetails* bowledBy)
    : overNumber(overNumber), extraBallsCount(0), bowledBy(bowledBy) {}

OverDetails::~OverDetails() {
    for (auto* ball : balls) delete ball;
}

bool OverDetails::startOver(Team* battingTeam, Team* bowlingTeam, int runsToWin, int maxOverCountPerBowler) {
    if (!bowledBy) {
        try {
            bowlingTeam->chooseNextBowler(maxOverCountPerBowler);
            bowledBy = bowlingTeam->getCurrentBowler();
        } catch (...) {
            cout << "No bowlers available for over " << overNumber << endl;
            return true; // end inning
        }
    }

    int ballCnt = 1;
    while(ballCnt <= 6) {
        if(!bowledBy) {
            cout << "No bowler available to bowl" << endl;
            return true; // safe exit
        }

        BallDetails* ball = new BallDetails(ballCnt);
        ball->startBallDelivery(battingTeam, bowlingTeam, this);

        balls.push_back(ball);
        if(ball->ballType == BallType::NORMAL) ballCnt++;

        if(ball->wicket) {
            try {
                battingTeam->chooseNextBatsMan();
            } catch (...) {
                cout << "No batsmen left to play" << endl;
                return true;
            }
        }

        if(runsToWin != -1 && battingTeam->getTotalRuns() >= runsToWin) {
            battingTeam->isWinner = true;
            return true;
        }
    }

    return false;
}
