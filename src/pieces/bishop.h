#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
class bishop: public piece{
    public:
        bishop();
        bishop(chessP team, int x, int y, int move);
        void print() override;


};
#endif