#include "gameData.h";

//Asks for user input and changes 'positions' index to have the character 'X' or 'O'. Position ranges from 1-9.
CharData drawChar(int position, char character);

//Draws the Tictactoe table based on the 'positions' array in the TableData object.
void drawTable(TableData table);