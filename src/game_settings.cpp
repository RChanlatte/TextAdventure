#include "stdafx.h"
#include "game_settings.h"
#include "debug.h"

#include <iostream>
#include <codecvt>

/*
	This file is primarily for secondary things that involve windows like the windows size.
*/

char const configFileName[12] = { "config.txt\0" };

// TODO: Make it so that you can adjust the size of the console
//		 window inside the config file. Some of the work is done.
void make_config()
{
	std::fstream configFileObj;

	std::cout << "Do you want to adjust the size of the console window? (Yes/No) No defaults to an arbitrary value.";

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
}

void set_Settings()
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

	// checks if config file exists, if it doesn't, make it
	if (!std::ifstream(configFileName))
	{
		make_config();
	}

	writeHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	readHnd = GetStdHandle(STD_INPUT_HANDLE);
	windowSize = { 0,0,150,300 };
	bufferSize = { 150,300 };

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