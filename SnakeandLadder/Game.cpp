#include <bits/stdc++.h>
using namespace std;

#include "Jump.hpp"
#include "Player.hpp"
#include "Dice.hpp"
#include "Board.hpp"

class Game
{
private:
    Board *myBoard;
    Dice *dice;
    deque<Player *> playersList;
    Player *winner;

    int checkJump(int position)
    {
        int finPosition = position;

        Cell *cell = myBoard->getCell(position);

        if (cell->jump != nullptr && cell->jump->start == position)
        {
            string jumpMsg = "";

            if (cell->jump->start < cell->jump->end)
            {
                jumpMsg = "[ladder up] " + to_string(position) + " -> " + to_string(cell->jump->end);
            }
            else
            {
                jumpMsg = "[snake bite] " + to_string(position) + " -> " + to_string(cell->jump->end);
            }

            cout << jumpMsg << "\n";

            finPosition = cell->jump->end;
        }
        return finPosition;
    }

public:
    Game(int row, int col, int snakes, int ladders, int dices)
    {
        myBoard = new Board(row, col, snakes, ladders);
        dice = new Dice(dices);
        winner = NULL;
    }

    void addPlayer(string name)
    {
        Player *p = new Player(name, 0);
        playersList.push_back(p);
    }

    void start()
    {

        srand(time(0));
        while (!winner)
        {
            // getting player whose turn is
            Player *playerTurn = playersList.front();
            playersList.pop_front();
            playersList.push_back(playerTurn);

            int diceNum = dice->roll();

            int newPosition = playerTurn->Position() + diceNum;

            if (newPosition > myBoard->getBoardsize() - 1)
            {
                cout << "[" << playerTurn->id << "," << diceNum << "] Close to winning, try to get lower value on dice\n";
                continue;
            }

            // check new pos for snake-or-ladder
            newPosition = this->checkJump(newPosition);
            ;
            playerTurn->position = newPosition;

            cout << "[" << playerTurn->id << "] "
                 << "newCell: " << newPosition << "\n";

            // check for winning condition
            if (newPosition == myBoard->getBoardsize() - 1)
            {
                cout << "Woohooo! " << playerTurn->id << " WON!!!\n";
                winner = playerTurn;
            }
        }
    }
};