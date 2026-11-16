#ifndef GAMEDATA_H
#define GAMEDATA_H
#endif

struct CharData {
    int position;
    char character;
};

class TableData {
    private:
        //Max of 9 positions in the table. Each position can be either 'X', 'O', or empty.
        CharData positions[9] = {};
    public:
        //Changes 'positions' array to have the character 'X' or 'O' in the specified position. From 1-9.
        void setPositionTo(char character, int position);

        //Creates a new TableData object with all positions empty.
        TableData();
};