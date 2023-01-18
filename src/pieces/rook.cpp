#include <iostream>
#include "rook.h"

Rook::Rook(Color c) : Piece(rook, c) {

}

bool Rook::isMoveValid(const Board *board, pair <int, int> startCoor, pair <int, int> endCoor) const {
    if (board->isMoveHorizontal(startCoor, endCoor)) {
        if (board->isCourseClear(startCoor, endCoor)) {
            return true;
        }
    }
    return false;
}