#ifndef PAWN_H
#define PAWN_H
#include "board.h"
#include "piece.h"

class Pawn : public Piece {
    public:
        Pawn(Color c);
        ~Pawn() override = default;
        bool isMoveValid(const Board *board, const std::pair<int, int> startCoor, const std::pair<int, int> endCoor) const override;
    private:
};
#endif