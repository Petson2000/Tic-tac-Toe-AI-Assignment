
#include <iostream>
#include <string>
#include <conio.h>

#include "GridBuilder.h"
#include "Player.h"
#include "Move.h"
#include "AI.h"

#define PLAYER_MARK 'X';
#define AI_MARK 'O';

int main()
{
	bool bGameActive = true;
	bool bPlayersTurn = true;
	bool bGameWon = false;

	char playerInput;

	Player* player = new Player();
	AI* enemy = new AI();
	GridBuilder* gridBuilder = new GridBuilder();

	while (bGameActive)
	{
		system("CLS");
		if (bPlayersTurn && bGameActive)
		{
			if (bPlayersTurn)
			{
				printf("Players Turn! \n");
				gridBuilder->draw_Grid();

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

								gridBuilder->grid[row][column] = PLAYER_MARK;
							}
						}
					}

					bPlayersTurn = false;
				}
			}
		}
	
		int enteredNumber = playerInput;

		if (!bPlayersTurn && bGameActive)
		{
			Move enemyMove;
	
			printf("AIs Turn! \n");
			_getch();
	
			enemyMove = enemy->calculate_Best_Move(gridBuilder->grid);

			gridBuilder->grid[enemyMove.row][enemyMove.column] = AI_MARK;

			gridBuilder->draw_Grid();
	
			if (gridBuilder->checkGameDraw(gridBuilder->grid))
			{
				_getch();
				printf("The game is a draw!");
				bGameWon = false;
			}
	
			if (gridBuilder->checkGameWon(gridBuilder->grid))
			{
				printf("Game is won!");
				bGameWon = true;
			}
	
			if (bGameWon)
			{
				bGameActive = false;
			}

			_getch();
			bPlayersTurn = true;
		}
	}

	if (!bGameActive)
	{
		delete player;
		delete enemy;
		delete gridBuilder;
	}
}