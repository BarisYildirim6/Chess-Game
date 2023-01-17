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
        placePiece(pw ,make_pair(6, i));
        placePiece(pb, make_pair(1, i));
    }
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