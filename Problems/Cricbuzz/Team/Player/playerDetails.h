#pragma once
#include "./Score/battingScoreCard.h"
#include "./Score/bowlingScoreCard.h"
#include "person.h"
#include "playerType.h"
#include <iostream>

class PlayerDetails {
public:
    Person* person;
    PlayerType playerType;
    BattingScoreCard* battingScoreCard;
    BowlingScoreCard* bowlingScoreCard;

    PlayerDetails(Person* person, PlayerType playerType) : person(person), 
                                                           playerType(playerType),
                                                           battingScoreCard(new BattingScoreCard()),
                                                           bowlingScoreCard(new BowlingScoreCard()) {}
    
    void pringBattingScoreCard() {
        cout << "PlayerName: " << person->name 
        << " -- totalRuns: " << battingScoreCard -> totalRuns
        << " -- totalBallsPlayed: " << battingScoreCard -> totalBallsPlayed 
        << " -- 4s: " << battingScoreCard -> totalFours 
        << " --6s: " << battingScoreCard -> totalSix 
        << " -- outBy: "
        << ((battingScoreCard -> wicketDetails != nullptr) 
            ? battingScoreCard -> wicketDetails -> takenBy -> person -> name 
            : "notOut") 
        << endl;
    }                
    
    void printBowlingScoreCard() {
        cout << "PlayerName: " << person -> name 
        << "-- totalOversThrown: " << bowlingScoreCard -> totalOverCount 
        << " -- totalRunsGiven: " << bowlingScoreCard -> runsGiven 
        << " -- WicketsTaken: " << bowlingScoreCard -> wicketsTaken 
        << endl;
    }
};