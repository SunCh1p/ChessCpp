#include "board.h"
#include <iostream>

board::board(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            mBoard[i][j] = nullptr;
        }
    }
    mMove = 0;
}

board::~board(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            delete mBoard[i][j];
        }
    }
}

piece* board::getPiece(int x, int y) const{
    if(x > -1 && x < 8 && y > -1 && y < 8){
        return mBoard[x][y];
    }
    else{
        return nullptr;
    }
}

void board::clearBoard(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(mBoard[i][j] != nullptr){
                delPiece(i,j);
            }
        }
    }
}

void board::setBoard(){
    clearBoard();
    chessP team;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            state[i][j] = 0;
            if(i == 1 || i == 6){
                (i == 1) ? team = BLACK : team = WHITE;
                insertPiece(team, PAWN,i,j, -1);
            }else if(i == 0 || i == 7){
                (i == 0) ? team = BLACK : team = WHITE;
                if(j == 0 || j == 7){
                    insertPiece(team, ROOK, i, j, 0);
                }else if(j == 1 || j == 6){
                    insertPiece(team, KNIGHT, i, j, 0);
                }else if(j == 2 || j== 5){
                    insertPiece(team, BISHOP, i, j, 0);
                }else if(j == 3){
                    insertPiece(team, QUEEN, i, j, 0);
                }else if(j==4){
                    insertPiece(team, KING, i, j, 0);
                }
            } 
        }
    }
    mMove = 1;
    return;
}

void board::movePiece(int fromX, int fromY, int toX, int toY){
    if(!onBoard(fromX, fromY) || !onBoard(toX, toY)){
        return;
    }
    if(getPiece(fromX,fromY) == nullptr){
        return;
    }

    chessP type = getPiece(fromX, fromY)->getType();
    chessP team = getPiece(fromX, fromY)->getTeam();
    switch(type){
        case PAWN:
            if(movePawn(fromX, fromY,toX, toY)){
                if((team == WHITE && toX == 0) || (team==BLACK && toX == 7)){
                    //insert promotion code
                }
            }
            break;
        case ROOK:
            moveRook(fromX, fromY, toX, toY);
            break;
        case KNIGHT:
            moveKnight(fromX, fromY, toX, toY);
            break;
        case BISHOP:
            //can move diagonally
            std::cout << "bishop" << std::endl;
            break;
        case KING:
            //King can move one square in any direction unless:
            //  square will put the king in check
            //  there is a friendly piece
            std::cout << "king" << std::endl;
            break;
        case QUEEN:
            //Can move in any direction
            std::cout << "queen" << std::endl;
            break;
        default:
            return;
    }
    
}

bool board::onBoard(int x, int y){
    if(x < 0 || x > 7 || y < 0 || y > 7){
        return false;;
    }
    return true;
}

void board::insertPiece(chessP team, chessP type, int x, int y, int move){
    if(x < 0 || x > 7 || y < 0 || y > 7){
        return;
    }
    if(mBoard[x][y] != nullptr){
        delPiece(x,y);
    }
    if(team == WHITE || team == BLACK){
        switch(type){
            case PAWN:
                mBoard[x][y] = new pawn(team, x, y, move);
                break;
            case ROOK:
                mBoard[x][y] = new rook(team, x, y, move);
                break;
            case KNIGHT:
                mBoard[x][y] = new knight(team, x, y, move);
                break;
            case BISHOP:
                mBoard[x][y] = new bishop(team, x, y, move);
                break;
            case QUEEN:
                mBoard[x][y] = new queen(team, x, y, move);
                break;
            case KING:
                mBoard[x][y] = new king(team, x, y, move);
                break;

        }

    }
    return;
}

void board::delPiece(int x, int y){
    if(mBoard[x][y] == nullptr){
        return;
    }
    delete mBoard[x][y];
    mBoard[x][y] = nullptr;
    return;
}

void board::printBoard(){
    std::cout << "   ";
    for(int i = 0; i < 8; i++){
        std::cout << ' ' << i << ' ';
    }
    std::cout << std::endl;
    for(int i = 0; i < 8; i++){
        std::cout << ' ' << i << ' ';
        for(int j = 0; j < 8; j++){ 
            if(mBoard[i][j] == nullptr){
                std::cout << " - ";
            }
            else{
                mBoard[i][j]->print();
            }
        }
        std::cout << std::endl;
    }
}

