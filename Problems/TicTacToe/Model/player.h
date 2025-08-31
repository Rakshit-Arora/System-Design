#pragma once
#include "playingPiece.h"
#include <string>
using namespace std;


class Player {
    private:
        string name;
        PlayingPiece* piece; // Pointer to the player's piece (X or O)
    public:
        Player(string& name, PlayingPiece* piece): name(name), piece(piece) {};
        string getName() {return name; }
        PlayingPiece* getPiece() {return piece; }
};