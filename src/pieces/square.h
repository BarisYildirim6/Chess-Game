#ifndef SQUARE_H
#define SQUARE_H
#include "piece.h"

enum SquareColor {
    whiteS,
    blackS
};

class Square {
    public:
        Square(SquareColor color);
        Piece* setPiece(Piece* piece);
        Piece* getPiece();

        void setColor(SquareColor color);
        char getColor();
    private:
        Piece* curPiece;
        SquareColor c;
        char squareColorToChar(SquareColor color) const;
};
#endif