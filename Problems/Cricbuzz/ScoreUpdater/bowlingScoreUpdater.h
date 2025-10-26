#pragma once
#include "scoreUpdaterObserver.h"
#include "../Inning/ballType.h"
#include "../Inning/runType.h"

class BallDetails;

class BowlingScoreUpdater : public ScoreUpdaterObserver {
public:
    void update(BallDetails* ballDetails) override;
};