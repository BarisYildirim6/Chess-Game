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

        bool isSquareOccupied(pair <int, int> coordinates);
        bool isSquareOccupiedSameColor(pair <int, int> startCoor, pair <int, int> endCoor);
        bool isSquareOccupiedDifferentColor(pair <int, int> startCoor, pair <int, int> endCoor);
        bool isMoveValid(pair <int, int> startCoor, pair <int, int> endCoor);

        void printBoardOnConsole();
    private:
        map<pair<int, int>, Square*> board;
};
#endif