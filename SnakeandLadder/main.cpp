#include <bits/stdc++.h>
using namespace std;

#include "Game.cpp"

int main()
{
    Game SnL(10, 10, 5, 5, 2);

    SnL.addPlayer("potato");
    SnL.addPlayer("mish");
    SnL.addPlayer("drekk");

    SnL.start();

    return 0;
}