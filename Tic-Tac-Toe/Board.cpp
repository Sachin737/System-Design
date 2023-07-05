#include <bits/stdc++.h>
#include "Board.hpp"
#include "Cell.hpp"
#include "Piece.hpp"
using namespace std;

Board::Board(int r = 3, int c = 3)
{
    this->rows = r;
    this->cols = c;
    this->board.resize(r + 1, vector<Cell *>(c + 1));

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            this->board[i][j] = new Cell();
        }
    }
}

Board::Board() {}

bool Board::addPiece(int row, int column, Piece *playingPiece)
{
    if (board[row][column]->p != nullptr)
    {
        return false;
    }
    board[row][column]->p = playingPiece;
    return true;
}

vector<pair<int, int>> Board::getFreeCells()
{
    vector<pair<int, int>> freeCells;

    for (int i = 1; i <= this->rows; i++)
    {
        for (int j = 1; j <= this->cols; j++)
        {
            if (board[i][j]->p == nullptr)
            {
                freeCells.push_back({i, j});
            }
        }
    }

    return freeCells;
}

void Board::printBoard()
{
    for (int i = 1; i <= this->rows; i++)
    {
        for (int j = 1; j <= this->cols; j++)
        {
            cout << "  ";
            if (board[i][j]->p != nullptr)
            {
                cout << static_cast<char>(board[i][j]->p->piece) << "  |";
            }
            else
            {
                cout << "   |";
            }
        }
        cout << endl;
    }
}