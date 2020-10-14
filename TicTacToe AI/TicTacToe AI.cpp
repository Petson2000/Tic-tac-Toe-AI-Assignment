
#include <iostream>
#include <string>
#include <conio.h>

#include "GridBuilder.h"
#include "Player.h"
#include "Move.h"
#include "AI.h"

#define PLAYER_MARK 'X';
#define AI_MARK 'O';

enum class GameOverState : int
{
	GAME_WON_AI,
	GAME_WON_PLAYER,
	GAME_DRAW
};

void handle_Game_Over(GameOverState state)
{
	switch (state)
	{
	case GameOverState::GAME_WON_AI:
		system("CLS");
		printf("The Enemy Won the game!");
		break;
	case GameOverState::GAME_WON_PLAYER:
		printf("You Won!");
		system("CLS");

		break;
	case GameOverState::GAME_DRAW:
		printf("The game is a draw");
		system("CLS");

		break;

	default:
		break;
	}
}

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
		if (bPlayersTurn)
		{
			if (gridBuilder->checkGameDraw(gridBuilder->grid))
			{
				system("CLS");
				handle_Game_Over(GameOverState::GAME_DRAW);
				bGameActive = false;
				continue;
			}

			printf("Players Turn! \n");
			gridBuilder->draw_Grid();

			playerInput = player->make_Move();


			if (player->is_Valid_Input(playerInput))
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
							if (gridBuilder->checkGameWon(gridBuilder->grid))
							{
								handle_Game_Over(GameOverState::GAME_WON_PLAYER);
								bGameActive = false;
							}

						}
					}
				}
				bPlayersTurn = false;
			}

			else
			{
				_getch();
			}
		}

		int enteredNumber = playerInput;

		if (!bPlayersTurn && bGameActive)
		{
			if (gridBuilder->checkGameDraw(gridBuilder->grid))
			{
				system("CLS");
				handle_Game_Over(GameOverState::GAME_DRAW);
				bGameActive = false;
				continue;
			}

			Move enemyMove;

			printf("AIs Turn! \n");
			_getch();

			enemyMove = enemy->calculate_Best_Move(gridBuilder->grid);

			gridBuilder->grid[enemyMove.row][enemyMove.column] = AI_MARK;

			gridBuilder->draw_Grid();

			if (gridBuilder->checkGameDraw(gridBuilder->grid))
			{
				_getch();
				handle_Game_Over(GameOverState::GAME_DRAW);
				bGameWon = false;
			}

			if (gridBuilder->checkGameWon(gridBuilder->grid))
			{
				handle_Game_Over(GameOverState::GAME_WON_AI);
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