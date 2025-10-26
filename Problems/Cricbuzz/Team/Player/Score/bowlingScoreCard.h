#pragma once

class BowlingScoreCard
{
public:
    int totalOverCount;
    int runsGiven;
    int wicketsTaken;
    int noBallCount;
    int wideBallCount;
    double economyRate;

    BowlingScoreCard() : totalOverCount(0), 
                         runsGiven(0), 
                         wicketsTaken(0), 
                         noBallCount(0), 
                         wideBallCount(0), 
                         economyRate(0.0) {}
};