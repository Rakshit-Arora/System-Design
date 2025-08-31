#pragma once
#include "playingPiece.h"
using namespace std;

class PieceO : public PlayingPiece
{
    public:
        PieceO() : PlayingPiece(PieceType::O) {}
        string getSymbol() const override { return "O"; }
};
