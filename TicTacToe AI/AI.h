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
	int32_t index = 0;

	int32_t bestVal = 0;
	int32_t value = 0;

public:
	void PlanMove(char grid[3][3]);

	bool SearchGridForValidSquares(char grid[3][3]);

	bool evaluateBoard(char grid[3][3]);

	int MiniMax(char grid[3][3], int32_t depth);

	Move MakeBestMove(char grid[3][3]);
};