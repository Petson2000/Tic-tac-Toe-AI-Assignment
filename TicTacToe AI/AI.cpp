#include "AI.h"

void AI::PlanMove(char grid[3][3])
{
	if (SearchGridForValidSquares(grid))
	{
		evaluateBoard(grid);
	}
}

bool AI::SearchGridForValidSquares(char grid[3][3])
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (grid[x][y] != 'X' && grid[x][y] != 'O')
			{
				return true;
			}
		}
	}

	return false;
}

int AI::evaluateBoard(char grid[3][3])
{
	//Check if the game is won.
	index = 0;

	for (int row = 0; row < 3; row++)
	{
		//Check all rows to see if anyone has won.

		if (CheckRow(grid, row, 0))
		{
			if (CheckRow(grid, row, 1))
			{
				if (CheckRow(grid, row, 2))
				{
					if (grid[row][0] == 'X')
					{
						return +10;
					}

					if (grid[row][0] == 'O')
					{
						return -10;
					}
				}
			}
		}

		//Todo cleaner checks
		//Todo: Implement search columns and diagonal.
	}

	return 0;
}

bool AI::CheckRow(char grid[3][3], char RowPos, char ColumnPos)
{
	if (grid[RowPos][ColumnPos] == grid[RowPos][ColumnPos + 1])
	{
		if (grid[RowPos][ColumnPos + 1] == grid[RowPos][ColumnPos + 2])
		{
			return true;
		}
	}

	return false;
}

int AI::MiniMax(char grid[3][3], int32_t depth, bool isMaximizingPlayer)
{
	if (evaluateBoard(grid) == 10)
	{
		//Player won
	}

	if (evaluateBoard(grid) == -10)
	{
		//AI Won
	}

	//if (evaluateBoard(grid) == 0)
	//{
	//	//Game was a tie
	//}
	if (isMaximizingPlayer)
	{
		bestVal = -INFINITY;
		value = 0; //FIX LATER 

		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				if (!isNumber(grid[row][column]))
				{
					continue;
				}

				MiniMax(grid, depth + 1, false);

				bestVal = max(bestVal, MiniMax(grid, depth + 1, !isMaximizingPlayer));

				return bestVal;
			}
		}
	}

	else
	{
		bestVal = INFINITY;

		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				value = MiniMax(grid, depth + 1, true);
				bestVal = min(bestVal, value);
				return bestVal;
			}
		}
	}

	return 0;
}

bool AI::isNumber(char input)
{
	if (isalnum(input))
	{
		if (input < '0' || input > '9')
		{
			return false;
		}

		return true;
	}

	return false;
}


