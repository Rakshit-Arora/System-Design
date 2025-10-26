#include "battingScoreUpdater.h"
#include "../Inning/ballDetails.h"
#include "../Team/Player/playerDetails.h"

void BattingScoreUpdater::update(BallDetails* ballDetails) {
    if (ballDetails == nullptr || ballDetails->playedBy == nullptr) return;

    int run = 0;
    auto& battingScore = ballDetails->playedBy->battingScoreCard;

    switch (ballDetails->runType) {
        case RunType::ONE:   run = 1; break;
        case RunType::TWO:   run = 2; break;
        case RunType::THREE: run = 3; break;
        case RunType::FOUR:  run = 4; battingScore->totalFours++; break;
        case RunType::SIX:   run = 6; battingScore->totalSix++; break;
        default: break;
    }

    battingScore->totalRuns += run;
    battingScore->totalBallsPlayed++;

    if (ballDetails->wicket != nullptr) {
        battingScore->wicketDetails = ballDetails->wicket;
    }
}