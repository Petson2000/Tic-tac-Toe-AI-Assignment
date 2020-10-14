
#include <iostream>
#include <string>
#include <conio.h>

#include "GridBuilder.h"
#include "Player.h"
#include "Move.h"
#include "AI.h"

constexpr char PLAYER_MARK = 'X';
constexpr char AI_MARK = 'O';


enum class GameOverState : int
{
	GAME_WON_AI,
	GAME_WON_PLAYER,
	GAME_DRAW
};


void handle_Game_Over(GameOverState state) noexcept
{
	switch (state)
	{

	case GameOverState::GAME_WON_AI:
		system("CLS");
		printf("The Enemy Won the game!\n");
		break;

	case GameOverState::GAME_WON_PLAYER:
		printf("You Won!\n");
		system("CLS");
		break;
	case GameOverState::GAME_DRAW:
		printf("The game is a draw\n");
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
	bool bAITurn = true;
	bool bGameWon = false;

	char playerInput;

	auto player = make_unique<Player>();

	auto gridBuilder = make_unique<GridBuilder>();

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
				break;
			}

			printf("Players Turn! \n");
			gridBuilder->draw_Grid();

			playerInput = player->make_Move();


			if (player->is_Valid_Input(playerInput))
			{
				for (int row = 0; row < ROW_SIZE; row++)
				{
					for (int column = 0; column < COL_SIZE; column++)
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
								return 0;
							}

						}
					}
				}

				bPlayersTurn = false;
				bAITurn = true;
			}

			else
			{
				_getch();
			}
		}

		if (!bPlayersTurn && bGameActive && bAITurn)
		{
			if (gridBuilder->checkGameDraw(gridBuilder->grid))
			{
				system("CLS");
				handle_Game_Over(GameOverState::GAME_DRAW);
				bGameActive = false;
				break;
			}

			Move enemyMove;

			printf("AIs Turn! \n");
			_getch();

			enemyMove = AI::calculate_Best_Move(gridBuilder->grid);

			gridBuilder->grid[enemyMove.row][enemyMove.column] = AI_MARK;

			gridBuilder->draw_Grid();

			_getch();
			bPlayersTurn = true;

			if (gridBuilder->checkGameDraw(gridBuilder->grid))
			{
				_getch();
				handle_Game_Over(GameOverState::GAME_DRAW);
				bGameWon = false;
				return 0;
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
		}
	}
}