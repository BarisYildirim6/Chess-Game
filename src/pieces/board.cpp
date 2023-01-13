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
        Pawn* p = new Pawn(white);
        placePiece(p ,make_pair(1, i));

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