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

	int32_t bestVal = 0;
	int32_t value = 0;

public:
	bool SearchGridForValidSquares(char grid[3][3]);

	bool evaluateBoard(char grid[3][3]);

	int MiniMax(Move node, char grid[3][3], int32_t depth, bool maximizingPlayer);

	Move MakeBestMove(char grid[3][3]);
};