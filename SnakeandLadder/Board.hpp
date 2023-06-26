#ifndef BOARD_H
#define BOARD_H

#include "Cell.hpp"

class Board
{
private:
    vector<vector<Cell*>> board;
    int rows, cols, boardsize;

    void addSnakeLadders(int snakes, int ladders);

public:
    Board();
    Board(int rows, int cols, int snakes, int ladders);

    Cell* getCell(int playerPosition);

    int getBoardsize();
};

#endif