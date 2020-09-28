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

bool AI::evaluateBoard(char grid[3][3])
{
	for (int row = 0; row < 3; row++)
	{
		//Check all rows to see if anyone has won.
		if (grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2])
		{
			if (grid[row][0] == 'X')
			{
				//Player won
			}

			else if (grid[row][0] == 'O')
			{
				//AI Won
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
				//Player won
			}

			else if (grid[0][column] == 'O')
			{
				//AI Won
			}
		}
	}

	//Check diagonally
	if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
	{
		if (grid[0][0] == 'X')
		{
			//Player won
		}

		else if (grid[0][0] == 'O')
		{
			//AI Won
		}
	}

	return true;
}

int AI::MiniMax(Move node, char grid[3][3], int32_t depth, bool maximizingPlayer)
{
	if (depth == 0 || !evaluateBoard(grid))
	{
		return -1;
		//Return static evalutation of this position
	}

	if (maximizingPlayer)
	{
		int maxValue = -INFINITY;

		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				Move position;
				position.row = row;
				position.column = column;

				int value = MiniMax(position, grid, depth - 1, false);
				maxValue = max(maxValue, value);
			}
		}

		return maxValue;
	}

	else
	{
		int minValue = INFINITY;

		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				Move position;
				position.row = row;
				position.column = column;

				int value = MiniMax(position, grid, depth - 1, true);
				minValue = min(minValue, value);
			}
		}

		return minValue;
	}

	return 0;
}



Move AI::MakeBestMove(char grid[3][3])
{
	int bestValue = -INFINITY;
	Move bestMove;

	bestMove.row = -1;
	bestMove.column = -1;

	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column ++)
		{
			if (grid[row][column] == 'X' && grid[row][column] != 'O')
			{
				continue;
			}

			bestMove.row = row;
			bestMove.column = column;

			int moveValue = MiniMax(bestMove, grid, 3, true);

			if (moveValue >= value)
			{
				bestMove.row = row;
				bestMove.column = column;
				value = moveValue;
			}
		}
	}
	printf("The value of the best node is: %d", bestVal);
	printf("Chosen Row: %f", bestMove.row);
	printf("Chosen Column: %f", bestMove.column);

	return bestMove;
}


