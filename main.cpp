#include <iostream>
#include <cstdint>
#include <string>
#include <windows.h>
#include "encryption.h"
#include "drone.h"

int main()
{
	if (checkAccess())
	{
		chooseOperation();
	}

	return 0;
}