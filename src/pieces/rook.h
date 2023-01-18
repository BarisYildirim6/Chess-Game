#ifndef ROOK_H
#define ROOK_H
#include "board.h"
#include "piece.h"

class Rook : public Piece {
    public:
        Rook(Color c);
        ~Rook();
        bool isMoveValid(const Board *board, const std::pair<int, int> startCoor, const std::pair<int, int> endCoor) const override;
    private:
};
#endif