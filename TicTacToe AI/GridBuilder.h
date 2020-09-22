#pragma once

#include <iostream>
#include <string>

using namespace std;

class GridBuilder
{
public:

	void GenerateGrid();
	
public:

	const static int32_t gridSize = 3;

	char grid[gridSize][gridSize];
};
