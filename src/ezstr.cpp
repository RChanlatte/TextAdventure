#include "ezStr.hpp"

// changes the case of a string to upper-case
void ezStr::ToUpper(std::string& inputStr)
{
   // iterates over each character in a string
   for (size_t charIndex = 0; charIndex < inputStr.length(); charIndex++)
	{
      // if the character is lower-case, convert to upper-case; otherwise, keep going
		if (islower(inputStr[charIndex]))
		{
			inputStr[charIndex] = toupper(inputStr[charIndex]);
		}
	}
}

// changes the case of a string to lower-case
void ezStr::ToLower(std::string& inputStr)
{
   // iterates over each character in a string
	for (size_t charIndex = 0; charIndex < inputStr.length(); charIndex++)
	{
      // if the character is lower-case, convert to upper-case; otherwise, keep going
		if (isupper(inputStr[charIndex]))
		{
			inputStr[charIndex] = tolower(inputStr[charIndex]);
		}
	}
}

// change the case of a string to capitalize each word
void ezStr::Capitalize(std::string& inputStr)
{
   // uppercases first character
   inputStr[0] = toupper(inputStr[0]);

   // iterates over the characters in the string
   for (size_t charIndex = 1; charIndex < inputStr.length(); charIndex++)
   {
      // if the last character was an alphabetical, ascii character, then convert to lower-case
      if (isalpha(inputStr[charIndex - 1]))
      {
         inputStr[charIndex] = tolower(inputStr[charIndex]);
      }
      // if it isn't an alphabetical, ascii character, then convert to upper-case
      else
      {
         inputStr[charIndex] = toupper(inputStr[charIndex]);
      }
   }
}

// replaces a single character in a string to some other, programmer defined, character
void ezStr::ReplaceAll(char charToReplace, char charReplacement, std::string& inputStr)
{
   // the usual replace function
	std::replace(inputStr.begin(), inputStr.end(), charToReplace, charReplacement);
}

// remove a character or C-array of characters from a string
void ezStr::RemoveChar(std::string& inputStr, char* removeChar_Array)
{
   // iterates over the string's characters
   for (size_t charIndex = 0; charIndex < strlen(removeChar_Array); charIndex++)
   {
      // using the erase-remove idiom, we remove the characters then move onto the next character
      inputStr.erase(remove(inputStr.begin(), inputStr.end(), removeChar_Array[charIndex]), inputStr.end());
   }
}

// remove a string from a string
void ezStr::RemoveChar(std::string& inputStr, std::string removeChar_Str)
{
   // iterates over the string's characters
   for (size_t charIndex = 0; charIndex < removeChar_Str.length(); charIndex++)
   {
      // using the erase-remove idiom, we remove the string from the input string 
      inputStr.erase(remove(inputStr.begin(), inputStr.end(), removeChar_Str[charIndex]), inputStr.end());
   }
}

// remove a vector of characters from a string
void ezStr::RemoveChar(std::string& inputStr, std::vector<char> removeChar_Vec)
{
   // iterates over the string's characters
   for (size_t charIndex = 0; charIndex < removeChar_Vec.size(); charIndex++)
   {
      // using the erase-remove idiom, we remove the characters, then increment the vector
      inputStr.erase(remove(inputStr.begin(), inputStr.end(), removeChar_Vec[charIndex]), inputStr.end());
   }
}

// check to see if two strings are equivalent
bool ezStr::Compare(const std::string& firstString, const std::string& secondString)
{
   // returns either true or false, depending on equivalency
	return firstString == secondString ? true : false;
}

// takes a string and a single-character delimiter, and tokenizing it into a vector
std::vector <std::string> ezStr::ToVector(const std::string& inputStr, const char& delim)
{
	std::vector<std::string> tempVec;
	std::string tempSubStr;

   // iterates over the input string's characters
	for (size_t charIndex = 0; charIndex < inputStr.length(); charIndex++)
	{
      // if the current character is NOT the programmer-defined delimiter, append to our SubString
		if (inputStr[charIndex] != delim)
		{
			tempSubStr += inputStr[charIndex];
		}
      // if the current character IS the programmer-defined delimiter, push_back to our vector
		else if (inputStr[charIndex] == delim)
		{
			tempVec.push_back(tempSubStr);
         // clear the substring so nothing from the previous element is accidentally added
			tempSubStr.clear();
		}
	}

   // push_back residual strings
	tempVec.push_back(tempSubStr);
	return tempVec;
}