#ifndef BISHOP_H
#define BISHOP_H
#include "board.h"
#include "piece.h"

class Bishop : public Piece {
    public:
        Bishop(Color c);
        ~Bishop() override = default;
        bool isMoveValid(const Board *board, const std::pair<int, int> startCoor, const std::pair<int, int> endCoor) const override;
    private:
};
#endif