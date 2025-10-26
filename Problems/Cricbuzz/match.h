#pragma once
#include "./Inning/inningDetails.h"
#include "./Team/team.h"
#include "matchType.h"
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class Match {
public:
    Team* teamA;
    Team* teamB;
    time_t matchDate;
    string venue;
    Team* tossWinner;
    InningDetails* innings[2];
    MatchType* matchType;

    Match(Team* teamA, 
        Team* teamB, 
        time_t matchDate, 
        string venue, 
        MatchType* matchType)
    : 
        teamA(teamA),
        teamB(teamB), 
        matchDate(matchDate),
        venue(venue),
        matchType(matchType) {
            innings[0] = nullptr;
            innings[1] = nullptr;
            srand(time(nullptr));
        }
    
    void startMatch() {
        // Toss
        tossWinner = toss(teamA, teamB);

        //Start the inning, 2 innings in a match
        for(int inning = 1; inning <= 2; inning++) {
            InningDetails* inningDetails;
            Team* bowlingTeam;
            Team* battingTeam;

            //assuming batfirst -> tosswinner
            bool isChasing = false;
            if(inning == 1) {
                battingTeam = tossWinner;
                bowlingTeam = (tossWinner -> getTeamName() == teamA -> getTeamName()) ? teamB : teamA;
                inningDetails = new InningDetails(battingTeam, bowlingTeam, matchType);
                inningDetails->start(-1);
            }
            else {
                bowlingTeam = tossWinner;
                battingTeam = (tossWinner -> getTeamName() == teamA -> getTeamName()) ? teamB : teamA;
                inningDetails -> start(innings[0] -> getTotalRuns());

                if(bowlingTeam -> getTotalRuns () > battingTeam -> getTotalRuns()) {
                    bowlingTeam -> isWinner = true;
                }
            }

            innings[inning-1] = inningDetails;

            //Printing Inning Details
            cout<<"Inning " << inning << " -- total Run: " <<battingTeam -> getTotalRuns() << endl;
            cout<<"--- Batting ScoreCard: " << battingTeam -> teamName << endl;
            battingTeam -> printBattingScoreCard();

            cout<<endl<<"--- Bowling ScoreCard: " << bowlingTeam -> teamName <<endl;
            bowlingTeam -> printBowlingScoreCard();
        }cout<<endl;

        if(teamA -> isWinner) {
            cout<<"--- WINNER ---" << teamA -> teamName << endl;
        }
        else {
            cout<<"--- WINNER ---" << teamB -> teamName << endl;
        }
    }

private:
    Team* toss(Team* teamA, Team* teamB) {
        return (rand() % 2 == 0) ? teamA : teamB;
    }
};