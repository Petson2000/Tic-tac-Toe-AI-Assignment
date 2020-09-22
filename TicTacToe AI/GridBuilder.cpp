#include "GridBuilder.h"

void GridBuilder::GenerateGrid()
{
	int number = 1;

	for (int x = 0; x < gridSize; x++)
	{
		for (int y = 0; y < gridSize; y++)
		{
			grid[x][y] = to_string(number).c_str()[0];
			number += 1;
		}
	}

	printf("\n------------\n");

	for (int x = 0; x < gridSize; x++)
	{
		for (int y = 0; y < gridSize; y++)
		{
			printf(" %c |", grid[x][y]);
		}

		printf("\n------------\n");
	}
}
