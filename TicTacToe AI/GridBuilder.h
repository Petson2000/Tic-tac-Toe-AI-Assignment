#pragma once

#include <iostream>
#include <string>

#include "Utilities.h"
#include <array>
#include "Move.h"

constexpr int ROW_SIZE = 3;
constexpr int COL_SIZE = 3;

using namespace std;

using Board = std::array < std::array<char, ROW_SIZE>, COL_SIZE>;

class GridBuilder
{
public:
	void draw_Grid(Board &board) noexcept;

	bool check_Moves_Left(int number, char mark) noexcept;

public:
	Move* positions[9];

	Board grid = {'1','2', '3' , '4' , '5' , '6' , '7' , '8' , '9' };

	void GenerateBoard(Board &board) const noexcept;

	bool checkGameDraw(const Board &board) noexcept;

	bool checkGameWon(const Board &board) noexcept;
};
