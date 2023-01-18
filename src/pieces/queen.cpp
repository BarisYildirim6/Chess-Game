#include <iostream>
#include "queen.h"

Quenn::Quenn(Color c) : Piece(queen, c) {

}

bool Quenn::isMoveValid(const Board *board, pair <int, int> startCoor, pair <int, int> endCoor) const {
    if (board->isMoveDiagonal(startCoor, endCoor) || board->isMoveVertical(startCoor, endCoor) || board->isMoveHorizontal(startCoor, endCoor)) {
        if (board->isCourseClear(startCoor, endCoor)) {
            return true;
        }
    }
    return false;
}