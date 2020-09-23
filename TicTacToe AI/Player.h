#pragma once

#include <string.h>
class Player
{
public:
	char Mark = 'X';

public:
	char SelectNumber();

private:
	void ApplyMarkOnGrid();
};