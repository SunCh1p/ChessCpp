#include "pawn.h"

pawn::pawn(){
    mTeam = NADA;
    mType = NADA;
    mX = -1;
    mY = -1;
    mMove = -1;
}
pawn::pawn(chessP team, int x, int y, int move){
    mTeam = team;
    mType = PAWN;
    mX = x;
    mY = y;
    mMove = move;
    mFirstMove = false;
    mEnPassant = true;
}

void pawn::print(){
    if(mTeam == WHITE){
        std::cout << " \033[33m" << "p\033[37m ";
    } else if (mTeam == BLACK){
        std::cout << " \033[34m" << "p\033[37m ";
    } else{
        std::cout << " p ";
    }
    return;
}

