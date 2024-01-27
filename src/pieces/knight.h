#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
class knight: public piece{
    public:
        knight();
        knight(chessP team, int x, int y, int move);
        void print() override;

};
#endif