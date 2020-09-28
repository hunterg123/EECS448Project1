//Player.cpp

#include "player.h"
#include <iostream>

Player::Player() {
    
}

Player::~Player() {}

void Player::SetNumShips(int ships) {numShips = ships; }

void Player::PrintMyShips() { my_ships.printBoard(); }

void Player::PrintEnemyShips() { enemy_ships.printBoard(); }

void Player::UpdateEnemyBoard(int row, int col, bool hit)
{
    if (hit) enemy_ships.updateBoard(row, col, 'X');
    else enemy_ships.updateBoard(row, col, 'O');
}

bool Player::PlaceShip(int size, int row, int col, char direction)
{
    if (direction == 'R') // try to place ship right of pivot coordinates row, col
    {
        if (9 - col >= size) // make sure there are enough indices to place ship
        {
            for (int j = col; j < col + size; j++) // make sure no ships have already been placed in each spot
            {
                if (my_ships.getValue(row, j) != '-') return false; // fails to place if something is already there
            }
            for (int j = col; j < col + size; j++)
            {
                my_ships.updateBoard(row, j, 'S'); // if not returned by now, place ship
            }
        }
        else return false; // fails to place if not enoguh space
    }
    else if (direction == 'L') // Left
    {
        if (col - size + 1 >= 0)
        {
            for (int j = col; j >= col - size + 1; j--)
            {
                if (my_ships.getValue(row, j) != '-') return false;
            }
            for (int j = col; j >= col - size + 1; j--)
            {
                my_ships.updateBoard(row, j, 'S');
            }
        }
        else return false;
    }
    else if (direction == 'D') // Down
    {
        if (9 - row >= size)
        {
            for (int i = row; i < row + size; i++)
            {
                if (my_ships.getValue(i, col) != '-') return false;
            }
            for (int i = row; i < row + size; i++)
            {
                my_ships.updateBoard(i, col, 'S');
            }
        }
        else return false;
    }
    else if (direction == 'U') // Up
    {
        if (row - size + 1 >= 0)
        {
            for (int i = row; i >= row - size + 1; i--)
            {
                if (my_ships.getValue(i, col) != '-')
                {
                    cout << "nope because " << my_ships.getValue(i, col);
                    return false;
                }
            }
            for (int i = row; i >= row - size + 1; i--)
            {
                my_ships.updateBoard(i, col, 'S');
            }
        }
        else return false;
    }
    return true;

}

bool Player::CheckHit(int row, int col)
{
    if (row > 8 || row < 0 || col > 8 || col < 0 || my_ships.getValue(row, col) == 'X') return false;

    if (my_ships.getValue(row, col) == 'S')
    {
        my_ships.updateBoard(row, col, 'X');
        return true;
    }
    else return false;
}
