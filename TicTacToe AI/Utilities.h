#pragma once

class Utilities
{
public:
	static bool CheckInputValid(char input)
	{
		if (input <= 0 || input >= 9)
		{
			return false;
		}

		return true;
	}
};
