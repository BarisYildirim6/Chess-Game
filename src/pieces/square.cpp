#include "square.h"

Square::Square(SquareColor color) {
    c = color;
    curPiece = NULL;
}

Piece* Square::setPiece(Piece* piece) {
    Piece* oldPiece = curPiece;
    curPiece = piece;
    return oldPiece;
}

Piece* Square::getPiece() {
    return curPiece;
}

void Square::setColor(SquareColor color) {
    c = color;
}

char Square::getColor() {
    return squareColorToChar(c);
}

char Square::squareColorToChar(SquareColor color) const {
    switch (color)
    {
    case whiteS: return 'W';
    case blackS: return 'B';
    default: return ' ';
    }
}