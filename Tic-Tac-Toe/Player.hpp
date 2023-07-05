#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

#include "Piece.hpp"

class Player
{
public:
    string name;
    Piece *playerPiece;

    Player(string name, Piece *piece);
};

#endif