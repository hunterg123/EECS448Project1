#include "board.h"

Board:: Board()
{
	for(int i=0; i<numRows; i++)
	{
		for(int j=0; j<numCols; j++)
		{
			m_board[i][j] = '-';
		}
	}
}
Board:: Board(bool big)
{
	if(big = true) {
		numRows = 20;
		numCols = 20;
	}
	for(int i=0; i<numRows; i++)
	{
		for(int j=0; j<numCols; j++)
		{
			m_board[i][j] = '-';
		}
	}
}

Board::~Board() {}

void Board::printBoard()
{
	int sideNum = 1;
	for(int i=0; i<numRows; i++)
	{
		for(int j=0; j<numCols; j++)
		{
			if(i == 0 && j == 0)
			{
				cout << "  ";
				for(char c = 'A'; c <= 'I'; c++)
				{
					cout << c << " ";
				}
				cout << "\n";
			}
			if(j == 0)
			{
				cout << sideNum << " ";
			}
			cout << m_board[i][j] << " ";
		}
		sideNum++;
		cout << "\n";
	}
}

void Board::updateBoard(int row, int col, char c)
{
	m_board[row][col] = c;
}

char Board::getValue(int row, int col)
{
	return m_board[row][col];
}
