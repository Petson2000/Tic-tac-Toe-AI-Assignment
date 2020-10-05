#include "AI.h"

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

int AI::getGridState(char grid[3][3])
{
	for (int row = 0; row < 3; row++)
	{
		//Check all rows to see if anyone has won.
		if (grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2])
		{
			if (grid[row][0] == 'X')
			{
				return -10;
			}

			else if (grid[row][0] == 'O')
			{
				return +10;
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
				return -10;
			}

			else if (grid[0][column] == 'O')
			{
				return +10;
			}
		}
	}

	//Check diagonallys
	if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
	{
		if (grid[0][0] == 'X')
		{
			return -10;
		}

		else if (grid[0][0] == 'O')
		{
			return +10;
		}
	}

	if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
	{
		if (grid[0][2] == 'X')
		{
			return -10;
		}

		else if (grid[0][2] == 'O')
		{
			return +10;
		}
	}

	return 0;
}

int AI::MiniMax(char grid[3][3], int32_t depth, bool isMax)
{
	int startValue = getGridState(grid);

	if (startValue == 10)
	{
		//Player won
		return startValue - depth;
	}

	if (startValue == -10)
	{
		//AI won
		return startValue + depth;
	}

	if (!SearchGridForValidSquares(grid))
	{
		return 0;
	}

	if (isMax)
	{
		int maxValue = -1000;

		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				if (grid[row][column] != 'X' && grid[row][column] != 'O')
				{
					char prevMark;
					prevMark = grid[row][column];
					grid[row][column] = 'O';
					int value = MiniMax(grid, depth + 1, false);
					grid[row][column] = prevMark;
					maxValue = max(value, maxValue);
				}
			}
		}

		return maxValue;
	}

	else
	{
		int minValue = 1000;

		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				if (grid[row][column] != 'X' && grid[row][column] != 'O')
				{
					char prevMark;
					prevMark = grid[row][column];
					grid[row][column] = 'X';

					int value = MiniMax(grid, depth + 1, true);

					grid[row][column] = prevMark;

					minValue = min(minValue, value);
				}
			}
		}

		return minValue;
	}

	return 0;
}



Move AI::CalculateBestMove(char grid[3][3])
{
	int bestValue = -1000;
	Move bestMove;

	bestMove.row = -1;
	bestMove.column = -1;

	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			if (grid[row][column] != 'X' && grid[row][column] != 'O')
			{
				char prevMark = grid[row][column]; 
				grid[row][column] = 'O';
				int moveValue = MiniMax(grid, 0, false);
				grid[row][column] = prevMark;

				if (moveValue > bestValue)
				{
					bestMove.row = row;
					bestMove.column = column;
					bestValue = moveValue;
				}
			}
		}
	}

	printf("The value of the AIs best move is: %d \n", bestValue);
	printf("Best Row: %d \n", bestMove.row);
	printf("Best Column: %d \n", bestMove.column);

	return bestMove;
}
