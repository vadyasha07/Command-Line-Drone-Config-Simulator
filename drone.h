#ifndef DRONE_H
#define DRONE_H
#include <cstdint>

namespace Drone
{
	extern bool isWork;
	extern bool isFlight;
	extern bool onGround;
	extern uint16_t altitude;
	extern uint8_t speed;
}

void isFlighting();
void landDrone();
void isWorking();
void setSpeed();
void setAltitude();
char chooseOperation();

#endif