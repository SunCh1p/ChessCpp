#include <iostream>
#include "board.h"

int main(int argc, char* argv[]){
    board chessBoard;
    chessBoard.setBoard();
    chessBoard.printBoard();
    chessBoard.movePiece(6,0,4,0);//white move
    chessBoard.movePiece(1,0,3,0);//black move
    chessBoard.movePiece(6,1,5,1);//white move
    chessBoard.movePiece(1,5,2,5);//black move
    //testing enPassant left
    chessBoard.movePiece(6,2,4,2);//white move
    chessBoard.movePiece(2,5,3,5);//black move
    chessBoard.movePiece(4,2,3,2);//white move
    chessBoard.movePiece(1,1,3,1);//black move
    chessBoard.movePiece(3,2,2,1);//EnPassant White move
    //end of enPassant test
    //promote test
    chessBoard.movePiece(3,5,4,5);//black move
    chessBoard.movePiece(2,1,1,2);//white move
    chessBoard.movePiece(4,5,5,5);//black move
    chessBoard.movePiece(1,2,0,1);//white move
    //test rook
    chessBoard.movePiece(0,0,0,1);//black move
    chessBoard.movePiece(7,0,5,0);//white move
    chessBoard.printBoard();

    

    

    return 0;
}