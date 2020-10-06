#pragma once

#include <iostream>
#include <string>

#include "Utilities.h"
#include "Move.h"

#define ROW_SIZE 3
#define COL_SIZE 3

using namespace std;

class GridBuilder
{
public:
	void draw_Grid();

	bool check_Grid_Position(int number, char mark);

	int gridSize = 3;
	
public:
	Move* positions[9];

	char grid[ROW_SIZE][COL_SIZE] = { {'1', '2', '3'}, { '4', '5', '6'}, {'7', '8', '9'} };

	bool checkGameDraw(char grid[ROW_SIZE][COL_SIZE]);

	bool checkGameWon(char grid[ROW_SIZE][COL_SIZE]);
};
