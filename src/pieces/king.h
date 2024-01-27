#ifndef KING_H
#define KING_H
#include "piece.h"
class king: public piece{
    public:
        king();
        king(chessP team, int x, int y, int move);
        void print() override;

};
#endif