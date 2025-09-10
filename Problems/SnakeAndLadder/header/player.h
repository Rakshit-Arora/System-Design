#pragma once
#include <string>
using namespace std;

class Player {
public: 
    string id;
    int currentPos;

    Player(string id, int pos = 0): id(id), currentPos(pos) {};
};