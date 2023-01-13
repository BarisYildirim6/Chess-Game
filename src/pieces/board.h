#ifndef BOARD_H
#define BOARD_H
#include <iostream>
using namespace std;

#include "square.h"
#include <map>

class Piece;

class Board {
    public: 
        Board();

        bool placePiece(Piece* piece, pair <int, int>);
        
        bool placePawns();
        void printBoardOnConsole();
    private:
        map<pair<int, int>, Square*> board;
};
#endif