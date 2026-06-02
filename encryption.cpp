#include <iostream>
#include "encryption.h"

static constexpr int passw{ 1234 };

bool checkAccess()
{
	bool isPassValid{ false };
	int userAttemts{ 0 };

	while (!isPassValid)
	{
		std::cout << "---[ACTION] Enter a password: ";
		int userPassw{};
		std::cin >> userPassw;

		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "---[ERROR] Invalid input." << "\n\n";
			continue;
		}

		if (userPassw != passw)
		{
			++userAttemts;
			std::cout << "---[ERROR] Invalid password, you have " << 3 - userAttemts << " attemps" << "\n\n";
			
			if (userAttemts == 3)
			{
				std::cout << "---[ERROR] Please try again later" << "\n\n";
				break;
			}
		}
		else
		{
			isPassValid = true;
			std::cout << "---[SUCCESS] You are entered a BPLA panel" << "\n\n";
			
		}
	}
	return isPassValid;
}