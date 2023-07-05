#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Piece.hpp"
#include "Cell.hpp"
using namespace std;

class Board
{
public:
    int rows, cols;
    vector<vector<Cell *>> board;
    Board();
    Board(int r, int c);
    vector<pair<int, int>> getFreeCells();
    void printBoard();
    bool addPiece(int row, int col, Piece *playingPiece);
};

#endif