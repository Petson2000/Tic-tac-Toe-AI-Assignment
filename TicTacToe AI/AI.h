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
	bool is_Move_Possible(char grid[3][3]);

	int get_Grid_State(char grid[3][3]);

	int miniMax(char grid[3][3], int32_t depth, bool isMax);

	Move calculate_Best_Move(char grid[3][3]);
	
};