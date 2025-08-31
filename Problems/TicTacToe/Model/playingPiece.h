#pragma once
#include "pieceType.h"
#include <string>
using namespace std;

class PlayingPiece 
{
    protected:
        PieceType type;
    public:
        PlayingPiece(PieceType t): type(t) {}
        virtual ~PlayingPiece() = default;

        virtual string getSymbol() const = 0;
};