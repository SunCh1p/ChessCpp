#include "knight.h"

knight::knight(){
    mTeam = NADA;
    mType = NADA;
    mX = -1;
    mY = -1;
    mMove = -1;
}
knight::knight(chessP team, int x, int y, int move){
    mTeam = team;
    mType = KNIGHT;
    mX = x;
    mY = y;
    mMove = move;
}
void knight::print(){
    if(mTeam == WHITE){
        std::cout << " \033[33m" << "k\033[37m ";
    } else if (mTeam == BLACK){
        std::cout << " \033[34m" << "k\033[37m ";
    } else{
        std::cout << " p ";
    }
    return;
}