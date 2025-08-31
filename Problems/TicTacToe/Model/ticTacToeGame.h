#pragma once
#include "player.h"
#include "board.h"
#include <vector>
using namespace std;

class TicTacToeGame {
    private:
        Board board;
        vector<Player> players;

    public:
        TicTacToeGame(int size, vector<Player>& p);
        void play();
};