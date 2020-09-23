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

	void GenerateGrid();

	void DisplayGrid();

	bool CheckGridPosition(int number, char mark);
	
public:

	const static int32_t gridSize = 3;

	char grid[gridSize][gridSize];
};
