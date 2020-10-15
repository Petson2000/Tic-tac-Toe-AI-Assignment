#include "Player.h"

#include <iostream>
#include <string>
#include <sstream>

bool Player::is_Valid_Input(char playerInput) noexcept
{
	if (playerInput == '\n')
	{
		printf("Input can't be empty, please try again!");
		return false;
	}

	if (playerInput <= '0' || playerInput > '9')
	{
		printf("Input was outside the scope of the grid, please try again!");
		return false;
	}

	return true;
}

char Player::make_Move()
{
	printf("Please type the number of the square where you want to place your mark: ");

	std::string input;
	getline(std::cin, input);

	stringstream stream(input);
	int inputToNum = 0;

	stream >> inputToNum;

	if (inputToNum <= ROW_SIZE * COL_SIZE)
	{
		std::cout << "Player chosen square is: " << input << std::endl;
	}

	return input.c_str()[0];
}