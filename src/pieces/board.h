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
        bool isMoveKnight(pair <int, int> startCoor, pair <int, int> endCoor) const;
        bool isMoveLegal(pair <int, int> startCoor, pair <int, int> endCoor)const;
        // Required calculations for move checks
        int courseDistance(pair <int, int> startCoor, pair <int, int> endCoor) const;
        // Moving pieces    
        bool movePiece(pair <int, int> startCoor, pair <int, int> endCoor) const;
        // Move conversions
        string coordinateToNotation(pair <int, int> coordinates) const;
        pair <int, int> notationToCoordinate(string notation) const;
        
        void printBoardOnConsole();
    private:
        map <pair <int, int>, Square*> board;

        // Placement of pieces
        bool setupSquares();
        bool placePiece(Piece* piece, pair <int, int>);
        bool placePawns();
        bool placeBishops();
        bool placeKnights();
        bool placeRooks();
        bool placeQueens();
        bool placeKings();
};
#endif