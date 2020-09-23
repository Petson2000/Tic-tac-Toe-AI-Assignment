#include "AI.h"

void AI::PlanMove(char grid[3][3])
{
	if (CheckValidMoves(grid))
	{
		//Check all rows
		for (int row = 0; row < 3; row++)
		{
			if (grid[row][0] != 'X')
			{

			}
		}
	}
}

bool AI::CheckValidMoves(char grid[3][3])
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
