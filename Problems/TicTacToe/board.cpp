#include <iostream>
#include "Model/board.h"
using namespace std;

Board:: Board(int n): size(n), filled(0) {
    grid.assign(n, vector<PlayingPiece*>(n, nullptr));
}

bool Board:: placePiece(int r, int c, PlayingPiece* piece) {
    if(!inBounds(r, c)) return false;
    if(grid[r][c] != nullptr) return false;
    grid[r][c] = piece;
    filled++;

    return true;
}

bool Board:: isFull() {
    return filled == size * size;
}

bool Board:: checkWin(int r, int c, PlayingPiece* piece) {
    string sym = piece->getSymbol();

    // Check row
    bool win = true;
    for(int j = 0; j < size; j++) {
        if(grid[r][j] == nullptr || grid[r][j]->getSymbol() != sym) {
            win = false;
            break;
        }
    }

    if(win) return true;

    // check column
    win = true;
    for(int i = 0; i < size; i++) {
        if(grid[i][c] == nullptr || grid[i][c]->getSymbol() != sym) {
            win = false;
            break;     
        }
    }

    if(win) return true;

    // check main diagonal
    if(r == c) {
        win = true;
        for(int i = 0; i < size; i++) {
            if(grid[i][i] == nullptr || grid[i][i]->getSymbol() != sym) {
                win = false;
                break; 
            }
        }

        if(win) return true;
    }

    // check anti diagonal
    if(r + c == size - 1) {
        win = true;
        for(int i = 0; i < size; i++) {
            int j = size - 1 - i;
            if(grid[i][j] == nullptr || grid[i][j]->getSymbol() != sym) {
                win = false;
                break;
            }
        }

        if(win) return true;
    }

    return false;
}

bool Board:: inBounds(int r, int c) {
    return r >= 0 && r < size && c >= 0 && c < size;
}

void Board:: display() {
    cout<<endl;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout<<" "<<(grid[i][j] ? grid[i][j]->getSymbol() : " ")<<" ";
            if(j != size - 1) cout<<"|";
        }
        cout<<endl;

        if(i != size - 1) {
            for(int k = 0; k < size; k++) {
                cout<<"----";
                if(k != size - 1) cout<<"+";
            }
            cout<<endl;
        }
    }

    cout<<endl;
}