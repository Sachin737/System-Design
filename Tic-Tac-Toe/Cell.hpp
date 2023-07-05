#ifndef CELL_H
#define CELL_H

#include "Piece.hpp"

class Cell
{
public:
    Piece *p = nullptr;
    Cell();
    Cell(Piece *newPiece);
};

#endif