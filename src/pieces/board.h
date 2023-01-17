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
        bool isSquareOccupied(pair <int, int> coordinates) const;
        bool isSquareOccupiedSameColor(pair <int, int> startCoor, pair <int, int> endCoor) const;
        bool isSquareOccupiedDifferentColor(pair <int, int> startCoor, pair <int, int> endCoor) const;
        // Required checks for moves
        bool isCourseClear(pair <int, int> startCoor, pair <int, int> endCoor) const;
        bool isMoveVertical(pair <int, int> startCoor, pair <int, int> endCoor) const;
        bool isMoveHorizontal(pair <int, int> startCoor, pair <int, int> endCoor) const;
        bool isMoveForward(pair <int, int> startCoor, pair <int, int> endCoor) const;
        bool isMoveDiagonal(pair <int, int> startCoor, pair <int, int> endCoor) const;
        bool isMoveLegal(pair <int, int> startCoor, pair <int, int> endCoor);
        // Required calculations for move checks
        int courseDistance(pair <int, int> startCoor, pair <int, int> endCoor) const;

        void printBoardOnConsole();
    private:
        map <pair <int, int>, Square*> board;
};
#endif