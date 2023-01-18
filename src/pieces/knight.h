#ifndef KNIGHT_H
#define KNIGHT_H
#include "board.h"
#include "piece.h"

class Knight : public Piece {
    public:
        Knight(Color c);
        ~Knight() override = default;
        bool isMoveValid(const Board *board, const std::pair<int, int> startCoor, const std::pair<int, int> endCoor) const override;
    private:
};
#endif