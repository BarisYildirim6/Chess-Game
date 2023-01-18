#ifndef QUEEN_H
#define QUEEN_H
#include "board.h"
#include "piece.h"

class Quenn : public Piece {
    public:
        Quenn(Color c);
        ~Quenn() override = default;
        bool isMoveValid(const Board *board, const std::pair<int, int> startCoor, const std::pair<int, int> endCoor) const override;
    private:
};

#endif