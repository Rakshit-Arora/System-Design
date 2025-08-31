#include <iostream>
#include "Model/ticTacToeGame.h"
#include "Model/pieceX.h"
#include "Model/pieceO.h"
using namespace std;

int main() {
    int size;
    cout<<"Enter board size (3 for default): ";
    if(!(cin>>size) || size < 3) size = 3;

    string p1, p2;
    cout<<"Enter name for Player 1: ";
    cin>>p1;
    cout<<"Enter name for Player 2: ";
    cin>>p2;

    PieceX x;
    PieceO o;
    Player player1(p1, &x);
    Player player2(p2, &o);

    vector<Player> players = {player1, player2};
    TicTacToeGame game(size, players);
    game.play();

    return 0;
}