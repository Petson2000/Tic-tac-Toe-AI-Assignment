#pragma once
#include <cstdint>
#include <map>
#include <iostream>
#include "Move.h"
#include <algorithm>
#include "GridBuilder.h"

using namespace std;

class AI 
{
public:
	bool is_Move_Possible(char grid[ROW_SIZE][COL_SIZE]);

	int get_Grid_State(char grid[ROW_SIZE][COL_SIZE]);

	int miniMax(char grid[ROW_SIZE][COL_SIZE], int32_t depth, bool isMax);

	Move calculate_Best_Move(char grid[ROW_SIZE][COL_SIZE]);
	
};