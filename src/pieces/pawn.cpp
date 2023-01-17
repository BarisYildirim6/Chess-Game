#include <iostream>
#include "pawn.h"

Pawn::Pawn(Color c) : Piece(pawn, c) {

}

bool Pawn::isMoveValid(const Board *board, pair <int, int> startCoor, pair <int, int> endCoor) const {
    // Distance between the selected coordinates
    int moveDistance = board->courseDistance(startCoor, endCoor);

    // Pawn cannot move horizontally
    if (board->isMoveHorizontal(startCoor, endCoor)) {
        return false;
    }

    // Pawn cannot move backwards
    if (!board->isMoveForward(startCoor, endCoor)) {
        return false;
    }

    // Pawn can move 1 or 2 squares per move depending on whether it moved before or not
    if (board->isMoveVertical(startCoor, endCoor)) {

        // Pawn cannot move horizontally to an occupied square
        if (board->isSquareOccupied(endCoor)) {
            return false;
        }

        // Pawn can move 2 squares if it has not moved already
        if (moveDistance == 2) {
            if (!isMovedBefore() && board->isCourseClear(startCoor, endCoor)) {
                return true;
            }
        } else if (moveDistance == 1) {
            return true;
        } else {
            return false;
        }
    }

    // Pawn can move diagonally 1 square if it is a capture (different color piece occupies the square)
    if (board->isMoveDiagonal(startCoor, endCoor)) {
        if (moveDistance == 1) {
            // It's a capture
            if (board->isSquareOccupiedDifferentColor(startCoor, endCoor)) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    return false;
}