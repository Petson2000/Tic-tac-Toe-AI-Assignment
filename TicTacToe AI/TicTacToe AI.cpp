
#include <iostream>
#include <string>

#include "GridBuilder.h"
#include "Player.h"
#include "AI.h"

int main()
{
	int points = 0;
	bool gameActive = true;
	bool playersTurn = true;
	Player* player = new Player();
	AI* enemy = new AI();
	GridBuilder* gridBuilder = new GridBuilder();
	gridBuilder->GenerateGrid();

	while (gameActive)
	{
		gridBuilder->DisplayGrid();

		char playerInput;

		if (playersTurn)
		{
			playerInput = player->SelectNumber();
			if (playerInput <= '0' || playerInput >= '9')
			{
				printf("Invalid input");
			}
		}


		int enteredNumber = playerInput - '0'; //Convert to int

	
		if (gridBuilder->CheckGridPosition(enteredNumber, player->Mark))
		{
			playersTurn = false;
			enemy->PlanMove(gridBuilder->grid);
		}


		if (points > 3)
		{
			gameActive = false;
		}
	}

}
