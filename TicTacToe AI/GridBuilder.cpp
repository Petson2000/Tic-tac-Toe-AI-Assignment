#include "GridBuilder.h"

GridBuilder::GridBuilder()
{
}

GridBuilder::~GridBuilder()
{
	delete grid;
}

void GridBuilder::GenerateGrid()
{
	int number = 1;

	for (int x = 0; x < gridSize; x++)
	{
		for (int y = 0; y < gridSize; y++)
		{
			grid[x][y] = to_string(number).c_str()[0];
			number ++;
		}
	}
}

void GridBuilder::DisplayGrid()
{
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
