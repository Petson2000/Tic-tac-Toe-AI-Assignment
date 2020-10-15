#pragma once
#include <cstdint>
#include <map>
#include <iostream>
#include "Move.h"
#include <algorithm>
#include "GridBuilder.h"

using namespace std;

namespace AI 
{
	bool is_Move_Possible(const Board &board) noexcept;

	int get_Grid_State(const Board &board) noexcept;

	int miniMax(Board &board, int32_t depth, bool isMax);

	Move calculate_Best_Move(Board &board);
};