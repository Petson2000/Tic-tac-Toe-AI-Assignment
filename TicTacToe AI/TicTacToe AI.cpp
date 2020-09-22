
#include <iostream>
#include <string>

#include "GridBuilder.h"
#include "Player.h"
#include "AI.h"

int main()
{
	bool gameActive = true;
	Player* player = new Player();
	AI* enemy = new AI();
	GridBuilder* gridBuilder = new GridBuilder();
	gridBuilder->GenerateGrid();

	while (gameActive)
	{
		player->PlayTurn();
		gameActive = false;
	}

}