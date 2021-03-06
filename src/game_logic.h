#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "debug.h"
#include "ezstr.hpp"
#include "game_settings.h"

extern int GAME_STATE;
extern bool NUM_PUZZ_CMPT;
extern bool HANG_PUZZ_CMPT;

const enum eMovement {NORTH, SOUTH, EAST, WEST};
const enum eSchoolRooms {WizClass, NorthHall, EmptyClass, SouthHall, NurseOff, PrinceOff, Commons, Courtyard, PortalCrss, Pond1, Punisher, Pond2};
const enum eGAME_STATES {FREE_ROAM, PUZZLE};
const enum eNPCs {TicTac, Executioner};
const enum story_Milestones {INTRO, BULLY_PUZZLE, PUNISH, EXE_HANGMAN, REDEMPTION, BULLY_END, END_GAME};

const int MAX_MOVE_AMT = 4;
const int MAX_ROOM_AMT = 12;
const int MAX_MAP_X = 10;
const int MAX_MAP_Y = 10;
const int MAX_INV_AMT = 2;
const int GAME_STATE_AMT = 3;
const int NULL_VAL = -1;

// making a baby grid system
struct vector2
{
	int x;
	int y;
};

struct item
{
	std::string itemName = "[SLOT]";
	std::string itemExamine = "Empty spot in bag.";
	bool canUse = true;
	std::string usedOn;
};

struct CharacterBase
{
	vector2 characterLocation;
	std::string characterName;
};

struct Player : CharacterBase
{
	item playerInv[MAX_INV_AMT];
};

struct NPC : CharacterBase
{
	std::string npcLook_unMet;
	std::string npcLook_met;
	std::string talk_unMet;
	std::string talk_Met;
	bool hasMet = false;
};

struct room
{
	vector2 roomLocation;
	std::string roomName;
	std::string roomLook;
	std::string itemLook;
   int canMove[MAX_MOVE_AMT] = {NORTH, SOUTH, EAST, WEST};
	bool isLocked = false;
	bool itemPresent = false;
	bool useItem = false;
	bool npcPresent = false;
	item item_IFP;
	NPC npc_IFP;
};

inline bool operator==(const vector2& lhs, const vector2& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
inline bool operator!=(const vector2& lhs, const vector2& rhs) { return !operator==(lhs, rhs); }

// set the game state functions
void FREE_ROAM_STATE(bool isDEBUG = false);
void PUZZLE_STATE(bool isDEBUG = false);
void puzzle_NUM();
void puzzle_HANG();

// set the rooms
void set_Rooms(room Rooms[MAX_ROOM_AMT]);
// determine which room the player is moving too and if it's valid
void moveCommand(std::vector<std::string> &command, room *roomsLst, Player &player, room &currentRoom);
// read in input
void parse(std::string& input, Player &player, room &currentRm, room *Rooms);
// update player's position
void update_playerPos(vector2 &playerLoc, room &currentRoom, room *Rooms);
void moveOutput(room& room, bool canMove, bool isLocked);
// talk to an NPC if present
void talkCommand(std::vector<std::string> &commandDir, room &currentLoc);
// pick up an item if available
void takeCommand(std::vector<std::string> &commandDir, room &currentLoc, Player &player);
// use item
void useCommand(room &currentLoc, room *Rooms, Player &player);
// look around the room
void lookCommand(std::vector<std::string> &commandDir, room &currentLoc, Player &player);
// give player item
void giveItem(item& itemToGive, Player& player);

// story-based functions
void expo_story(int milestone);