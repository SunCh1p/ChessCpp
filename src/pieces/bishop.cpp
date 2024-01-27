#include "bishop.h"

bishop::bishop(){
    mTeam = NADA;
    mType = NADA;
    mX = -1;
    mY = -1;
    mMove = -1;
}
bishop::bishop(chessP team, int x, int y, int move){
    mTeam = team;
    mType = BISHOP;
    mX = x;
    mY = y;
    mMove = move;
}
void bishop::print(){
    if(mTeam == WHITE){
        std::cout << " \033[33m" << "b\033[37m ";
    } else if (mTeam == BLACK){
        std::cout << " \033[34m" << "b\033[37m ";
    } else{
        std::cout << " p ";
    }
    return;
}