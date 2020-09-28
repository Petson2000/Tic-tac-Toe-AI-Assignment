#pragma once

struct Move
{
	int row;
	int column;
	int score;
	Move();
	Move(int row, int column);
};