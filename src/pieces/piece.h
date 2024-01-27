#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <iostream>


enum chessP{
    KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN,WHITE,BLACK, NADA
};

class piece{
    public:
        //default constructor
        piece(): mTeam(NADA), mX(-1), mY(-1), mType(NADA){}
        piece(chessP pieceTeam, chessP pieceType, int x, int y, int move){mTeam = pieceTeam; mType = pieceType; mX = x; mY = y; mMove = move;}
        //copy constructor
        piece(const piece& other): mTeam(other.mTeam), mX(other.mX), mY(other.mY), mType(other.mType){}

        //simple Getter functions
        inline const chessP getTeam(){return mTeam;}
        inline const chessP getType(){return mType;}
        inline const int getMove(){return mMove;}

        //pure virtual functions
        virtual bool validMove(int x, int y){return false;}
        virtual void print() = 0;
        //not needed for all pieces so default is return false
        virtual void setSpecialMember1(){std::cout << "dave" << std::endl;};
        virtual void setSpecialMember2(){std::cout << "dave" << std::endl;};
        virtual void setSpecialMember3(){std::cout << "dave" << std::endl;};
        virtual bool returnSpecialMember1(){return false;}
        virtual bool returnSpecialMember2(){return false;}
        virtual bool returnSpecialMember3(){return false;}

    protected:
        chessP mTeam;
        chessP mType;
        int mX, mY;
        int mMove;
};
#endif