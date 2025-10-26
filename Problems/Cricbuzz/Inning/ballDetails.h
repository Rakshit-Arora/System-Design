// ...existing code...
#pragma once

#include <vector>
#include "../Inning/ballType.h"
#include "../Inning/runType.h"

using std::vector;

// Forward declarations to avoid heavy includes / circular deps
class PlayerDetails;
class Team;
class Wicket;
class ScoreUpdaterObserver;
class OverDetails;

struct BallDetails {
    int ballNumber;
    BallType ballType;
    RunType runType;
    PlayerDetails* playedBy;
    PlayerDetails* bowledBy;
    Wicket* wicket;
    vector<ScoreUpdaterObserver*> scoreUpdaterObserverList;

    // ctor/dtor moved to .cpp to avoid requiring full definitions here
    BallDetails(int ballNumber);
    ~BallDetails();

    void startBallDelivery(Team* battingTeam, Team* bowlingTeam, OverDetails* over);

private:
    void handleWicket(Team* battingTeam, Team* bowlingTeam, OverDetails* over);
    void handleRuns(Team* battingTeam);
    void notifyUpdaters();
    RunType getRunType();
    bool isWicketTaken();
};
