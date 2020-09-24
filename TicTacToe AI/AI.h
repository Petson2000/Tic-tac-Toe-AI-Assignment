#pragma once
#include <cstdint>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
class AI 
{
public:
	char Mark = 'O';

	char validSquares[3][3];

	std::map<char, char> validPositions;

	int32_t index = 0;

	int32_t bestVal = 0;
	int32_t value = 0;

public:
	void PlanMove(char grid[3][3]);

	bool SearchGridForValidSquares(char grid[3][3]);

	int evaluateBoard(char grid[3][3]);

	bool CheckRow(char grid[3][3], char RowPos, char ColumnPos);

	int MiniMax(char grid[3][3], int32_t depth, bool isMaximizingPlayer);

	bool isNumber(char input);
};