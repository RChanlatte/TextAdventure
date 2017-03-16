#include "stdafx.h"
#include "game_logic.h"

void update_playerPos(Player &player, room &currentRoom, room *Rooms)
{
	for (int i = 0; i < MAX_ROOM_AMT; i++)
	{
		if (Rooms[i].roomLocation.x == player.characterLocation.x &&
			Rooms[i].roomLocation.y == player.characterLocation.y)
		{
			currentRoom = Rooms[i];
			break;
		}
		else
		{
			currentRoom.roomName = "NULL";
		}
	}
}

/*
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

WizClass, NorthHall, EmptyClass, SouthHall, NurseOff, PrinceOff, Cafeteria, StockRm, Courtyard, DirtRd, Forest, Altar
*/
void set_Rooms(room Rooms[MAX_ROOM_AMT])
{
	Rooms[WizClass].roomLocation.x = 2;
	Rooms[WizClass].roomLocation.y = 8;
	Rooms[WizClass].roomName = "Wizard's Class.";
	Rooms[WizClass].roomLook = "It is the wizard's classroom. N-nothing particularly interesting a-about it. A few students are doing t-trivial work while the other students\nare talking f-foolishness amongst themselves. I bet they're talking about how many c-clothraqs they've smitten. W-who cares about that?";

	Rooms[NorthHall].roomLocation.x = 3;
	Rooms[NorthHall].roomLocation.y = 8;
	Rooms[NorthHall].roomName = "Northern hallway.";
	Rooms[NorthHall].roomLook = "The northern half of a long corridor. School p-posters are p-plastered all along the walls with inspirational messages like: \"Avoid Gorthraks\n like you would deadlines!\"...W-what? nobody listens to those anyway. The occasional classroom breaks up the monotonous and s-stupid motivational\nposters.";

	Rooms[EmptyClass].roomLocation.x = 4;
	Rooms[EmptyClass].roomLocation.y = 8;
	Rooms[EmptyClass].roomName = "Empty Classroom.";
	Rooms[EmptyClass].roomLook = "Empty classroom with desks and school supplies strewn about as if everyone left suddenly.";

	Rooms[SouthHall].roomLocation.x = 3;
	Rooms[SouthHall].roomLocation.y = 7;
	Rooms[SouthHall].roomName = "Southern hallway.";
	Rooms[SouthHall].roomLook = "The southern half of a long corridor. More school p-posters are p-plastered along the school w-walls, in between classroom doors. \"A sword, a\nwand, a bow... All are acceptable ways to dispose of clothraqs!\"...N-no mention of the necronomicon? Of course not, n-nobody cares about Necromancers.";

	Rooms[NurseOff].roomLocation.x = 4;
	Rooms[NurseOff].roomLocation.y = 7;
	Rooms[NurseOff].roomName = "Nurse's Office.";
	Rooms[NurseOff].roomLook = "The nurse's office. Staffed by a Ranger while the white mage is out doing errands. The Ranger is actually quite pleasant, b-but p-probably\nunqualified.";

	Rooms[PrinceOff].roomLocation.x = 5;
	Rooms[PrinceOff].roomLocation.y = 7;
	Rooms[PrinceOff].roomName = "Grand Mage's Office.";
	Rooms[PrinceOff].roomLook = "The office of the Grand Mage. Dean of any and everything. S-stern, uny-yielding, and an a-asshole. Office smells a bit like what I'd\nanticipate colthraq urine to smell like.";

	Rooms[Cafeteria].roomLocation.x = 3;
	Rooms[Cafeteria].roomLocation.y = 6;
	Rooms[Cafeteria].roomName = "Cafeteria.";
	Rooms[Cafeteria].roomLook = "The Cafeteria. M-most noise that can b-be heard is just student c-chatter. Just, t-talking, occasionally uproarous l-laughter, but\nmostly t-talking.";

	Rooms[StockRm].roomLocation.x = 4;
	Rooms[StockRm].roomLocation.y = 6;
	Rooms[StockRm].roomName = "Stockroom.";
	Rooms[StockRm].roomLook = "The Stockroom. Full of supplies a-and alchemical flasks. I-I probably shouldn't t-touch anything.";

	Rooms[Courtyard].roomLocation.x = 3;
	Rooms[Courtyard].roomLocation.y = 5;
	Rooms[Courtyard].roomName = "Courtyard.";
	Rooms[Courtyard].roomLook = "The Courtyard. A large grassy terrace, a-a single dirt road t-that leads to a forest. We're not allowed to go down that r-road.";

	Rooms[DirtRd].roomLocation.x = 4;
	Rooms[DirtRd].roomLocation.y = 5;
	Rooms[DirtRd].roomName = "Dirt Road.";
	Rooms[DirtRd].roomLook = "A dirt road. It is littered with overgrowth, d-doesn't look like it has been w-walked on frequently in m-many\nyears. N-nothing but forest\nhere on o-out.";

	Rooms[Forest].roomLocation.x = 5;
	Rooms[Forest].roomLocation.y = 5;
	Rooms[Forest].roomName = "Forest.";
	Rooms[Forest].roomLook = "A forest. This f-forest is actually q-quite terrifying. It's dark, cold, green, and I can't see past all the\ntrees. I d-don't know if I should go that f-far.";

	Rooms[Altar].roomLocation.x = 5;
	Rooms[Altar].roomLocation.y = 4;
	Rooms[Altar].roomName = "Altar.";
	Rooms[Altar].roomLook = "An altar in the middle of a clearing. I d-don't know where I am, it is dead s-silent and there is a delapidated\na-altar surrounded by nothing but d-dirt... It l-looks like there is b-blood on the altar.";
}

