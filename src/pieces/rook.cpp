#include "rook.h"

rook::rook(){
    mTeam = NADA;
    mType = NADA;
    mX = -1;
    mY = -1;
    mMove = -1;
    mCanCastle = true;
}
rook::rook(chessP team, int x, int y, int move){
    mTeam = team;
    mType = ROOK;
    mX = x;
    mY = y;
    mMove = move;
    mCanCastle = true;
}

void rook::print(){
    if(mTeam == WHITE){
        std::cout << " \033[33m" << "r\033[37m ";
    } else if (mTeam == BLACK){
        std::cout << " \033[34m" << "r\033[37m ";
    } else{
        std::cout << " p ";
    }
}