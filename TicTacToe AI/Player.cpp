#include "Player.h"

#include <iostream>
#include <string>

void Player::PlayTurn()
{
	printf("Please type the number of the square where you want to place your mark");
	
	std::string input;
	getline(std::cin, input);

	if (input != "")
	{
		char enteredElement = input.c_str()[0];

		if (enteredElement >= '1' && enteredElement <= '9')
		{
			//Todo: Check that location to make sure there is no node there.

			ApplyMarkOnGrid();
		}

		else
		{
			printf("Invalid Input");
		}
	}

	else
	{
		printf("No Input detected, please try again");
	}
}

void Player::ApplyMarkOnGrid()
{
}
