#include "debug.h"

/*
	This file is intended as a general repository of debug-based functions/actions
*/

extern bool IS_DEBUG = true;
extern char Generic_Err[51] = "\n\n***ERROR***\nSomething went wrong.\n***ERROR***\n\n\0";
extern std::wstring gameVer = L"v0.3.5-a";

static double currentFrame = GetCurrentTime();

void DEBUG::debugTag()
{
	std::cout << "*DEBUG* ";
}
void DEBUG::echo(std::string const &inputStr)
{
	std::cout << "*DEBUG* You input: " << inputStr << "\n" << std::endl;
}
void DEBUG::wecho(std::wstring const &inputStr)
{
	std::wcout << "*DEBUG* You input: " << inputStr << "\n" << std::endl;
}

void DEBUG::updateTick_Display(double previousUpdate, double previousInput)
{
	if (previousInput <= -1.0)
	{
		currentFrame = GetCurrentTime();
		double updateElapsed = currentFrame - previousUpdate;
		previousUpdate = currentFrame;
		std::cout << "*DEBUG* " << updateElapsed << " miliseconds have elapsed since last update.\n" << std::endl;
	}
	else if (previousInput >= 0.0)
	{
		currentFrame = GetCurrentTime();
		double updateElapsed = currentFrame - previousUpdate;
		double inputElapsed = currentFrame - previousInput;
		previousUpdate = currentFrame;
		previousInput = currentFrame;
		std::cout << "*DEBUG* " << updateElapsed << " miliseconds have elapsed since last update.\n*DEBUG* " << inputElapsed << " miliseconds since last input." << std::endl;
	}
}