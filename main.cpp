#include <iostream>
#include <string>
#include "gameData.h"

int main() {
    TableData table;
    bool gameRunning = true;
    bool player1Turn = true;
    bool player2Turn = false;

    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
    std::cout << "Player 1 is 'X' and Player 2 is 'O'." << std::endl;

    while (gameRunning) {
        if (player1Turn) {
            int position;
            std::string input;
            std::cout << "Player 1, enter your position (1-9): ";
            std::getline(std::cin, input);
            if (!table.validateInput(input, position)) {
                continue;
            }
            if (table.setPositionTo('X', position)) {
                player1Turn = false;
                player2Turn = true;
            }

        } else if (player2Turn) {
            int position;
            std::string input;
            std::cout << "Player 2, enter your position (1-9): ";
            std::getline(std::cin, input);
            if (!table.validateInput(input, position)) {
                continue;
            }
            if (table.setPositionTo('O', position)) {
                player2Turn = false;
                player1Turn = true;
            }
        }

        // Draw the table after each move
        Table t;
        t.drawTable(table);

        // Check for win condition
        if (t.checkWinCondition(table)) {
            if (player1Turn) {
                std::cout << "Player 2 wins!" << std::endl;
            } else {
                std::cout << "Player 1 wins!" << std::endl;
            }
            gameRunning = false;
        }
    }

    return 0;
}