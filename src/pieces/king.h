#ifndef KING_H
#define KING_H
#include "board.h"
#include "piece.h"

class King : public Piece {
    public:
        King(Color c);
        ~King() override = default;
        bool isMoveValid(const Board *board, const std::pair<int, int> startCoor, const std::pair<int, int> endCoor) const override;
    private:
};
#endif