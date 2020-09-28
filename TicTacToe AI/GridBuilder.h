#pragma once

#include <iostream>
#include <string>

#include "Utilities.h"

using namespace std;

class GridBuilder
{
public:

	GridBuilder();
	~GridBuilder();

	void DrawGrid();

	bool CheckGridPosition(int number, char mark);
	
public:

	const static int32_t gridSize = 3;

	char grid[gridSize][gridSize] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

	bool checkGameWon(char grid[3][3]);
};
