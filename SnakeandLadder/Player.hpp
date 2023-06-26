#ifndef PLAYER_H
#define PLAYER_H

#include <bits/stdc++.h>

class Player
{
public:
    std::string id;
    int position;

    Player();
    Player(std::string id, int curPosition);
    int Position();
};

#endif