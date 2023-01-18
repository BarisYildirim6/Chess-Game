#include <iostream>
#include <map>
#include "board.h"
#include "piece.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "king.h"
using namespace std;

Board::Board() {
    setupSquares();
    placePawns();
    placeKnights();
    placeBishops();
    placeRooks();
    placeQueens();
    placeKings();
}

bool Board::setupSquares() {
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
        placePiece(pw ,make_pair(6, i));
        placePiece(pb, make_pair(1, i));
    }
}

bool Board::placeBishops() {
    Bishop* bwr = new Bishop(white);
    Bishop* bwl = new Bishop(white);
    Bishop* bbr = new Bishop(black);
    Bishop* bbl = new Bishop(black);

    placePiece(bwr, make_pair(7, 5));
    placePiece(bwl, make_pair(7, 2));
    placePiece(bbr, make_pair(0, 5));
    placePiece(bbl, make_pair(0, 2));
}

bool Board::placeKnights() {
    Knight* kwr = new Knight(white);
    Knight* kwl = new Knight(white);
    Knight* kbr = new Knight(black);
    Knight* kbl = new Knight(black);

    placePiece(kwr, make_pair(7, 6));
    placePiece(kwl, make_pair(7, 1));
    placePiece(kbr, make_pair(0, 6));
    placePiece(kbl, make_pair(0, 1));
}

bool Board::placeRooks() {
    Rook* rwr = new Rook(white);
    Rook* rwl = new Rook(white);
    Rook* rbr = new Rook(black);
    Rook* rbl = new Rook(black);

    placePiece(rwr, make_pair(7, 7));
    placePiece(rwl, make_pair(7, 0));
    placePiece(rbr, make_pair(0, 7));
    placePiece(rbl, make_pair(0, 0));
}

bool Board::placeQueens() {
    Quenn* qw = new Quenn(white);
    Quenn* qb = new Quenn(black);

    placePiece(qw, make_pair(7,3));
    placePiece(qw, make_pair(0,3));
}

bool Board::placeKings() {
    King* kw = new King(white);
    King* kb = new King(black);

    placePiece(kw, make_pair(7,4));
    placePiece(kw, make_pair(0,4));
}

bool Board::isSquareOccupied(pair <int, int> coordinates) const {
    return board.at(coordinates)->getPiece() != NULL;
}

