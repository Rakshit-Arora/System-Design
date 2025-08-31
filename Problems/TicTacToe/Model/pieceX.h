#pragma once
#include "playingPiece.h"

class PieceX : public PlayingPiece
{
    public:
        PieceX(): PlayingPiece(PieceType::X) {}
        string getSymbol() const override { return "X"; }
};