void board::printBoardMoves(){
    std::cout << "   ";
    for(int i = 0; i < 8; i++){
        std::cout << ' ' << i << ' ';
    }
    std::cout << std::endl;
    for(int i = 0; i < 8; i++){
        std::cout << ' ' << i << ' ';
        for(int j = 0; j < 8; j++){ 
            if(mBoard[i][j] == nullptr){
                std::cout << " - ";
            }
            else{
                if(mBoard[i][j]->getMove() == -1){
                    std::cout << " x ";
                }
                else{
                    std::cout << ' '<< mBoard[i][j]->getMove() << ' ';

                }
            }
        }
        std::cout << std::endl;
    }
}

bool board::movePawn(int fromX, int fromY, int toX, int toY){
    //check if current team is allowed to move
    if(checkIfTeamMove(fromX, fromY) == false){
        std::cout << "NOT TEAM MOVE" << std::endl;
        return false;
    }
    if(fromX == toX && fromY == toY){
        return false;
    }
    int dir = (getPiece(fromX, fromY)->getTeam() == WHITE)? -1 : 1;
    //case forward+2
    if(toX == (fromX+(2*dir)) && toY == fromY && getPiece(fromX+dir, fromY) == nullptr 
    && getPiece(toX, toY) == nullptr && !getPiece(fromX, fromY)->returnSpecialMember1()){
        insertPiece(getPiece(fromX, fromY)->getTeam(), getPiece(fromX, fromY)->getType(), toX, toY,mMove);
        getPiece(toX, toY)->setSpecialMember1();
        delPiece(fromX, fromY);
        mMove++;
        //std::cout << "forward+2" << std::endl;
        return true;
    }//case forward+1 
    else if (toX == (fromX+dir) && toY == fromY && getPiece(toX, toY) == nullptr)
    {
        insertPiece(getPiece(fromX, fromY)->getTeam(), getPiece(fromX, fromY)->getType(), toX, toY,mMove);
        getPiece(toX, toY)->setSpecialMember1();
        getPiece(toX, toY)->setSpecialMember2();
        delPiece(fromX, fromY);
        mMove++;
        //std::cout << "forward+1" << std::endl;
        return true;
    } //enemy kill
    else if((fromX + dir) == toX && ((fromY+dir) == toY || (fromY-dir) == toY) 
    && getPiece(toX, toY) != nullptr 
    && getPiece(toX, toY)->getTeam() != getPiece(fromX, fromY)->getTeam()
    )
    {
        insertPiece(getPiece(fromX, fromY)->getTeam(), getPiece(fromX, fromY)->getType(), toX, toY,mMove);
        getPiece(toX, toY)->setSpecialMember1();
        getPiece(toX, toY)->setSpecialMember2();
        delPiece(fromX, fromY);
        mMove++;
        return true;
    }//case EnPassant Left
    else if
    (toX==(fromX+dir) && (toY == (fromY+dir)) && getPiece(toX,toY) == nullptr
    && getPiece(fromX, fromY+dir) != nullptr 
    && getPiece(fromX, fromY+dir)->getTeam() != getPiece(fromX,fromY)->getTeam() 
    && getPiece(fromX, fromY+dir)->getType() == PAWN
    && getPiece(fromX, fromY+dir)->getMove() == mMove-1
    && (getPiece(fromX, fromY+dir)->returnSpecialMember1() && getPiece(fromX, fromY+dir)->returnSpecialMember2())
    )
    { 
        insertPiece(getPiece(fromX, fromY)->getTeam(), getPiece(fromX, fromY)->getType(), toX, toY,mMove);
        getPiece(toX, toY)->setSpecialMember1();
        getPiece(toX, toY)->setSpecialMember2();
        delPiece(fromX, fromY);
        delPiece(fromX, fromY+dir);
        mMove++;
        //std::cout << "enPassant Left" << std::endl;
        return true;
    }//enPassant case Right
    else if
    (toX==(fromX+dir) && (toY == (fromY-dir)) && getPiece(toX,toY) == nullptr
    && getPiece(fromX, fromY-dir) != nullptr 
    && getPiece(fromX, fromY-dir)->getTeam() != getPiece(fromX,fromY)->getTeam() 
    && getPiece(fromX, fromY-dir)->getType() == PAWN
    && getPiece(fromX, fromY-dir)->getMove() == mMove-1
    && (getPiece(fromX, fromY-dir)->returnSpecialMember1() && getPiece(fromX, fromY-dir)->returnSpecialMember2())
    )
    { 
        insertPiece(getPiece(fromX, fromY)->getTeam(), getPiece(fromX, fromY)->getType(), toX, toY,mMove);
        getPiece(toX, toY)->setSpecialMember1();
        getPiece(toX, toY)->setSpecialMember2();
        delPiece(fromX, fromY);
        delPiece(fromX, fromY-dir);
        mMove++;
        //std::cout << "EnPassant Right" << std::endl;
        return true;
    } //case EnPassant Right
    //case attack
    std::cout << "NOT A MOVE" << std::endl;
    return false;
}

