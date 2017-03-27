#include "game_settings.h"
#include "debug.h"

#include <iostream>
#include <codecvt>

/*
	This file is primarily for secondary things that involve windows like the windows size.
*/

short CONSOLE_WIDTH = 0;
short CONSOLE_HEIGHT = 0;
extern short CONSOLE_BUFFER_WIDTH = 0;
extern short CONSOLE_BUFFER_HEIGHT = 0;

char const configFileName[12] = { "config.txt\0" };

inline bool file_exist(const char* filename)
{
   std::ifstream infile(filename);
   return infile.good();
}

inline std::string file_toStr(const char* fileName)
{
   std::ifstream fileStream(fileName);
   std::string fileContents;
   // iterators have to be in parenthesis. It's a c++ compiler parsing problem
   fileContents.assign((std::istreambuf_iterator<char>(fileStream)),
      (std::istreambuf_iterator<char>()));
   return fileContents;
}

inline void make_config()
{
	std::fstream configFileObj;
   std::string fileContent, input;

   if (file_exist(configFileName))
   {
      configFileObj.open(configFileName, std::ios::in);

      if (configFileObj.is_open())
      {
         // puts contents of file into string
         fileContent = file_toStr(configFileName);
         std::vector<std::string> tempVec = ezStr::To_Vector(fileContent, 'x');
         CONSOLE_WIDTH = (INT16)stoi(tempVec[0]);
         CONSOLE_HEIGHT = (INT16)stoi(tempVec[1]);
         CONSOLE_BUFFER_WIDTH = CONSOLE_WIDTH;
         CONSOLE_BUFFER_HEIGHT = (CONSOLE_HEIGHT * 2);
      }
      else
      {
         std::cout << "\n\n***Error***\nConfig file could not be opened.\n***ERROR***\n\n";
      }
   }
   else
   {
      while (true)
      {
         std::cout << "Do you want to adjust the size of the console window? ([Y]es/[N]o) No defaults to"
            " an arbitrary value.\n\nInput:\t";

         std::getline(std::cin, input);
         ezStr::To_Lower(input);
         ezStr::Remove_Char(input, ezStr::NUMBERS_10);
         ezStr::Remove_Char(input, ezStr::PUNCTUATION);
         if (input == "yes" || input == "y")
         {
            std::cout << "\nPut in as \"widthxheight\".\n\nInput:\t";
            input.clear();
            std::getline(std::cin, input);
         }
         else if (input == "no" || input == "n")
         {
            configFileObj.open(configFileName, std::ios::out);

            if (configFileObj.is_open())
            {
               // sets the widthxheight of the window
               configFileObj << "150x300";
               configFileObj.close();
            }
            else if (!configFileObj.is_open())
            {
               std::cout << "\n\n***Error***\nConfig file could not be opened.\n***ERROR***\n\n";
               configFileObj.close();
            }
            else
            {
               std::cout << Generic_Err;
               configFileObj.close();
            }

            CONSOLE_WIDTH = 150;
            CONSOLE_HEIGHT = 300;
            CONSOLE_BUFFER_WIDTH = CONSOLE_WIDTH;
            CONSOLE_BUFFER_HEIGHT = (CONSOLE_HEIGHT * 2);
         }
         else
         {
            std::cout << "\nI couldn't understand that!\n" << std::endl;
            continue;
         }

      }
   }
}

extern inline void set_Settings()
{
	std::wstring dgTitle = L"DEBUG - Text Adventure " + gameVer;
	std::wstring reTitle = L"Text Adventure " + gameVer;
	HANDLE writeHnd;
	HANDLE readHnd;
	LPWSTR DEBUG_Title = const_cast<LPWSTR>(dgTitle.c_str());
	LPWSTR RELEASE_Title = const_cast<LPWSTR>(reTitle.c_str());
	SMALL_RECT windowSize;
	COORD bufferSize;

	DEBUG::wecho(dgTitle);
	DEBUG::wecho(reTitle);

   make_config();

	writeHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	readHnd = GetStdHandle(STD_INPUT_HANDLE);
	windowSize = { 0,0, CONSOLE_WIDTH, CONSOLE_HEIGHT };
	bufferSize = { CONSOLE_BUFFER_WIDTH, CONSOLE_BUFFER_HEIGHT};

	// Change the window's title:
	if (IS_DEBUG == true)
	{
		SetConsoleTitle(DEBUG_Title);
	}
	else
	{
		SetConsoleTitle(RELEASE_Title);
	}

	//  set up the window size automatically
	SetConsoleWindowInfo(writeHnd, 1, &windowSize);

	// change console buffer size
	SetConsoleScreenBufferSize(writeHnd, bufferSize);
}