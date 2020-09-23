#include "Player.h"

#include <iostream>
#include <string>

char Player::SelectNumber()
{
	printf("Please type the number of the square where you want to place your mark: ");
	
	std::string input;
	getline(std::cin, input);

	if (input != "")
	{
		std::cout << input << std::endl;
		return input.c_str()[0];
	}
}

void Player::ApplyMarkOnGrid()
{

}
