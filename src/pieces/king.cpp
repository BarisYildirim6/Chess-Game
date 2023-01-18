#include <iostream>
#include "king.h"

King::King(Color c) : Piece(king, c) {

}

bool King::isMoveValid(const Board *board, const std::pair<int, int> startCoor, const std::pair<int, int> endCoor) const {
    if (board->courseDistance(startCoor, endCoor) == 1) {
        return true;
    }
    return false;
}