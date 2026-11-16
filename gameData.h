#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>

struct CharData {
    int position;
    char character;
};

class TableData {
    private:
        //Max of 9 positions in the table. Each position can be either 'X', 'O', or empty.
        CharData positions[9] = {};
    public:
        TableData();

        //Changes 'positions' array to have the character 'X' or 'O' in the specified position. From 1-9.
        bool setPositionTo(char character, int position);

        //Returns the CharData struct at the specified position. From 1-9.
        CharData getPosition(int position); 

        bool validateInput(const std::string& input, int& position);
};

class Table : public TableData {
    private:
        TableData table;
    public:
        //Draws the Tictactoe table based on the 'positions' array in the TableData object.
        void drawTable(TableData table);
        bool checkWinCondition(TableData table);
};

#endif