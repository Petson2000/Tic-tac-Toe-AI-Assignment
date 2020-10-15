#pragma once

class Utilities
{
public:
	static bool CheckInputValid(char input) noexcept
	{
		if (input <= 0 || input >= 9)
		{
			return false;
		}

		return true;
	}
};
