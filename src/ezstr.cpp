/*
###
###	Contributors:
###
###		Ryan Chanlatte
###		Cameron Alexander (preemptively added because I love him)
###
*/

#include "stdafx.h"

// if you need to add additional headers for more functionality, please do so in the "ezstr.h" header first.
#include "ezstr.h"

// NOTE TO POTENTIAL CONTRIBUTORS:
/*
	If you're going to contribute here are some guidelines:
	{
		1.) Please make sure if you're using a string as an argument to a function and you're NOT modifying
			it, please make it constant. It is good practice and it prevents Undefined Behavior (UB).

		2.) Please use sensible variable and function names. Some of the names may seem verbose now, but I
			wanted to err on the side of too detailed, rather than too vague.

		3.) Comment everything.

		4.) I don't want any line to be too long so I'm imposing a hard limit of 110 characters-per-line,
			so try to adhere too it the best you can. Yes, spaces & tabs count, and yes exceptions can
			and probably will be made, but let's keep it low.

		5.) Try to stick to the current syntax and set-up, that is, stick to the style you currently see
			so as to create some level of consistency & readability.

			EXAMPLE: The void functions are first, followed by those that return values, starting with
					 booleans, then integers, ect. It's wholly arbitrary, but make sure it remains
					 consistent and clump similar functions together, primarily by return value.
					 All voids together, all bools together, all ints together, ect.
	}
*/

// convert a string's characters to upper-case
void ezStr::strToUpper(std::string &inputStr)
{
	for (size_t charIndex = 0; charIndex < inputStr.length(); charIndex++)
	{
		if ( islower(inputStr[charIndex]) )
		{
			inputStr[charIndex] = toupper(inputStr[charIndex]);
		}
	}
}

// convert a string's characters to lower-case
void ezStr::strToLower(std::string &inputStr)
{
	for (size_t charIndex = 0; charIndex < inputStr.length(); charIndex++)
	{
		if ( isupper(inputStr[charIndex]) )
		{
			inputStr[charIndex] = tolower(inputStr[charIndex]);
		}
	}
}

// rmv must be a character pointer so it allows multiple characters via character arrays
void ezStr::strCharRmv(std::string& inputStr, const char* rmv)
{
	// iterates over the character array to check for each character in the string
	for (size_t charIndex = 0; charIndex < strlen(rmv); ++charIndex)
	{
		// erase is what removes the characters, remove simply re-orders the string to bring the character
		// currently seleted (rmv[charIndex]) to the front of the string. It's a bit unwieldy at first, but
		// it ultimately makes sense
		inputStr.erase(remove(inputStr.begin(), inputStr.end(), rmv[charIndex]), inputStr.end());
	}
}

void ezStr::conSolidLine(int length)
{
	for (int i = 0; i < length; i++) { std::cout << "_"; };
}

/*
// converts int to Str, can optionally add commas for tuples
std::string ezStr::intToStr(const int& integer, int mode, char delim)
{
	std::string tempStr;
	int tempInt = integer;

	if (mode == 0)
	{
		return std::to_string(tempInt);
	}
	else if (mode == 1)
	{
		tempStr = std::to_string(tempInt);
		
		for (int i = 0; i < tempStr.length(); i++)
		{
			tempStr[i] += delim;
		}
	}
	else if (mode == 2)
	{
		tempStr = std::to_string(tempInt);

		for (int i = 0; i < tempStr.length(); i+2)
		{
			tempStr[i] += delim;
		}
	}

	return tempStr;
}
*/

// returns a boolean value depending on whether or not the two strings are equal
bool ezStr::strCompare(const std::string &inputStr, const std::string &sourceStr)
{
	// if the input string is equal to the source string then return true, otherwise return false
	return inputStr == sourceStr ? true : false;
}

// removes all characters that aren't ascii numerials and convert the resulting value to an integer
int ezStr::strToInt(const std::string &inputStr)
{
	std::string tempStr = inputStr;
	int tempInt = 0;
	char alphabet[] = { "abcdefghijklmnopqrstuvwxyz,.;'/ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	ezStr::strCharRmv(tempStr, alphabet);
	tempInt = std::stoi(tempStr, nullptr, 10);

	return tempInt;
}

// separates a string based on a single character delimiter into smaller components.
std::vector<std::string> ezStr::strDelim(const std::string& inputStr, const char& delim)
{
	std::vector<std::string> tempVec;
	std::string subStr;

	// simply iterates over string to add each character to a sub-string, which is then pushed back
	// into a vector for use later
	for (size_t charIndex = 0; charIndex < inputStr.length(); charIndex++)
	{
		if (inputStr[charIndex] != delim && inputStr[charIndex] != '\0')
		{
			// appending to sub-string the inputStr's characters
			subStr += inputStr[charIndex];
		}
		else if (inputStr[charIndex] == delim)
		{
			// if we hit the input character delimiter, then we'll push back the sub-string
			// into the vector. I clear the sub-string so nothing from the previous iteration
			// interferes with the new one.
			tempVec.push_back(subStr);
			subStr.clear();
		}
	}

	// the conditional gets out without committing the last word that is delimited. Not sure why that is
	// trying to figure it out now. Thus far, this is a band-aid fix.
	tempVec.push_back(subStr);

	return tempVec;
}