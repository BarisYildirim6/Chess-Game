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
        // Placement of pieces
        bool placePawns();
        // Required checks for squares
        bool isSquareOccupied(pair <int, int> coordinates);
        bool isSquareOccupiedSameColor(pair <int, int> startCoor, pair <int, int> endCoor);
        bool isSquareOccupiedDifferentColor(pair <int, int> startCoor, pair <int, int> endCoor);
        // Required checks for moves
        bool isCourseClear(pair <int, int> startCoor, pair <int, int> endCoor);
        bool isMoveVertical(pair <int, int> startCoor, pair <int, int> endCoor);
        bool isMoveHorizontal(pair <int, int> startCoor, pair <int, int> endCoor);
        bool isMoveForward(pair <int, int> startCoor, pair <int, int> endCoor);
        bool isMoveDiagonal(pair <int, int> startCoor, pair <int, int> endCoor);
        bool isMoveLegal(pair <int, int> startCoor, pair <int, int> endCoor);
        // Required calculations for move checks
        int courseDistance(pair <int, int> startCoor, pair <int, int> endCoor);

        void printBoardOnConsole();
    private:
        map<pair<int, int>, Square*> board;
};
#endif