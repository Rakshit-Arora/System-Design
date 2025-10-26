#include "bowlingScoreUpdater.h"
#include "../Inning/ballDetails.h"
#include "../Team/Player/playerDetails.h"

void BowlingScoreUpdater::update(BallDetails* ballDetails) {
    if (ballDetails == nullptr || ballDetails->bowledBy == nullptr) return;

    auto& bowlingScore = ballDetails->bowledBy->bowlingScoreCard;

    if (ballDetails->ballNumber == 6 && ballDetails->ballType == BallType::NORMAL) {
        // over finished logic if any (example)
    }

    switch (ballDetails->runType) {
        case RunType::ONE:   bowlingScore->runsGiven += 1; break;
        case RunType::TWO:   bowlingScore->runsGiven += 2; break;
        case RunType::THREE: bowlingScore->runsGiven += 3; break;
        case RunType::FOUR:  bowlingScore->runsGiven += 4; break;
        case RunType::SIX:   bowlingScore->runsGiven += 6; break;
        default: break;
    }

    if (ballDetails->wicket != nullptr) {
        bowlingScore->wicketsTaken++;
    }

    if (ballDetails->ballType == BallType::NOBALL) {
        bowlingScore->noBallCount++;
    }
    if (ballDetails->ballType == BallType::WIDEBALL) {
        bowlingScore->wideBallCount++;
    }
}