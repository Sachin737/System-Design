#include <bits/stdc++.h>
#include "Player.hpp"
#include "Piece.hpp"
using namespace std;

Player::Player(string name = "noName", Piece *p = nullptr)
{
    this->name = name;
    this->playerPiece = p;
}