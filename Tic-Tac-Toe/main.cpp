// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

#include "Game.cpp"
#include "Player.hpp"
#include "Piece.hpp"
#include "PieceType.hpp"
#include "PieceX.cpp"
#include "PieceO.cpp"

int main()
{
    cout << "Enter board's board size(row or col): ";
    int n;
    cin >> n;
    cout << "\n";

    TicTacToeGame game(n, n);

    Player *sachin = new Player("sachin", new PieceX());
    Player *ravic = new Player("ravic", new PieceO());
    
    game.addPlayer(sachin);
    game.addPlayer(ravic);

    game.startgame();

    return 0;
}