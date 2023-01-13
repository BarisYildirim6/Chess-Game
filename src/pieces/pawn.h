#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn : public Piece {
    public:
        Pawn(Color c);
        ~Pawn();

        void setIsFirst(bool first);
    
    private:
        bool isFirst;
};
#endif