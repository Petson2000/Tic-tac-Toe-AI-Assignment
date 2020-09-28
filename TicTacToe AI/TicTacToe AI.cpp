
#include <iostream>
#include <string>

#include "GridBuilder.h"
#include "Player.h"
#include "Move.h"
#include "AI.h"

int main()
{
	int points = 0;
	bool gameActive = true;
	bool playersTurn = true;
	bool gameWon = false;

	char playerInput;

	Player* player = new Player();
	AI* enemy = new AI();
	GridBuilder* gridBuilder = new GridBuilder();
	gridBuilder->DrawGrid();

	while (gameActive)
	{

		if (playersTurn)
		{
			gridBuilder->DrawGrid();

			playerInput = player->SelectNumber();

			if (playerInput <= '0' || playerInput >= '9')
			{
				printf("Invalid input");
			}

		}

		int enteredNumber = playerInput;

		if (gridBuilder->CheckGridPosition(enteredNumber, player->Mark))
		{
			playersTurn = false;

			Move enemyMove;
			
			enemyMove = enemy->MakeBestMove(gridBuilder->grid);
			
			gridBuilder->grid[enemyMove.row][enemyMove.column] = 'O';
			
			playersTurn = true;
		}

		if (gridBuilder->checkGameWon(gridBuilder->grid))
		{
			gameWon = true; 
		}


		if (gameWon)
		{
			gameActive = false;
		}
	}

}

//Returns true if the game is won.
