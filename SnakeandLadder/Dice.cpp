#include <bits/stdc++.h>
using namespace std;

#include "Dice.hpp"

Dice::Dice(int cnt)
{
    this->DiceCount = cnt;
}

Dice::Dice()
{
}

int Dice::roll()
{
    int diceRolled = 0;
    int total = 0;

    while (diceRolled < DiceCount)
    {
        total += rand() % (mx - mn + 1) + mn;
        diceRolled++;
    }

    return total;
}
