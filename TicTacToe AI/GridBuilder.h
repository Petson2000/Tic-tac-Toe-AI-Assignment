#pragma once

#include <iostream>
#include <string>

#include "Utilities.h"
#include "Move.h"

using namespace std;

class GridBuilder
{
public:
	void draw_Grid();

	bool check_Grid_Position(int number, char mark);

	const static int gridSize = 3;

	
public:
	Move* positions[9];

	char grid[gridSize][gridSize] = { {'1', '2', '3'}, { '4', '5', '6'}, {'7', '8', '9'} };

	bool checkGameDraw(char grid[3][3]);

	bool checkGameWon(char grid[3][3]);
};
