#include <iostream>
using namespace std;

#include "piece.h"

Piece::Piece(Type type, Color color) {
    pieceColor = color;
    pieceType = type;
}

Piece::~Piece() {

}

void Piece::setColor(Color color) {
    pieceColor = color;
}

void Piece::setType(Type type) {
    pieceType = type;
}

char Piece::getColor() {
    return pieceColor;
}

char Piece::getType() {
    return typeToChar(pieceType);
}

char Piece::typeToChar(Type type) const {
    switch (type)
    {
    case pawn: return 'P'; 
    case knight: return 'N';
    case bishop: return 'B';
    case rook: return 'R';
    case queen: return 'Q';
    case king: return 'K';
    default: return ' ';
    }
}

char Piece::colorToChar(Color color) const {
    switch (color) {
        case white: return 'W';
        case black: return 'B';
        default: return ' ';
    }
}