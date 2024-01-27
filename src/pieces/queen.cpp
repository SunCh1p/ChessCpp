#include "queen.h"

queen::queen(){
    mTeam = NADA;
    mType = NADA;
    mX = -1;
    mY = -1;
    mMove = -1;
}
queen::queen(chessP team, int x, int y, int move){
    mTeam = team;
    mType = QUEEN;
    mX = x;
    mY = y;
    mMove = move;
}
void queen::print(){
    if(mTeam == WHITE){
        std::cout << " \033[33m" << "Q\033[37m ";
    } else if (mTeam == BLACK){
        std::cout << " \033[34m" << "Q\033[37m ";
    } else{
        std::cout << " p ";
    }
    return;
}