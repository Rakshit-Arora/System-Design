#include "playingPiece.h"
#include <string>
#include <vector>
using namespace std;

class Board {
    private:
        int size;
        vector<vector<PlayingPiece*>> grid;
        int filled;
    
    public:
        Board(int n);

        bool placePiece(int r, int c, PlayingPiece* piece);
        bool isFull();
        bool checkWin(int r, int c, PlayingPiece* piece);
        void display();
        bool inBounds(int r, int c);
};