#include "pch.h"
#include "CppUnitTest.h"
#include "../TicTacToe AI/Move.h"
#include "../TicTacToe AI/AI.h"
#include "../TicTacToe AI/GridBuilder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MiniMaxUnitTest
{
	TEST_CLASS(MiniMaxUnitTest)
	{
	public:

		/* This test makes sure that the algorithm returns a valid node on the grid,
		if it returns -1 on either x or y its invalid
		*/
		TEST_METHOD(ReturnValidNode)
		{
			AI* AIPlayer = new AI();
			GridBuilder* gridBuilder = new GridBuilder();
			
			char grid[3][3];
			
			for (int i = 0; i < 3; i++)
			{
				Move currentMove = {-1, -1};
			
				currentMove = AIPlayer->CalculateBestMove(grid);
				
				if (currentMove.row == -1 || currentMove.column == -1)
				{
					Assert::Fail;
				}
			}
		}



		/* As the default value of the move is -1000 the minimax should never return -1000 as the move value,
		if it does that means that the algorithm doesnt work.
		*/
		TEST_METHOD(MiniMaxReturnAboveZero)
		{
			AI* AIPlayer = new AI();
			GridBuilder* gridBuilder = new GridBuilder();

			char grid[3][3];
			int bestValue = 0;

			for (int row = 0; row < 3; row++)
			{
				for (int column = 0; column < 3; column++)
				{
					if (grid[row][column] != 'X' && grid[row][column] != 'O')
					{
						char prevMark = grid[row][column];
						grid[row][column] = 'O';

						int moveValue = AIPlayer->MiniMax(grid, 0, false);

						grid[row][column] = prevMark;

						if (moveValue > bestValue)
						{
							bestValue = moveValue;
						}
					}
				}
			}

			Assert::IsTrue(bestValue > -1000);
		}
	};
}
