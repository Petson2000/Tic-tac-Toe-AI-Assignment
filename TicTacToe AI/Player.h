#pragma once

#include <string.h>
#include "GridBuilder.h"
class Player
{
public:
	char Mark = 'X';

public:
	bool is_Valid_Input(char playerInput);

	char make_Move();
};