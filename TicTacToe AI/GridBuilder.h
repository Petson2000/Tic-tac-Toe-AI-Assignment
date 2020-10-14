#pragma once

#include <iostream>
#include <string>

#include "Utilities.h"
#include <array>
#include "Move.h"

#define ROW_SIZE 3
#define COL_SIZE 3

using namespace std;

using Board = std::array<std::array<char, 3>, 3>;

class GridBuilder
{
public:
	void draw_Grid();

	bool check_Moves_Left(int number, char mark);

	int gridSize = 3;
	
public:
	Move* positions[9];

	Board grid = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

	//char grid[ROW_SIZE][COL_SIZE] = { {'1', '2', '3'}, { '4', '5', '6'}, {'7', '8', '9'} };

	bool checkGameDraw(const Board &board);

	bool checkGameWon(const Board &board);
};
