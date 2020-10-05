#pragma once
#include <cstdint>
#include <map>
#include <iostream>
#include "Move.h"
#include <algorithm>

using namespace std;

class AI 
{
public:
	char Mark = 'O';

	char validSquares[3][3];
	char bestMove[1][1];

public:
	bool SearchGridForValidSquares(char grid[3][3]);

	int getGridState(char grid[3][3]);

	int MiniMax(char grid[3][3], int32_t depth, bool isMax);

	Move CalculateBestMove(char grid[3][3]);
	
};