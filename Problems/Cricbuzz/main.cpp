#include "./Team/Player/person.h"
#include "./Team/Player/playerDetails.h"
#include "./Team/Player/playerType.h"
#include "./Team/team.h"
#include "match.h"
#include "matchType.h"
#include "t20MatchType.h"
#include <vector>
#include <queue>
using namespace std;

class Main {
public:
    static int main() {
        Main ob;

        Team* teamA = ob.addTeam("India");
        Team* teamB = ob.addTeam("Australia");

        MatchType* matchType = new T20MatchType();
        Match* match = new Match(teamA, teamB, time(nullptr), "SMS STADIUM", matchType);
        match -> startMatch();

        delete matchType;
        delete teamA;
        delete teamB;

        return 0;
    }

private:
    Team* addTeam(string name) {
        queue<PlayerDetails*> playerDetailsQueue; 

        //Create 11 Players
        vector<PlayerDetails*> players;

        for(int i = 1; i <= 11; i++) {
            string playerName = name + to_string(i);
            PlayerDetails* p = addPlayer(playerName, PlayerType::ALLROUNDER);
            players.push_back(p);
            playerDetailsQueue.push(p);
        }

        vector<PlayerDetails*> bowlers = {
            players[7], players[8], players[9], players[10]
        };
        
        Team* team = new Team(name, playerDetailsQueue, {}, bowlers);
        return team;
    }

    PlayerDetails* addPlayer(string playerName, PlayerType playerType) {
        Person* person = new Person();
        person -> name = playerName;
        PlayerDetails* pd = new PlayerDetails(person, playerType);
        return pd;
    }
}; 

int main() {
    return Main:: main();
}
