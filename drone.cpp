#include <iostream>
#include <windows.h>
#include "drone.h"

namespace Drone
{
	bool isWork{ false };
	bool isFlight{ false };
	bool onGround{ true };
	uint16_t altitude{ 0 };
	uint8_t speed{ 0 };
}


char chooseOperation()
{
	while (true)
	{
		std::cout
			<< "Enter an operations" << "\n\n"
			<< "ARM(On/Off engine) - choose O " << '\n'
			<< "TAKEOFF(Start high to work) - choose F" << '\n'
			<< "LAND - Choose L" << '\n'
			<< "SET SPEED - Choose S" << '\n'
			<< "SET ALTITUDE - Choose A" << '\n'
			<< "EXIT - Choose E" << '\n';

		std::cout << "... ";
		char c{};
		std::cin >> c;
		c = std::toupper(c);

		switch (c)
		{
		case('E'):
			std::cout << "Exiting..." << '\n';
			return 0;
		case('O'):
			isWorking();
			break;
		case('F'):
			isFlighting();
			break;
		case('L'):
			landDrone();
			break;
		case 'S':
			setSpeed();
			break;
		case 'A':
			setAltitude();
			break;
		default:
			std::cout << "---[ERROR] Invalid input. Try again" << "\n\n";

		}
	}
}


void isFlighting()
{
	if (Drone::isWork && Drone::onGround && (Drone::altitude != 10))
	{
		Drone::onGround = false;
		Drone::isFlight = true;
		Drone::altitude = 10;
		std::cout << "---[SUCCESS] The flight high has been changed on the " << Drone::altitude << " meters. "
			<< "Current high is " << Drone::altitude << "\n\n";
	}
	else
	{
		if (Drone::isWork && Drone::onGround == true)
		{
			std::cout << "---[INFO] The start high is already set" << "\n\n";
		}
		else
		{
			std::cout << "---[FAILED] Your drone isn't working" << "\n\n";
		}
	}
}

void landDrone()
{
	if (Drone::isWork && Drone::isFlight && Drone::altitude > 0)
	{
		std::cout << "---[INFO] The drone speed is " << static_cast<int>(Drone::speed)
			<< " the high flight " << Drone::altitude << "\n\n";

		while (Drone::speed > 0)
		{
			--Drone::speed;
			std::cout << "---[INFO] The drone speed is " << static_cast<int>(Drone::speed) << "\n\n";
			Sleep(300);
		}

		while (Drone::altitude > 0)
		{
			--Drone::altitude;
			std::cout << "---[INFO] The drone high is " << static_cast<int>(Drone::altitude) << "\n\n";
			Sleep(300);
		}

		Drone::isFlight = false;
		Drone::onGround = true;
		std::cout << "---[SUCCESS] The landing was succesfully completed" << "\n\n";
	}

	else
	{
		std::cout << "---[FAILED] Your drone is on the " << Drone::altitude
			<< " and speed is " << static_cast<int>(Drone::speed) << "\n\n";
	}

}

void isWorking()
{
	if (Drone::isWork == false)
	{
		Drone::isWork = true;
		std::cout << "---[SUCCESS] The drone was succesfully on" << "\n\n";
	}
	else if (Drone::isWork == true && !Drone::isFlight && (static_cast<int>(Drone::speed) == 0))
	{
		Drone::isWork = false;
		std::cout << "---[SUCCESS] The drone was succesfully off" << "\n\n";
	}
	else
	{
		std::cout << "---[FAILED] You cannot off/on your drone, the speed is " << static_cast<int>(Drone::speed)
			<< " and high is " << Drone::altitude << "\n\n";
	}
}

void setSpeed()
{
	if (Drone::isWork && Drone::isFlight && !Drone::onGround && Drone::altitude > 0)
	{
		bool userRightInput{ false };
		while (!userRightInput)
		{
			std::cout << "[ACTION] Please enter the drone speed(0 - 100 km/h)" << "\n\n";
			int userSpeed{ 0 };
			std::cin >> userSpeed;

			if (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "---[ERROR] Invalid input.(only numbers)" << "\n\n";
				continue;
			}

			if (userSpeed <= 100 && userSpeed >= 0)
			{
				userRightInput = true;
				Drone::speed = static_cast<uint8_t>(userSpeed);

				std::cout << "---[SUCCESS] The speed was succesfully changed to "
					<< static_cast<int>(Drone::speed) << '\n';
				std::cout << "---[INFO] Current speed is " << static_cast<int>(Drone::speed)
					<< " the high is " << Drone::altitude << "\n\n";
			}
			else
			{
				std::cout << "---[ERROR] The scope is between 0 - 100" << "\n\n";
			}
		}
	}
	else
	{
		std::cout << "---[ERROR] Your drone is off or he is on the ground" << '\n';
		std::cout << "---[INFO] Please set an altitude or start high to work" << "\n\n";
	}
}

void setAltitude()
{
	bool userInputRightAltitude{ false };
	if (Drone::isWork) {
		while (!userInputRightAltitude)
		{
			std::cout << "---[ACTION] Please enter your drone high(0 - 500 metters)" << "\n\n";
			int altitudeUserInput{ 0 };
			std::cin >> altitudeUserInput;

			if (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "---[ERROR] Invalid input.(only numbers)" << "\n\n";
				continue;
			}

			if (500 >= altitudeUserInput && 0 <= altitudeUserInput)
			{
				Drone::altitude = altitudeUserInput;
				userInputRightAltitude = true;
				std::cout << "---[INFO] Your drone is on " << Drone::altitude << " metters " << "\n\n";
				Drone::isFlight = true;
				Drone::onGround = false;

				if (Drone::altitude == 0)
				{
					std::cout << "---[INFO] Your drone is on the ground" << "\n\n";
					Drone::speed = 0;
					Drone::isFlight = false;
					Drone::onGround = true;
				}
			}
			else
			{
				std::cout << "---[ERROR] Invalid input, please enter a number between 0 - 500" << "\n\n";
			}

		}
	}

}