// TODO: flesh out npc dialogue
void set_NPCs(room Rooms[MAX_ROOM_AMT], Player &player)
{
	
}

void lookCommand(std::vector<std::string> &commandDir, room &currentLoc, Player &player) 
{
	if (commandDir[1] == "AREA")
	{
		std::cout << currentLoc.roomLook;
	}
	else if (commandDir[1] == "ITEM")
	{
		if (currentLoc.itemPresent == true)
		{
			std::cout << currentLoc.itemLook;
		}
		else
		{
			std::cout << "\"There doesn't seem to be anything interesting here.\"";
		}
	}
	else if (commandDir[1] == "INVENTORY")
	{
		std::cout << "\"I've got: ";
		for (int i = 0; i < 10; ++i)
		{
			std::cout << player.playerInv[i].itemName;
			if (i != 9)
			{
				std::cout << ", ";
			}
			else
			{
				std::cout << ".\"";
			}
		}
	}
	else if (commandDir[1] == "NPC")
	{
		if (currentLoc.npcPresent == true)
		{
			if (currentLoc.npc_IFP.hasMet == false)
			{
				std::cout << currentLoc.npc_IFP.npcLook_unMet;
			}
			else
			{
				std::cout << currentLoc.npc_IFP.npcLook_met;
			}
		}
		else
		{
			std::cout << "\"There isn't any one here.\"";
		}

	}
}

// TODO: currently you can move from the stock room to the forest and vice/versa, change the function so that this doesn't happen.
void moveRoom(std::vector<std::string> &commandDir, room *roomsLst, Player &player, room &currentLoc)
{
	int tempVal_x = player.characterLocation.x;
	int tempVal_y = player.characterLocation.y;

	if (commandDir[1] == "EAST")
	{
		// TODO: turn this for-loop and accompanying if-statement into a function
		//		 use a function pointer to easily switch between x and y values
		//		 Should only be two functions, add a parameter for neg/pos directions
		for (int i = 0; i < MAX_ROOM_AMT; i++)
		{
			if (roomsLst[i].roomLocation.x == tempVal_x + 1 && roomsLst[i].roomLocation.y == player.characterLocation.y && roomsLst[i].isLocked == false)
			{
				++player.characterLocation.x;
				std::cout << "\"I'm now in the " << roomsLst[i].roomName << ".\"";
				break;
			}
			else if (roomsLst[i].roomLocation.x == tempVal_x + 1 && roomsLst[i].isLocked == true)
			{
				std::cout << "\"It's locked.";
				break;
			}
		}
		if (player.characterLocation.x == tempVal_x)
		{
			std::cout << "\"I can't move east.\"\n";
		}
	}
	else if (commandDir[1] == "WEST")
	{
		for (int i = 0; i < MAX_ROOM_AMT; i++)
		{
			if (roomsLst[i].roomLocation.x == tempVal_x - 1 && roomsLst[i].roomLocation.y == player.characterLocation.y && roomsLst[i].isLocked == false)
			{
				--player.characterLocation.x;
				std::cout << "\"I'm now in the " << roomsLst[i].roomName << ".\"";
				break;
			}
			else if (roomsLst[i].roomLocation.x == tempVal_x - 1 && roomsLst[i].isLocked == true)
			{
				std::cout << "\"It's locked.\" ";
				break;
			}
		}
		if (player.characterLocation.x == tempVal_x)
		{
			std::cout << "\"I can't move west.\"\n";
		}
	}
	if (commandDir[1] == "NORTH")
	{
		for (int i = 0; i < MAX_ROOM_AMT; i++)
		{
			if (roomsLst[i].roomLocation.y == tempVal_y + 1 && roomsLst[i].roomLocation.x == player.characterLocation.x && roomsLst[i].isLocked == false)
			{
				++player.characterLocation.y;
				std::cout << "\"I'm now in the " << roomsLst[i].roomName << ".\"";
				break;
			}
		}
		if (player.characterLocation.y == tempVal_y)
		{
			std::cout << "\"I can't move north.\"\n";
		}
	}
	if (commandDir[1] == "SOUTH")
	{
		for (int i = 0; i < MAX_ROOM_AMT; i++)
		{
			if (roomsLst[i].roomLocation.y == tempVal_y - 1 && roomsLst[i].roomLocation.x == player.characterLocation.x && roomsLst[i].isLocked == false)
			{
				--player.characterLocation.y;
				std::cout << "\"I'm now in the " << roomsLst[i].roomName << ".\"";
				break;
			}
		}
		if (player.characterLocation.y == tempVal_y)
		{
			std::cout << "\"I can't move south.\"\n";
		}
	}

	// updates player position to new position
	update_playerPos(player, currentLoc, roomsLst);
}

