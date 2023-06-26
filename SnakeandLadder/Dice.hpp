#ifndef DICE_H
#define DICE_H

class Dice
{
    int DiceCount = 0;
    int mn = 1;
    int mx = 6;

public:
    Dice();
    Dice(int cnt);
    int roll();
};

#endif