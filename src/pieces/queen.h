#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
class queen: public piece{
    public:
        queen();
        queen(chessP team, int x, int y, int move);
        void print() override;

        //overwritten pure virtual functions

};
#endif