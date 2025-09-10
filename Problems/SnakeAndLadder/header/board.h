#pragma once
#include<vector>
#include <random>
#include "cell.h"
#include "jump.h"
using namespace std;

class Board {
private:
    void initializeCells(int n) {
        cells.resize(n, vector<Cell>(n));
    }

    void addSnakesAndLadders(int nSnakes, int nLadders) {
        mt19937 rng(random_device{}());
        uniform_int_distribution<int> dist(1, cells.size() * cells.size() - 2);

        while(nSnakes > 0) {
            int head = dist(rng);
            int tail = dist(rng);

            if(tail >= head) continue;
            getCell(head).jump = new Jump(head, tail);
            nSnakes--;
        }

        while(nLadders > 0) {
            int start = dist(rng);
            int end = dist(rng);
            if(start >= end) continue;
            getCell(start).jump = new Jump(start, end);
            nLadders--;
        }
    }

public: 
    vector<vector<Cell>> cells;
    
    Board(int boardSize, int nSnakes, int nLadders) {
        initializeCells(boardSize);
        addSnakesAndLadders(nSnakes, nLadders);
    }

    Cell& getCell(int playerPosition) {
        int row = playerPosition / cells.size();
        int col = playerPosition % cells.size();

        return cells[row][col];
    }
};