//Simplify LATER
void board::moveRook(int fromX, int fromY, int toX, int toY){
    if(checkIfTeamMove(fromX, fromY) == false){
        std::cout << "NOT TEAM MOVE" << std::endl;
        return;
    }
    if(fromX == toX && fromY == toY){
        std::cout << "ERROR: SAME SPOT" << std::endl;
        return;
    }

    //horizontal moves
    if(fromX == toX && fromY != toY){
        if(std::abs(toY - fromY) > 1){
            int dir;
            (toY > fromY) ? dir = 1: dir = -1;
            for(int i = fromY; i < toY; i++){
                if(getPiece(fromX, i) != nullptr){
                    std::cout << "ERROR: PIECE IN THE WAY" << std::endl;
                    return;
                }
            }
        }
        if(getPiece(fromX, toY) != nullptr){
            if(getPiece(fromX, toY)->getTeam() == getPiece(fromX, fromY)->getTeam()){
                std::cout << "ERROR: ALLY PIECE IN PATH" << std::endl;
            }
        }
        insertPiece(getPiece(fromX, fromY)->getTeam(), getPiece(fromX, fromY)->getType(), toX, toY,mMove);
        getPiece(toX, toY)->setSpecialMember1();
        delPiece(fromX, fromY);
        mMove++;
        return;
    }//vertical moves
    else if(fromY == toY && toX != fromX){
        if(std::abs(fromX-toX) > 1){
            int dir;
            (toX > fromX) ? dir = 1 : dir = -1;
            for(int i = fromX; i < toX; i++){
                if(getPiece(i, fromY) != nullptr){
                    std::cout << "DIRECTION is blocked" << std::endl;
                    return;
                }
            }
        }
        if(getPiece(toX, fromY) != nullptr){
            if(getPiece(toX, fromY)->getTeam() == getPiece(toX, fromY)->getTeam()){
                std::cout << "ERROR: ALLY PIECE IN PATH" << std::endl;
            }
        }
        insertPiece(getPiece(fromX, fromY)->getTeam(), getPiece(fromX, fromY)->getType(), toX, toY,mMove);
        getPiece(toX, toY)->setSpecialMember1();
        delPiece(fromX, fromY);
        mMove++;
        return;
    }
    return;
}

void board::moveKnight(int fromX, int fromY, int toX, int toY){
    if(checkIfTeamMove(fromX, fromY) == false){
        std::cout << "NOT TEAM MOVE" << std::endl;
        return;
    }
    if(fromX == toX && fromY == toY){
        return;
    }
    int x = std::abs(fromX - toX);
    int y = std::abs(fromY - toY);
    if((x == 2 && y == 1) || (y==2 && x == 1)){
        if(getPiece(x,y) != nullptr && getPiece(x,y)->getTeam() == getPiece(fromX,fromY)->getTeam()){
            return;
        }
        insertPiece(getPiece(fromX, fromY)->getTeam(), getPiece(fromX, fromY)->getType(), toX, toY,mMove);
        delPiece(fromX, fromY);
        mMove++;
        return;
    }
    return;
}


bool board::checkIfTeamMove(int x, int y){
    chessP team = getPiece(x,y)->getTeam();
    int move = mMove%2;
    if(move == 1 && team == WHITE){
        return true;
    } else if(move == 0 && team == BLACK){
        return true;
    }
    return false;
}