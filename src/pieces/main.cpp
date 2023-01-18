#include <iostream>
#include "board.h"
using namespace std;

int main() {
    Board board;
    board.placePawns();
    board.placeKnights();
    board.placeBishops();
    board.placeRooks();
    board.placeQueens();
    board.placeKings();
    board.printBoardOnConsole();
    cout << board.movePiece(make_pair(6,4), make_pair(5,4)) << endl;
    board.printBoardOnConsole();
    cout << board.movePiece(make_pair(7,5), make_pair(2,0)) << endl;
    board.printBoardOnConsole();
    cout << board.movePiece(make_pair(1,1), make_pair(2,0)) << endl;
    board.printBoardOnConsole();


    return 0;
}