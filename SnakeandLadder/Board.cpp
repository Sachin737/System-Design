#include <bits/stdc++.h>
using namespace std;

#include "Board.hpp"
#include "Jump.hpp"
#include "Cell.hpp"

Board::Board(int rows, int cols, int snakes, int ladders)
{
    this->rows = rows;
    this->cols = cols;
    this->boardsize = rows * cols;
    this->board.resize(rows, vector<Cell *>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            this->board[i][j] = new Cell();
        }
    }

    this->addSnakeLadders(snakes, ladders);
}

Board::Board()
{
}

void Board::addSnakeLadders(int snakes, int ladders)
{
    cout << "Snakes at: ";
    while (snakes)
    {
        int st = rand() % boardsize;
        int en = rand() % boardsize;
        if (st <= en || (st == boardsize - 1))
        {
            continue;
        }

        cout << "(" << st / rows << "," << st % cols << ")->";
        cout << "(" << en / rows << "," << en % cols << ")\n";

        Jump *snakeObj = new Jump();
        snakeObj->start = st;
        snakeObj->end = en;

        Cell *myCell = getCell(st);
        myCell->jump = snakeObj;

        snakes--;
    }

    cout << "Ladders at: ";
    while (ladders)
    {
        int st = rand() % boardsize;
        int en = rand() % boardsize;
        if (st >= en)
        {
            continue;
        }

        cout << "(" << st / rows << "," << st % cols << ")->";
        cout << "(" << en / rows << "," << en % cols << ")\n";

        Jump *ladderObj = new Jump();
        ladderObj->start = st;
        ladderObj->end = en;

        Cell *myCell = getCell(st);
        myCell->jump = ladderObj;

        ladders--;
    }
}

Cell *Board::getCell(int playerPosition)
{
    int row = playerPosition / rows;
    int col = playerPosition % cols;
    return board[row][col];
}

int Board::getBoardsize()
{
    return boardsize;
}