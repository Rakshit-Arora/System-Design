// ...existing code...
#include "ballDetails.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "../ScoreUpdater/battingScoreUpdater.h"
#include "../ScoreUpdater/bowlingScoreUpdater.h"
#include "../Team/team.h"
#include "../Team/wicket.h"
#include "../Team/wicketType.h"
#include "overDetails.h"

BallDetails::BallDetails(int ballNumber)
    : ballNumber(ballNumber),
      ballType(BallType::NORMAL),
      runType(RunType::ZERO),
      playedBy(nullptr),
      bowledBy(nullptr),
      wicket(nullptr) {
    // register observers here (concrete types included in this .cpp)
    scoreUpdaterObserverList.push_back(new BowlingScoreUpdater());
    scoreUpdaterObserverList.push_back(new BattingScoreUpdater());

    // Initialize RNG once per object; consider moving to program init
    std::srand((unsigned)std::time(nullptr));
}

BallDetails::~BallDetails() {
    for (auto* observer : scoreUpdaterObserverList) {
        delete observer;
    }
    scoreUpdaterObserverList.clear();

    delete wicket;
    wicket = nullptr;
}

void BallDetails::startBallDelivery(Team* battingTeam, Team* bowlingTeam, OverDetails* over) {
    playedBy = battingTeam->getStriker();
    bowledBy = over->bowledBy;
    ballType = BallType::NORMAL;

    if (isWicketTaken()) {
        handleWicket(battingTeam, bowlingTeam, over);
    } else {
        handleRuns(battingTeam);
    }

    notifyUpdaters();
}

void BallDetails::handleWicket(Team* battingTeam, Team* bowlingTeam, OverDetails* over) {
    runType = RunType::ZERO;
    wicket = new Wicket(WicketType::BOLD, playedBy, over, this);
    battingTeam->setStriker(nullptr);
}

void BallDetails::handleRuns(Team* battingTeam) {
    runType = getRunType();

    if (runType == RunType::ONE || runType == RunType::THREE) {
        PlayerDetails* temp = battingTeam->getStriker();
        battingTeam->setStriker(battingTeam->getNonStriker());
        battingTeam->setNonStriker(temp);
    }
}

void BallDetails::notifyUpdaters() {
    for (auto* observer : scoreUpdaterObserverList) {
        observer->update(this);
    }
}

RunType BallDetails::getRunType() {
    double val = static_cast<double>(std::rand()) / RAND_MAX;
    if (val <= 0.2) return RunType::ONE;
    else if (val <= 0.4) return RunType::TWO;
    else if (val <= 0.6) return RunType::THREE;
    else if (val <= 0.8) return RunType::FOUR;
    else return RunType::SIX;
}

bool BallDetails::isWicketTaken() {
    return static_cast<double>(std::rand()) / RAND_MAX < 0.2;
}
