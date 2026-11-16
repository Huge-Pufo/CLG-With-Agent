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
void TableData::setPositionTo(char character, int position) {
    if (position < 1 || position > 9) {
        std::cout << "Invalid position. Please choose a position from 1 to 9." << std::endl;
        return;
    }
    
    //Changes the character in the 'positions' array at the specified index to either 'X' or 'O'.
    positions[position - 1].character = character;

    //Saves the position number in the 'position' variable of the CharData struct for that index.
    // This is useful when redrawing the table to know which positions have been filled with 'X' or 'O'.
    positions[position - 1].position = position;
}

//Returns the CharData struct at the specified position. From 1-9.
CharData TableData::getPosition(int position) {
    if (position < 1 || position > 9) {
        std::cout << "Invalid position. Please choose a position from 1 to 9." << std::endl;
        return positions[0]; // Return first position as default
    }
    return positions[position - 1];
}