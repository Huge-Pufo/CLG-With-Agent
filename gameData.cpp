#include "gameData.h"
#include <iostream>

TableData::TableData() {
    for (int i = 0; i < 9; i++) {
        positions[i].position = i + 1;
        positions[i].character = ' ';
    }
}

//Changes 'positions' array to have the character 'X' or 'O' in the specified position. From 1-9. 
// Once every time user input is received, this function will be called to change the 'positions' array in the TableData object.
bool TableData::setPositionTo(char character, int position) {
    if (position < 1 || position > 9) {
        std::cout << "Invalid position. Please choose a position from 1 to 9." << std::endl;
        return false;
    }
    
    // Check if the position is already taken
    if (positions[position - 1].character != ' ') {
        std::cout << "Position already taken. Please choose another position." << std::endl;
        return false;
    }

    //Changes the character in the 'positions' array at the specified index to either 'X' or 'O'.
    positions[position - 1].character = character;

    //Saves the position number in the 'position' variable of the CharData struct for that index.
    // This is useful when redrawing the table to know which positions have been filled with 'X' or 'O'.
    positions[position - 1].position = position;

    return true;
}

//Returns the CharData struct at the specified position. From 1-9.
CharData TableData::getPosition(int position) {
    if (position < 1 || position > 9) {
        std::cout << "Invalid position. Please choose a position from 1 to 9." << std::endl;
        return positions[0]; // Return first position as default
    }
    return positions[position - 1];
}

//Player wins if they have 3 of their characters in a row, column, or diagonal. This function checks for that condition.
bool Table::checkWinCondition(TableData table) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (table.getPosition(i + 1).character != ' ' &&
            table.getPosition(i + 1).character == table.getPosition(i + 2).character &&
            table.getPosition(i + 1).character == table.getPosition(i + 3).character) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (table.getPosition(i + 1).character != ' ' &&
            table.getPosition(i + 1).character == table.getPosition(i + 4).character &&
            table.getPosition(i + 1).character == table.getPosition(i + 7).character) {
            return true;
        }
    }

    // Check diagonals
    if (table.getPosition(1).character != ' ' &&
        table.getPosition(1).character == table.getPosition(5).character &&
        table.getPosition(1).character == table.getPosition(9).character) {
        return true;
    }

    if (table.getPosition(3).character != ' ' &&
        table.getPosition(3).character == table.getPosition(5).character &&
        table.getPosition(3).character == table.getPosition(7).character) {
        return true;
    }

    return false;
}