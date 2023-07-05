#include <bits/stdc++.h>
#include "Player.hpp"
#include "Board.hpp"

using namespace std;

class TicTacToeGame
{
    deque<Player *> players;
    Board *gameBoard;

public:
    TicTacToeGame(int n, int m)
    {
        this->gameBoard = new Board(n, m);
    }

    void addPlayer(Player *p)
    {
        players.push_back(p);
    }

    void startgame()
    {
        bool winner = false;

        while (!winner)
        {
            Player *playerTurn = players.front();
            players.pop_front();

            this->gameBoard->printBoard();

            vector<pair<int, int>> frees = this->gameBoard->getFreeCells();

            if (!frees.size())
            {
                cout << "tie!\n";
                return;
            }

            cout << "[" << playerTurn->name << "] Enter row col to mark:";
            int r, c;
            cin >> r >> c;

            if (r < 1 || r > this->gameBoard->rows || c < 1 || c > this->gameBoard->cols)
            {
                cout << "Incorrect position, try again!\n";
                players.push_front(playerTurn);
                continue;
            }

            bool peicePlaced = this->gameBoard->addPiece(r, c, playerTurn->playerPiece);

            if (!peicePlaced)
            {
                cout << "Incorrect position, try again!\n";
                players.push_front(playerTurn);
                continue;
            }

            players.push_back(playerTurn);

            winner = checkWinner(r, c, playerTurn->playerPiece);

            if (winner)
            {
                this->gameBoard->printBoard();

                cout << "Winner !!! ===> " << playerTurn->name << "\n";
                return;
            }
        }
    }

    bool checkWinner(int row, int column, Piece *pieceType)
    {
        bool rowMatch = true;
        bool columnMatch = true;
        bool diagonalMatch = true;
        bool antiDiagonalMatch = true;

        // Check row
        for (int i = 1; i <= this->gameBoard->cols; i++)
        {
            if (this->gameBoard->board[row][i]->p == nullptr || this->gameBoard->board[row][i]->p != pieceType)
            {
                rowMatch = false;
                break;
            }
        }

        // Check column
        for (int i = 1; i <= this->gameBoard->rows; i++)
        {
            if (this->gameBoard->board[i][column]->p == nullptr || this->gameBoard->board[i][column]->p != pieceType)
            {
                columnMatch = false;
                break;
            }
        }

        // Check diagonal
        for (int i = 1, j = 1; i <= this->gameBoard->rows; i++, j++)
        {
            if (this->gameBoard->board[i][j]->p == nullptr || this->gameBoard->board[i][j]->p != pieceType)
            {
                diagonalMatch = false;
                break;
            }
        }

        // Check anti-diagonal
        for (int i = 1, j = this->gameBoard->cols; i <= this->gameBoard->rows; i++, j--)
        {
            if (this->gameBoard->board[i][j]->p == nullptr || this->gameBoard->board[i][j]->p != pieceType)
            {
                antiDiagonalMatch = false;
                break;
            }
        }

        return rowMatch || columnMatch || diagonalMatch || antiDiagonalMatch;
    }
};