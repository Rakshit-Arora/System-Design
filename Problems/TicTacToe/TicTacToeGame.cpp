#include "Model/ticTacToeGame.h"
#include <iostream>
using namespace std;

TicTacToeGame::TicTacToeGame(int size, vector<Player>& p): board(size), players(p) {};

void TicTacToeGame:: play() {
    int current = 0;
    board.display();

    while(true) {
        Player p = players[current];
       
        cout<<p.getName()<<"'s turn ("<<p.getPiece()->getSymbol()<<"). Enter row and column: ";
        int r, c;
        cin>>r>>c;
        r--; c--; // Convert to 0-based indexing

        if(!board.placePiece(r, c, p.getPiece())) {
            cout<<"Invalid move. Try again."<<endl;
            continue;
        }

        board.display();

        if(board.checkWin(r, c, p.getPiece())) {
            cout<<p.getName()<<" wins!"<<endl;
            return;
        }

        if(board.isFull()) {
            cout<<"It's a draw!"<<endl;
            return;
        }

        current = (current + 1) % players.size();
    }
}