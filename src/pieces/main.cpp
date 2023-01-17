#include <iostream>
#include "board.h"
using namespace std;

int main() {
    Board board;
    board.placePawns();
    board.printBoardOnConsole();
    cout << board.movePiece(make_pair(6,2), make_pair(5,2)) << endl;
    board.printBoardOnConsole();
    cout << board.movePiece(make_pair(5,2), make_pair(4,2)) << endl;
    board.printBoardOnConsole();


    return 0;
}