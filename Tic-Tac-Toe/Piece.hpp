#ifndef PIECE_H
#define PIECE_H

#include "PieceType.hpp"

class Piece
{
public:
    PieceType piece = empty;
    Piece();
    Piece(PieceType piece);
};

#endif