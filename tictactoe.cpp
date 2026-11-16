#include "gameData.h"
#include <iostream>

//Redraws the Tictactoe table with 'X' and 'O" in whatever position the player chose (1-9).
void drawTable() {
    TableData table;
    std::cout << "Current Tic Tac Toe Board:" << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cout << "[" << table.getPosition(i + 1).character << "]";
        if ((i + 1) % 3 == 0) {
            std::cout << std::endl;
        }
    }
}