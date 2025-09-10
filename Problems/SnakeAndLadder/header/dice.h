#pragma once
#include <math.h>
using namespace std;

class Dice {
private:
    int diceCnt;
    int min = 1;
    int max = 6;

public: 
    Dice(int cnt) {
        this -> diceCnt = cnt;
    }

    int rollDice() {
        int totalSum = 0;
        int diceUsed = 0;

        while(diceUsed < diceCnt) {
            totalSum += (rand() % (max - min + 1)) + min;
            diceUsed++;
        }

        return totalSum;
    }
};
