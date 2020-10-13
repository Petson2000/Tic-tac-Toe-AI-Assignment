#include "GridBuilder.h"

void GridBuilder::draw_Grid()
{
	int number = 1;
	printf("\n-------------\n");
	for (int x = 0; x < gridSize; x++)
	{
		for (int y = 0; y < gridSize; y++)
		{
			printf(" %c |", grid[x][y]);
			number++;
		}

		printf("\n-------------\n");
	}
}

bool GridBuilder::check_Grid_Position(int number, char mark)
{
	for (int row = 0; row < gridSize; row++)
	{
		for (int column = 0; column < gridSize; column++)
		{
			if (grid[row][column] == number)
			{
				grid[row][column] = mark;
				return true;
			}
		}
	}

	return false;
}

bool GridBuilder::checkGameDraw(char grid[ROW_SIZE][COL_SIZE])
{
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			if (grid[row][column] != 'X' && grid[row][column] != 'O')
			{
				//Still valid moves to make
				return false;
			}
		}
	}

	//All valid moves are made, the game is a draw
	printf("All moves have been made, the game is a draw");
	return false;
}

bool GridBuilder::checkGameWon(char grid[ROW_SIZE][COL_SIZE])
{
	for (int row = 0; row < 3; row++)
	{
		//Check all rows to see if anyone has won.
		if (grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2])
		{
			if (grid[row][0] == 'X')
			{
				//Player won
				return true;
			}

			else if (grid[row][0] == 'O')
			{
				//AI Won
				return true;
			}
		}
	}

	//Check columns
	for (int column = 0; column < 3; column++)
	{
		if (grid[0][column] == grid[1][column] && grid[1][column] == grid[2][column])
		{
			if (grid[0][column] == 'X')
			{
				return true;
			}

			else if (grid[0][column] == 'O')
			{
				return true;
			}
		}
	}

	//Check diagonally
	if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
	{
		if (grid[0][0] == 'X')
		{
			return true;
		}

		else if (grid[0][0] == 'O')
		{
			return true;
		}

	}

	if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
	{
		if (grid[0][2] == 'X')
		{
			return true;
		}

		else if (grid[0][2] == 'O')
		{
			return true;
		}
	}

	return false;
}
