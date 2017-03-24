#pragma once
#include <Windows.h>
#include <fstream>
#include <wchar.h>
#include <string>
#include <sstream>

inline void set_Settings();
inline void make_config();
inline bool file_exist(const char* filename);
inline std::string file_toStr(const char* fileName);