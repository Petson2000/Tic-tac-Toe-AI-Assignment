#include "AI.h"

bool AI::is_Move_Possible(const Board& board) noexcept
{
	for (auto row : board)
	{
		for (auto mark : row)
		{
			if (mark != 'X' && mark != 'O')
			{
				return true;
			}
		}
	}

	return false;
}

int AI::get_Grid_State(const Board& board) noexcept
{

	//todo: redo

	for (int row = 0; row < 3; row++)
	{
		//Check all rows to see if anyone has won.
		if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
		{
			if (board[row][0] == 'X')
			{
				return -10;
			}

			else if (board[row][0] == 'O')
			{
				return +10;
			}
		}
	}

	//Check columns
	for (int column = 0; column < COL_SIZE; column++)
	{
		if (board[0][column] == board[1][column] && board[1][column] == board[2][column])
		{
			if (board[0][column] == 'X')
			{
				return -10;
			}

			else if (board[0][column] == 'O')
			{
				return +10;
			}
		}
	}

	//Check diagonally
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'X')
		{
			return -10;
		}

		else if (board[0][0] == 'O')
		{
			return +10;
		}
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == 'X')
		{
			return -10;
		}

		else if (board[0][2] == 'O')
		{
			return +10;
		}
	}

	return 0;
}

int AI::miniMax(Board& board, int32_t depth, bool isMax)
{
	const int startValue = get_Grid_State(board);

	if (startValue == 10)
	{
		//Player won
		return startValue - depth;
	}

	if (startValue == -10)
	{
		//AI won
		return startValue + depth;
	}

	if (!is_Move_Possible(board))
	{
		return 0;
	}

	if (isMax)
	{
		int maxValue = -1000;

		for (int row = 0; row < ROW_SIZE; row++)
		{
			for (int column = 0; column < COL_SIZE; column++)
			{
				if (board[row][column] != 'X' && board[row][column] != 'O')
				{
					char prevMark;
					prevMark = board[row][column];
					board[row][column] = 'O';
					int value = miniMax(board, depth + 1, false);
					board[row][column] = prevMark;
					maxValue = max(value, maxValue);
				}
			}
		}

		return maxValue;
	}

	else
	{
		int minValue = 1000;

		for (int row = 0; row < ROW_SIZE; row++)
		{
			for (int column = 0; column < COL_SIZE; column++)
			{
				if (board[row][column] != 'X' && board[row][column] != 'O')
				{
					char prevMark;
					prevMark = board[row][column];
					board[row][column] = 'X';

					int value = miniMax(board, depth + 1, true);

					board[row][column] = prevMark;

					minValue = min(minValue, value);
				}
			}
		}

		return minValue;
	}

	return 0;
}



Move AI::calculate_Best_Move(Board& board)
{
	int bestValue = -1000;
	Move bestMove;

	bestMove.row = -1;
	bestMove.column = -1;

	for (int row = 0; row < ROW_SIZE; row++)
	{
		for (int column = 0; column < COL_SIZE; column++)
		{
			if (board[row][column] != 'X' && board[row][column] != 'O')
			{
				char prevMark = board[row][column];
				board[row][column] = 'O';
				const int moveValue = miniMax(board, 0, false);
				board[row][column] = prevMark;

				if (moveValue > bestValue)
				{
					bestMove.row = row;
					bestMove.column = column;
					bestValue = moveValue;
				}
			}
		}
	}

	printf("The value of the AIs best move is: %d \n", bestValue);
	printf("Best Row: %d \n", bestMove.row);
	printf("Best Column: %d \n", bestMove.column);

	return bestMove;
}
