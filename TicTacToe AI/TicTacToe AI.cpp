
#include <iostream>
#include <string>
#include <conio.h>

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
	int gridSize = 0;

	char playerInput;
	Player* player = new Player();
	AI* enemy = new AI();
	GridBuilder* gridBuilder = new GridBuilder();

	while (gameActive)
	{
		system("CLS");
		if (playersTurn)
		{
			if (playersTurn)
			{
				printf("Players Turn! \n");
				gridBuilder->DrawGrid();

				playerInput = player->SelectNumber();

				if (playerInput <= '0' || playerInput > '9')
				{
					printf("Invalid input");
				}

				else
				{
					for (int row = 0; row < 3; row++)
					{
						for (int column = 0; column < 3; column++)
						{
							if (gridBuilder->grid[row][column] == playerInput)
							{
								printf("Player Chosen Row: %d \n", row);
								printf("Player Chosen Column: %d \n", column);

								gridBuilder->grid[row][column] = 'X';
							}
						}
					}

					playersTurn = false;
				}
			}
		}
	
		int enteredNumber = playerInput;

		if (!playersTurn)
		{
			Move enemyMove;
	
			printf("AIs Turn! \n");
			_getch();
	
			enemyMove = enemy->CalculateBestMove(gridBuilder->grid);
			gridBuilder->grid[enemyMove.row][enemyMove.column] = 'O';
			gridBuilder->DrawGrid();
	
			if (gridBuilder->checkGameDraw(gridBuilder->grid))
			{
				_getch();
				gameWon = false;
			}
	
			if (gridBuilder->checkGameWon(gridBuilder->grid))
			{
				printf("Game is won!");
				gameWon = true;
			}
	
			if (gameWon)
			{
				gameActive = false;
			}

			_getch();
			playersTurn = true;
		}
	}

}