#include <iostream>
#include "bishop.h"

Bishop::Bishop(Color c) : Piece(bishop, c) {

}

bool Bishop::isMoveValid(const Board *board, pair <int, int> startCoor, pair <int, int> endCoor) const {
    if (board->isMoveDiagonal(startCoor, endCoor)) {
        if (board->isCourseClear(startCoor, endCoor)) {
            return true;
        }
    }
    return false;
}