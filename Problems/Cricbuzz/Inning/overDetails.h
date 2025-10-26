#pragma once
#include <vector>
#include <iostream>
#include "ballType.h"

class BallDetails;
class PlayerDetails;
class Team;

using namespace std;

class OverDetails {
public:
    int overNumber;
    vector<BallDetails*> balls;
    int extraBallsCount;
    PlayerDetails* bowledBy;

    OverDetails(int overNumber, PlayerDetails* bowledBy);
    ~OverDetails();

    bool startOver(Team* battingTeam, Team* bowlingTeam, int runsToWin, int maxOverCountPerBowler);
};