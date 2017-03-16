#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "ezstr.h"

const enum SchoolRooms { WizClass, NorthHall, EmptyClass, SouthHall, NurseOff, PrinceOff, Cafeteria, StockRm, Courtyard, DirtRd, Forest, Altar };
const enum enNPCs { npc1, npc2, npc3 };

// a null variable that I'll check for when looking for a direction the player can go in.
const int NULL_VAL = -1;
const int MAX_ROOM_AMT = 12;
const int MAX_MAP_X = 10;
const int MAX_MAP_Y = 10;

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
	item playerInv[10];
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
	bool isLocked = false;
	bool itemPresent = false;
	bool useItem = false;
	bool npcPresent = false;
	item item_IFP;
	NPC npc_IFP;
};

inline bool operator==(const vector2& lhs, const vector2& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
inline bool operator!=(const vector2& lhs, const vector2& rhs) { return !operator==(lhs, rhs); }

// set the rooms
void set_Rooms(room Rooms[MAX_ROOM_AMT]);
// sets the NPCs in the room. didn't want to crowd the room function too much
void set_NPCs(room Rooms[MAX_ROOM_AMT], Player &player);
// determine which room the player is moving too and if it's valid
void moveRoom(std::vector<std::string> &command, room *roomsLst, Player &player, room &currentRoom);
// read in input
void parse(std::string& input, Player &player, room &currentRm, room *Rooms);
// update player's position
void update_playerPos(Player &player, room &currentRoom, room *Rooms);
// talk to an NPC if present
void talkNPC(std::vector<std::string> &commandDir, room &currentLoc);
// pick up an item if available
void takeItem(std::vector<std::string> &commandDir, room &currentLoc, Player &player);
// use item
void useItem(room &currentLoc, room Rooms[MAX_ROOM_AMT], Player &player);
// look around the room
void lookCommand(std::vector<std::string> &commandDir, room &currentLoc, Player &player);