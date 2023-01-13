#include <iostream>
#include "pawn.h"

Pawn::Pawn(Color c) : Piece(pawn, c) {
    isFirst = true;
}

void Pawn::setIsFirst(bool first) {
    isFirst = first;
}