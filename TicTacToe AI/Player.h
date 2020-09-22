#pragma once

#include <string.h>
class Player
{
public:
	char Mark = 'X';

public:
	void PlayTurn();

private:
	void ApplyMarkOnGrid();
};