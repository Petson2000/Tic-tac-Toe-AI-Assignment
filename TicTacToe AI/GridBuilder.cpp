#include "GridBuilder.h"

GridBuilder::GridBuilder()
{

}

GridBuilder::~GridBuilder()
{
	//delete grid;
}

void GridBuilder::GenerateGrid()
{
	for (int x = 0; x < gridSize; x++)
	{
		for (int y = 0; y < gridSize; y++)
		{
			grid[x][y] = '_';
		}
	}
}

void GridBuilder::DisplayGrid()
{
	printf("\n------------------\n");
	int number = 1;
	for (int x = 0; x < gridSize; x++)
	{
		for (int y = 0; y < gridSize; y++)
		{
			printf("%d:", number); //Change to square number later
			printf(" %c |", grid[x][y]);
			number++;
		}

		printf("\n------------------\n");
	}
}

bool GridBuilder::CheckGridPosition(int number, char mark)
{
	int index = number - 1;
	int row = index / gridSize;
	int column = index % gridSize;

	char gridPosition = grid[row][column];

	if (gridPosition == 'X' || gridPosition == 'O')
	{
		printf("That position is taken");
		return false;
	}

	grid[row][column] = mark;
	return true;
}

bool GridBuilder::checkGameWon(char grid[3][3])
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

	return false;
}
