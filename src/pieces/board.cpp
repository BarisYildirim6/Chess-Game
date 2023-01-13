#include <iostream>
#include <map>
#include "board.h"
#include "piece.h"
#include "pawn.h"
using namespace std;

Board::Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 != 0) && (j % 2 != 0))) {
                board.insert(pair <pair <int, int>, Square*> (make_pair(i, j), new Square(whiteS)));
            } else {
                board.insert(pair <pair <int, int>, Square*> (make_pair(i, j), new Square(blackS)));
            }
        }
    }
}

bool Board::placePiece(Piece* piece, pair <int, int> coordinates) {
    Square* curSquare = board.at(coordinates);
    if (piece != NULL) {
        curSquare->setPiece(piece);
        return true;
    } else {
        return false;
    }
}

bool Board::placePawns() {
    for (int i = 0; i < 8; i++) {
        Pawn* pw = new Pawn(white);
        Pawn* pb = new Pawn(black);
        placePiece(pw ,make_pair(1, i));
        placePiece(pb, make_pair(6, i));
    }
}

bool Board::isSquareOccupied(pair <int, int> coordinates) {
    return board.at(coordinates)->getPiece() != NULL;
}

bool Board::isSquareOccupiedSameColor(pair <int, int> startCoor, pair <int, int> endCoor) {
    Piece* start = board.at(startCoor)->getPiece();
    Piece* end = board.at(endCoor)->getPiece();
    
    // Checks if pieces exist on both squares
    if (start == NULL || end == NULL) {
        return false;
    } else {
        // Checks is the pieces are same color
        return (start->getColor() == end->getColor());
    }
}

bool Board::isMoveValid(pair <int, int> startCoor, pair <int, int> endCoor) {
    // Checks if starting coordinates are on board
    if (startCoor.first < 0 || startCoor.first > 7 || endCoor.second < 0 || startCoor.second > 7) {
        return false;
    }

    // Checks if the ending coordinates are on board
    if (endCoor.first < 0 || endCoor.first > 7 || endCoor.second < 0 || endCoor.second > 7) {
        return false;
    }

    Piece* movingPiece = board.at(startCoor)->getPiece();
    // Checks if the piece exist on the square of starting coordinates
    if (movingPiece == NULL) {
        return false;
    }

    // Checks if ending coordinates include a piece with same color as the piece on starting coordinates
    if (isSquareOccupiedSameColor(startCoor, endCoor)) {
        return false;
    }

}

void Board::printBoardOnConsole() {
    cout << "   A   B   C   D   E   F   G   H" << endl;
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << 8 - i << "  ";

        for (int j = 0; j < 8; j++) {
            Square* curSquare = board.at(make_pair(i, j));
            if (j == 7) {
                if (curSquare->getPiece() != NULL) {
                    cout << curSquare->getPiece()->getType();
                } else {
                    cout << " ";
                }
            } else {
                if (curSquare->getPiece() != NULL) {
                    cout << curSquare->getPiece()->getType() << " | ";
                } else {
                    cout << "  | ";
                }
            }
        }
        cout << endl;
        cout << "   -- --- --- --- --- --- --- --" << endl;
    }
}