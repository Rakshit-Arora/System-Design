#pragma once
#include "board.h"
#include "player.h"
#include "dice.h"
#include <iostream>
#include <deque>
using namespace std;

class Game {
private:
    Board* board;
    Dice* dice;
    Player* winner;
    deque<Player*> playerList; 

    void initialiseGame() {
        board = new Board(10, 5, 4);
        dice = new Dice(1);
        winner = nullptr;

        playerList.push_back(new Player("p1"));
        playerList.push_back(new Player("p2"));
    }

    Player* findPlayerTurn() {
        Player* turn = playerList.front();
        playerList.pop_front();
        playerList.push_back(turn);

        return turn;
    }

    int jumpCheck(int pos) {
        int boardSize = board -> cells.size() * board -> cells.size();

        if(pos >= boardSize) return pos;

        Cell& cell = board -> getCell(pos);

        if(cell.jump && cell.jump->start == pos) {
            string type = (cell.jump->start < cell.jump->end) ? "Ladder" : "Snake";
            cout << "Hit a " << type << "! Moving to " << cell.jump->end << "\n";
            return cell.jump->end;
        }
    
        // If no jump found
        return pos;
    }

public: 
    Game() {
        initialiseGame();
    }

    void startGame() {
        while(!winner) {
            Player* playerTurn = findPlayerTurn();
            cout << "Player turn: " << playerTurn->id << " current position: " << playerTurn->currentPos << "\n";

            int diceRoll = dice -> rollDice();
            int newPos = playerTurn -> currentPos + diceRoll;

            //To check if there is a Snake or Ladder present at new Position
            newPos = jumpCheck(newPos);

            playerTurn -> currentPos = newPos;

            cout << "Player: " << playerTurn->id << " moved to: " << newPos << "\n";

             if (newPos >= (board->cells.size() * board->cells.size() - 1)) {
                winner = playerTurn;
            }
        }

        cout << "WINNER IS: " << winner->id << "\n";
    }
};