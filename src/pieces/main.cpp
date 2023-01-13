#include <iostream>
#include "board.h"
using namespace std;

int main() {
    Board board;
    board.placePawns();
    board.printBoardOnConsole();

    return 0;
}