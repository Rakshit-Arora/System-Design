#pragma once
class BallDetails;

class ScoreUpdaterObserver {
public:
    virtual void update(BallDetails* ballDetails) = 0;
    virtual ~ScoreUpdaterObserver() = default;
};