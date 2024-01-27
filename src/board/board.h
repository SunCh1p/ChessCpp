#ifndef BOARD_H
#define BOARD_H
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <vector>
#include "cmath"

class board{
    public:
        board();
        ~board();

        //state of the board functions
        int getMove() const{return mMove;}
        void printBoard();
        void printBoardMoves();
        piece* getPiece(int x, int y) const;

        //Set board functions
        void clearBoard();
        void setBoard();
        void insertPiece(chessP team, chessP type, int x, int y, int move);
        void delPiece(int x, int y);
        //implement
        void movePiece(int fromX, int fromY, int toX, int toY);
        bool onBoard(int x, int y);

        //movement functions for pieces
        bool movePawn(int fromX, int fromY, int toX, int toY);//REFACTOR AND SIMPLIFY
        void moveRook(int fromX, int fromY, int toX, int toY);//REFACTOR AND SIMPLIFY
        void moveKnight(int fromX, int fromY, int toX, int toY);//REFACTOR AND SIMPLIFY
        //void moveBishop(int fromX, int fromY, int toX, int toY);
        //void moveKing(int fromX, int fromY, int toX, int toY);
        //void moveQueen(int fromX, int fromY, int toX, int toY);

        bool isCheck(){return false;}

        bool checkIfTeamMove(int x, int y);


    private:
        piece *mBoard[8][8];
        int state[8][8];
        int mMove;
};

#endif