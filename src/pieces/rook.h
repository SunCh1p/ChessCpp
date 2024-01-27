#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
class rook: public piece{
    public:
        rook();
        rook(chessP team, int x, int y, int move);
        void print() override;
        inline void setSpecialMember1() override{mCanCastle = false;};

    private:
        bool mCanCastle;
};
#endif