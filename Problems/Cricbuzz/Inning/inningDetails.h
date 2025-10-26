#pragma once
#include "../matchType.h"
#include "../Team/Player/playerDetails.h"
#include "../Team/team.h"
#include "overDetails.h"
#include "ballDetails.h"
#include <vector>
#include <iostream>

class InningDetails {
private:
    Team* battingTeam;
    Team* bowlingTeam;
    MatchType* matchType;
    vector<OverDetails*> overs;

public:
    InningDetails(Team* battingTeam, 
        Team* bowlingTeam, 
        MatchType* matchType) 
    : battingTeam(battingTeam),
      bowlingTeam(bowlingTeam),
      matchType(matchType) {}

    void start(int runsToWin) {
        try{
            battingTeam -> chooseNextBatsMan();
        }catch(const exception& e) {
            cout<<"Error :" << e.what() << endl;
        }

        int noOfOvers = matchType -> noOfOvers();
        int maxOverCountPerBowler = matchType->maxOverCountBowlers();

        for(int overNumber = 1; overNumber <= noOfOvers; overNumber++) {
            // chooseBowler
           try {
                bowlingTeam->chooseNextBowler(maxOverCountPerBowler);
            } catch (const std::exception& e) {
                cout << "No bowlers available for over " << overNumber << endl;
                break; // end inning
            }

            OverDetails* over = new OverDetails(overNumber, bowlingTeam -> getCurrentBowler());
            overs.push_back(over);

            try{
                bool won = over -> startOver(battingTeam, bowlingTeam, runsToWin, maxOverCountPerBowler);

                if(won == true) break;
            }catch (exception& e) {
                break;
            }

            PlayerDetails* temp = battingTeam -> getStriker();
            battingTeam -> setStriker(battingTeam -> getNonStriker());
            battingTeam -> setNonStriker(temp);
        }
    }

    int getTotalRuns() {
        return battingTeam -> getTotalRuns();
    }
};