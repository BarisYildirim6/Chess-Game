#ifndef PIECE_H
#define PIECE_H
#include <iostream>
using namespace std;

class Board;

enum Type {
    pawn,
    knight,
    bishop,
    rook,
    queen,
    king
};

enum Color {
    white,
    black
};

class Piece {
    public:
        Piece(Type type, Color color);
        ~Piece();

        void setColor(Color color);
        void setType(Type type);
        char getColor();
        char getType();
        bool isMovedBefore();
        virtual bool isMoveValid(const Board *board, const std::pair<int, int> startCoor, const std::pair<int, int> endCoor);

    private:
        Color pieceColor;
        Type pieceType;
        int numberOfMoves;
        char typeToChar(Type type) const;
        char colorToChar(Color color) const;
};
#endif