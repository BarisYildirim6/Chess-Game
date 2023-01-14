#include <iostream>
#include "pawn.h"

Pawn::Pawn(Color c) : Piece(pawn, c) {

}

bool Pawn::isMoveValid(const Board *board, const std::pair<int, int> startCoor, const std::pair<int, int> endCoor) {
    
}