#include <iostream>
#include "Player.hpp"
using namespace std;

Player::Player(string id, int curPosition)
{
    this->id = id;
    this->position = curPosition;
}

int Player::Position()
{
    return position;
}

Player::Player()
{
}
