#include "king.h"

king::king(){
    mTeam = NADA;
    mType = NADA;
    mX = -1;
    mY = -1;
    mMove = -1;
}
king::king(chessP team, int x, int y, int move){
    mTeam = team;
    mType = KING;
    mX = x;
    mY = y;
    mMove = move;
}
void king::print(){
    if(mTeam == WHITE){
        std::cout << " \033[33m" << "*\033[37m ";
    } else if (mTeam == BLACK){
        std::cout << " \033[34m" << "*\033[37m ";
    } else{
        std::cout << " p ";
    }
    return;
}