#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class pawn: public piece{
    public:
        pawn();
        pawn(chessP team, int x, int y, int move);
        void print() override;

        //overwritten pure virtual functions
        //set first move
        inline void setSpecialMember1() override{mFirstMove = true;};
        void setSpecialMember2() override{mEnPassant = false;};
        inline bool returnSpecialMember1() override {return mFirstMove;}
        inline bool returnSpecialMember2() override {return mEnPassant;}
    private:
        bool mFirstMove;
        bool mEnPassant;

        
};
#endif