#pragma once

class AI 
{
public:
	char Mark = 'O';

public:
	void PlanMove(char grid[3][3]);

	bool CheckValidMoves(char grid[3][3]);
};