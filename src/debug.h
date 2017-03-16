#pragma once

#include <string>
#include <iostream>
#include <Windows.h>

extern bool IS_DEBUG;
extern char Generic_Err[51];
extern std::wstring gameVer;

namespace DEBUG
{
	// outputs "*DEBUG* " to console, used for generic checks
	void debugTag();
	// outputs "*DEBUG* [input] to the console used for testing inputs
	void echo(std::string const &inputStr);
	// same functionality as echo(), but with wide strings
	void wecho(std::wstring const &inputStr);
	// create a function that times the intervals between while() ticks, has optional argument(s): "previousInput"
	// which has similar functionality but counts how long before the last input
	void updateTick_Display(double previousUpdate, double previousInput = -1.0);
}