void talkNPC(std::vector<std::string> &commandDir, room &currentLoc)
{
	if (commandDir[1] == "NPC" || commandDir[1] == currentLoc.npc_IFP.characterName)
	{
		if (currentLoc.npc_IFP.hasMet == false)
		{
			std::cout << currentLoc.npc_IFP.talk_unMet;
			currentLoc.npc_IFP.hasMet = true;
		}
		else
		{
			std::cout << currentLoc.npc_IFP.talk_Met;
		}
	}
}

void takeItem(std::vector<std::string> &commandDir, room &currentLoc, Player &player)
{
	if (currentLoc.itemPresent == true)
	{
		for (int i = 0; player.playerInv[i].itemName == "[SLOT]"; i++)
		{
			player.playerInv[i] = currentLoc.item_IFP;
			std::cout << "\"I picked up " << currentLoc.item_IFP.itemName << ".\"";
			currentLoc.itemPresent = false;
			break;
		}
	}
	else
	{
		std::cout << "\"There is nothing to take.\"";
	}
}

void useItem(room &currentLoc, room *Rooms, Player &player)
{
	if (currentLoc.useItem == true)
	{
		for (int i = 0; i < MAX_ROOM_AMT; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int k = -1; k < 2; k++)
				{
					if (Rooms[i].roomLocation.x == currentLoc.roomLocation.x + k && Rooms[i].isLocked == true
						&& player.playerInv[j].usedOn == Rooms[i].roomName)
					{
						std::cout << "\"I used the item and opened the " << Rooms[i].roomName << ".\"";
						Rooms[i].isLocked = false;
					}
					else if (Rooms[i].roomLocation == currentLoc.roomLocation)
					{
						continue;
					}
					else if (Rooms[i].roomLocation.y == currentLoc.roomLocation.y + k && Rooms[i].isLocked == true)
					{
						std::cout << "\"I used the item and opened the " << Rooms[i].roomName << ".\"";
						Rooms[i].isLocked = false;
					}
				}
				break;
			}
		}
	}
}

void parse(std::string &input, Player &player, room &currentRm, room *Rooms)
{
	std::vector<std::string> commandVec;
	char const space = ' ';
	char illegalChars[] = "0123456789`~!@#$%^&*()-_=+[]{}|;\'\",.<>?/";

	// remove illegal characters from the input string
	ezStr::strCharRmv(input, illegalChars);
	// capitalizes the string's characters to make manipulation easier 
	ezStr::strToUpper(input);
	// puts the individual words delimited by a space into a vector for easier manipulation
	commandVec = ezStr::strDelim(input, space);

	if (commandVec.size() > 0 && commandVec.size() < 3)
	{
		if (commandVec[0] == "EXIT")
		{
			exit(0);
		}
		else if (commandVec[0] == "CLEAR")
		{
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
		}
		// flesh this out -> maybe use a function pointer.
		else if (commandVec[0] == "MOVE")
		{
			moveRoom(commandVec, Rooms, player, currentRm);
		}
		else if (commandVec[0] == "LOOK")
		{
			lookCommand(commandVec, currentRm, player);
		}
		else if (commandVec[0] == "TAKE")
		{
			takeItem(commandVec, currentRm, player);
		}
		else if (commandVec[0] == "USE")
		{
			useItem(currentRm, Rooms, player);
		}
		else if (commandVec[0] == "TALK")
		{
			talkNPC(commandVec, currentRm);
		}
		else
		{
			std::cout << "I don't understand, try again.\n";
		}
	}
	else
	{
		std::cout << "Too many words!\n" << std::endl;
	}

}