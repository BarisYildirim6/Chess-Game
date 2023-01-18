#include <iostream>
#include "knight.h"

Knight::Knight(Color c) : Piece(knight, c) {

}

bool Knight::isMoveValid(const Board *board, pair <int, int> startCoor, pair <int, int> endCoor) const {
    if (board->isMoveKnight(startCoor, endCoor)) {
        return true;
    }
    return false;
}