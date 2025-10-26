#pragma once
#include "scoreUpdaterObserver.h"
#include "../Inning/runType.h"

class BallDetails;

class BattingScoreUpdater : public ScoreUpdaterObserver {
public:
    void update(BallDetails* ballDetails) override;
};