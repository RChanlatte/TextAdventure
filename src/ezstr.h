#pragma once
#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <vector>

namespace ezStr
{	
	void strCharRmv(std::string &inputStr, const char* rmv); // remove a particular character from a string
	void strToLower(std::string &inputStr); // make a string's characters lower-case
	void strToUpper(std::string &inputStr); // make a string's characters upper-case
	void conSolidLine(int length); // makes a line the width of the console window

	//std::string intToStr(const int& integer, int mode = 0, char delim = NULL); // convert from int to string

	// converts string to integers probably just going to be a wrapper for the atoi function with some safety and conveinence
	int strToInt(const std::string &inputStr);

	// returns a boolean value depending on whether or not two strings are equivalent
	bool strCompare(const std::string &inputStr, const std::string &sourceStr);

	// separates a string based on a single character delimiter into smaller components.
	std::vector<std::string> strDelim(const std::string& inputStr, const char& delim);

};