bool Board::isSquareOccupiedSameColor(pair <int, int> startCoor, pair <int, int> endCoor) const {
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

bool Board::isSquareOccupiedDifferentColor(pair <int, int> startCoor, pair <int, int> endCoor) const {
    Piece* start = board.at(startCoor)->getPiece();
    Piece* end = board.at(endCoor)->getPiece();
    
    // Checks if pieces exist on both squares
    if (start == NULL || end == NULL) {
        return false;
    } else {
        // Checks is the pieces are different color
        return (start->getColor() != end->getColor());
    }
}

bool Board::isCourseClear(pair <int, int> startCoor, pair <int, int> endCoor) const {
    // Does piece move 
    bool isMovePosY = startCoor.first > endCoor.first;
    // Does piece move from top to bottom
    bool isMovePosX = startCoor.second < endCoor.second;

    int distance = courseDistance(startCoor, endCoor);

    if (distance == 1 || distance == 0) {
        return true;
    }

    if (isMoveVertical(startCoor, endCoor)) {
        if (isMovePosY) {
            for (int i = startCoor.first - 1; i > endCoor.first; i--) {
                if (isSquareOccupied(make_pair(i, startCoor.second))) {
                    return false;
                }
            }
        } else {
            for (int i = startCoor.first + 1; i < endCoor.first; i++) {
                if (isSquareOccupied(make_pair(i, startCoor.second))) {
                    return false;
                }
            }
        }
        return true;
    }

    if (isMoveHorizontal(startCoor, endCoor)) {
        if (isMovePosX) {
            for (int i = startCoor.second + 1; i < endCoor.second; i++) {
                if (isSquareOccupied(make_pair(i, startCoor.second))) {
                    return false;
                }
            }
        } else {
            for (int i = startCoor.second - 1; i > endCoor.second; i--) {
                if (isSquareOccupied(make_pair(i, startCoor.second))) {
                    return false;
                }
            }
        }
        return true;
    }

    if (isMoveDiagonal(startCoor, endCoor)) {
        if (isMovePosX && isMovePosY) {
            for (int i = startCoor.first - 1, j = startCoor.second + 1; i > endCoor.first && j < endCoor.second; i--, j++) {
                if (board.at(make_pair(i, j))->getPiece() != NULL) {
                    return false;
                }
            }
        } else if (isMovePosX) {
            for (int i = startCoor.first + 1, j = startCoor.second + 1; i <= endCoor.first && j <= endCoor.second; i++, j++) {
                if (board.at(make_pair(i, j))->getPiece() != NULL) {
                    return false;
                }
            }
        } else if (isMovePosY) {
            for (int i = startCoor.first - 1, j = startCoor.second - 1; i > endCoor.first && j > endCoor.second; i--, j--) {
                if (board.at(make_pair(i, j))->getPiece() != NULL) {
                    return false;
                }
            }
        } else {
            for (int i = startCoor.first + 1, j = startCoor.second - 1; i < endCoor.first && j > endCoor.second; i++, j--) {
                if (board.at(make_pair(i, j))->getPiece() != NULL) {
                    return false;
                }
            }
        }
        return true;
    }

    return false;
}

bool Board::isMoveVertical(pair <int, int> startCoor, pair <int, int> endCoor) const {
    return (startCoor.second == endCoor.second && startCoor.first != endCoor.first);
}

bool Board::isMoveHorizontal(pair <int, int> startCoor, pair <int, int> endCoor) const {
    return (startCoor.second != endCoor.second && startCoor.first == endCoor.first);
}

bool Board::isMoveForward(pair <int, int> startCoor, pair <int, int> endCoor) const {
    // For white pieces, moving towards y is forward
    // For black pieces, moving towards -y is forward
    if (board.at(startCoor)->getPiece()->getColor() == white) {
        return (endCoor.first < startCoor.first);
    } else if (board.at(startCoor)->getPiece()->getColor() == black) {
        return (endCoor.first > startCoor.first);
    }
    return false;
}

bool Board::isMoveDiagonal(pair <int, int> startCoor, pair <int, int> endCoor) const {
    int xPath, yPath;

    xPath = startCoor.second - endCoor.second;
    yPath = startCoor.first - endCoor.first;

    return abs(xPath) == abs(yPath);
}

bool Board::isMoveKnight(pair <int, int> startCoor, pair <int, int> endCoor) const {
    if (abs(startCoor.first - endCoor.first) == 2) {
        if (abs(startCoor.second - endCoor.second) == 1) {
            return true;
        }
    }
    if (abs(startCoor.second - endCoor.second) == 2) {
        if (abs(startCoor.first - endCoor.first) == 1) {
            return true;
        }
    }
    return false;
}

bool Board::isMoveLegal(pair <int, int> startCoor, pair <int, int> endCoor) const {
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

    if (!movingPiece->isMoveValid(this, startCoor, endCoor)) {
        return false;
    }

    return true;
}

int Board::courseDistance(pair <int, int> startCoor, pair <int, int> endCoor) const {
    if (isMoveVertical(startCoor, endCoor)) {
        return abs(endCoor.first - startCoor.first);
    } else if (isMoveHorizontal(startCoor, endCoor)) {
        return abs(endCoor.second - startCoor.second);
    } else if (isMoveDiagonal(startCoor, endCoor)) {
        return abs(endCoor.second - startCoor.second);
    }
    return -1;
}

bool Board::movePiece(pair <int, int> startCoor, pair <int, int> endCoor) const {
    if (startCoor == endCoor) {
        return false;
    }

    if (isMoveLegal(startCoor, endCoor)) {

        // If the move is a capture
        if (board.at(endCoor)->getPiece() != NULL) {

        }
        // Piece at starting coordinates
        Piece* p = board.at(startCoor)->setPiece(NULL);
        board.at(endCoor)->setPiece(p);
        board.at(endCoor)->getPiece()->increaseMoves();
        return true;
    }

    return false;
}

string Board::coordinateToNotation(pair <int, int> coordinates) const {
    string notation = "";
    char row = static_cast<char>(8 - coordinates.first + '0');
    char col = static_cast<char>(coordinates.second + 'a');
    notation = string() + col + row;
    return notation;
}

pair <int, int> Board::notationToCoordinate(string notation) const {
    int row = 8 - (notation[1] - '0');
    int col = notation[0] - 'a';
    return make_pair(row, col);
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