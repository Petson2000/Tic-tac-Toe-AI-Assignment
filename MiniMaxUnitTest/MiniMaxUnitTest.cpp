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
		TEST_METHOD(return_Valid_Node)
		{
			GridBuilder* gridBuilder = new GridBuilder();
			
			Board board;
			for (int i = 0; i < 3; i++)
			{
				Move currentMove = {-1, -1};
			
				currentMove = AI::calculate_Best_Move(board);
				
				if (currentMove.row == -1 || currentMove.column == -1)
				{
					Assert::Fail;
				}
			}
		}



		/* As the default value of the move is -1000 the minimax should never return -1000 as the move value,
		if it does that means that the algorithm doesn't work.
		*/
		TEST_METHOD(miniMax_Return_Valid_Value)
		{
			GridBuilder* gridBuilder = new GridBuilder();

			Board board;
			int bestValue = 0;

			for (int row = 0; row < 3; row++)
			{
				for (int column = 0; column < 3; column++)
				{
					if (board[row][column] != 'X' && board[row][column] != 'O')
					{
						char prevMark = board[row][column];
						board[row][column] = 'O';

						int moveValue = AI::miniMax(board, 0, false);

						board[row][column] = prevMark;

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
