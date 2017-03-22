#include "game_logic.h"

/* TODO: Create a function in ezSTR that takes a string and an integer value for the buffer of a
         console window so it can input newlines dynamically. */

bool NUM_PUZZ_CMPT = false;
bool HANG_PUZZ_CMPT = false;

void update_playerPos(vector2 &playerLoc, room &currentRoom, room *Rooms)
{
	for (int i = 0; i < MAX_ROOM_AMT; i++)
	{
		if (Rooms[i].roomLocation.x == playerLoc.x &&
			Rooms[i].roomLocation.y == playerLoc.y)
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

void moveOutput(room& room, bool canMove, bool isLocked)
{
   if(canMove && (!isLocked))
   {
      std::cout << "\"I'm now in the " << room.roomName << "\"";
   }
   else if(isLocked && (!canMove))
   {
      std::cout << "\"The " << room.roomName << " is locked...\" ";
   }
   else
   {
      std::cout << "\"I can\'t move that way.\"";
   }
}

void set_items(room* roomList, item* itemList)
{
   item summonAm;
   summonAm.itemName = "Summoning Amulet";
   summonAm.itemExamine = "Summons skeletons; but, they're... not cooperative.\n";
   summonAm.canUse = false;
   summonAm.usedOn = "Nothing.";

   item key;
   key.itemName = "Empty Classroom Key";
   key.itemExamine = "I was told to use this on the empty classroom near the Wizard's Class.\n";
   key.canUse = true;
   key.usedOn = roomList[EmptyClass].roomName;

   itemList[0] = summonAm;
   itemList[1] = key;
}

void giveItem(item& itemToGive, Player& player)
{
   for (int i = 0; i < 2; i++)
   {
      if (player.playerInv[i].itemName == "[SLOT]")
      {
         player.playerInv[i] = itemToGive;
         break;
      }
      else
      {
         std::cout << "Inventory is too small.\n" << std::endl;
      }
      
   }
}

void expo_intro()
{
   std::cout << "\nDaydreaming you wake up, the teacher, a Wizard, kicks you out of the classroom"
      << "\nover your apathy towards your studies. Go to the principal's office.\n\n" << std::endl;
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

int canMove[MAX_MOVE_AMT] = {NORTH, SOUTH, EAST, WEST};

WizClass, NorthHall, EmptyClass, SouthHall, NurseOff, PrinceOff, Cafeteria, StockRm, Courtyard, DirtRd, Forest, Altar
*/
void set_Rooms(room Rooms[MAX_ROOM_AMT])
{
	Rooms[WizClass].roomLocation.x = 1;
	Rooms[WizClass].roomLocation.y = 8;
	Rooms[WizClass].roomName = "Wizard's Class.";
	Rooms[WizClass].roomLook = "It is the wizard's classroom.";
   Rooms[WizClass].canMove[NORTH] = NULL_VAL;
   Rooms[WizClass].canMove[SOUTH] = NULL_VAL;
   Rooms[WizClass].canMove[EAST] = 1;
   Rooms[WizClass].canMove[WEST] = NULL_VAL;

	Rooms[NorthHall].roomLocation.x = 2;
	Rooms[NorthHall].roomLocation.y = 8;
	Rooms[NorthHall].roomName = "Northern hallway.";
	Rooms[NorthHall].roomLook = "The northern half of a long corridor.";
   Rooms[NorthHall].canMove[NORTH] = NULL_VAL;
   Rooms[NorthHall].canMove[SOUTH] = 1;
   Rooms[NorthHall].canMove[EAST] = 1;
   Rooms[NorthHall].canMove[WEST] = 1;
   Rooms[NorthHall].useItem = true;

	Rooms[EmptyClass].roomLocation.x = 3;
	Rooms[EmptyClass].roomLocation.y = 8;
	Rooms[EmptyClass].roomName = "Empty Classroom.";
	Rooms[EmptyClass].roomLook = "Empty classroom with desks and school supplies strewn about as if everyone left suddenly.";
   Rooms[EmptyClass].canMove[NORTH] = NULL_VAL;
   Rooms[EmptyClass].canMove[SOUTH] = NULL_VAL;
   Rooms[EmptyClass].canMove[EAST] = NULL_VAL;
   Rooms[EmptyClass].canMove[WEST] = 1;
   Rooms[EmptyClass].isLocked = true;

	Rooms[SouthHall].roomLocation.x = 2;
	Rooms[SouthHall].roomLocation.y = 7;
	Rooms[SouthHall].roomName = "Southern hallway.";
	Rooms[SouthHall].roomLook = "The southern half of a long corridor.";
   Rooms[SouthHall].canMove[NORTH] = 1;
   Rooms[SouthHall].canMove[SOUTH] = 1;
   Rooms[SouthHall].canMove[EAST] = 1;
   Rooms[SouthHall].canMove[WEST] = NULL_VAL;

	Rooms[PrinceOff].roomLocation.x = 1;
	Rooms[PrinceOff].roomLocation.y = 6;
	Rooms[PrinceOff].roomName = "Grand Mage's Office.";
	Rooms[PrinceOff].roomLook = "The office of the Grand Mage.";
   Rooms[PrinceOff].canMove[NORTH] = NULL_VAL;
   Rooms[PrinceOff].canMove[SOUTH] = NULL_VAL;
   Rooms[PrinceOff].canMove[EAST] = NULL_VAL;
   Rooms[PrinceOff].canMove[WEST] = 1;

	Rooms[Commons].roomLocation.x = 2;
	Rooms[Commons].roomLocation.y = 6;
	Rooms[Commons].roomName = "Commons.";
	Rooms[Commons].roomLook = "The Commons.";
   Rooms[Commons].canMove[NORTH] = 1;
   Rooms[Commons].canMove[SOUTH] = 1;
   Rooms[Commons].canMove[EAST] = 1;
   Rooms[Commons].canMove[WEST] = NULL_VAL;

   Rooms[NurseOff].roomLocation.x = 3;
   Rooms[NurseOff].roomLocation.y = 6;
   Rooms[NurseOff].roomName = "Nurse's Office.";
   Rooms[NurseOff].roomLook = "The nurse's office.";
   Rooms[NurseOff].canMove[NORTH] = NULL_VAL;
   Rooms[NurseOff].canMove[SOUTH] = NULL_VAL;
   Rooms[NurseOff].canMove[EAST] = 1;
   Rooms[NurseOff].canMove[WEST] = 1;

	Rooms[Courtyard].roomLocation.x = 2;
	Rooms[Courtyard].roomLocation.y = 5;
	Rooms[Courtyard].roomName = "Courtyard.";
	Rooms[Courtyard].roomLook = "The School Courtyard.";
   Rooms[Courtyard].canMove[NORTH] = 1;
   Rooms[Courtyard].canMove[SOUTH] = NULL_VAL;
   Rooms[Courtyard].canMove[EAST] = 1;
   Rooms[Courtyard].canMove[WEST] = NULL_VAL;

   Rooms[PortalCrss].roomLocation.x = 2;
   Rooms[PortalCrss].roomLocation.y = 4;
   Rooms[PortalCrss].roomName = "Portal Crossing.";
   Rooms[PortalCrss].roomLook = "This is where the students come and go.";
   Rooms[PortalCrss].canMove[NORTH] = NULL_VAL;
   Rooms[PortalCrss].canMove[SOUTH] = NULL_VAL;
   Rooms[PortalCrss].canMove[EAST] = NULL_VAL;
   Rooms[PortalCrss].canMove[WEST] = NULL_VAL;
   
   Rooms[Pond1].roomLocation.x = 5;
   Rooms[Pond1].roomLocation.y = 8;
   Rooms[Pond1].roomName = "Pond Dimension.";
   Rooms[Pond1].roomLook = "A dimension to think about what you did, I guess.";
   Rooms[Pond1].canMove[NORTH] = NULL_VAL;
   Rooms[Pond1].canMove[SOUTH] = 1;
   Rooms[Pond1].canMove[EAST] = NULL_VAL;
   Rooms[Pond1].canMove[WEST] = NULL_VAL;

   Rooms[Punisher].roomLocation.x = 5;
   Rooms[Punisher].roomLocation.y = 7;
   Rooms[Punisher].roomName = "Punisher's Enclave.";
   Rooms[Punisher].roomLook = "A small cave where it smells like cheese.";
   Rooms[Punisher].canMove[NORTH] = 1;
   Rooms[Punisher].canMove[SOUTH] = 1;
   Rooms[Punisher].canMove[EAST] = NULL_VAL;
   Rooms[Punisher].canMove[WEST] = NULL_VAL;

   Rooms[Pond2].roomLocation.x = 5;
   Rooms[Pond2].roomLocation.y = 6;
   Rooms[Pond2].roomName = "Pond Dimesion.";
   Rooms[Pond2].roomLook = "A dimension to think about what you did, I guess.";
   Rooms[Pond2].canMove[NORTH] = 1;
   Rooms[Pond2].canMove[SOUTH] = 1;
   Rooms[Pond2].canMove[EAST] = NULL_VAL;
   Rooms[Pond2].canMove[WEST] = NULL_VAL;
}

void moveCommand(std::vector<std::string> &commandDir, room *roomsLst, Player &player, room &currentLoc)
{
   vector2 newMove = player.characterLocation;
   room prevRm = currentLoc;
   bool noRm_F = false;

   if (commandDir[1] == "STATE")
   {
      if (GAME_STATE == FREE_ROAM)
      {
         GAME_STATE = COMBAT;
         std::cout << "\n\nGAME_STATE IS NOW " << "COMBAT" << "\n\n" << std::endl;
      }
      else if (GAME_STATE == COMBAT)
      {
         (GAME_STATE == PUZZLE);
         std::cout << "\n\nGAME_STATE IS NOW " << "PUZZLE" << "\n\n" << std::endl;
      }
      else if(GAME_STATE == PUZZLE)
      {
         GAME_STATE = FREE_ROAM;
         std::cout << "\n\nGAME_STATE IS NOW " << "FREE_ROAM" << "\n\n" << std::endl;
      }
   }

   if (commandDir[1] == "EAST")
   {
      newMove.x++;

      if(!noRm_F)
      {
         // consider turning this for-loop into a function
         for (int i = 0; i < MAX_ROOM_AMT; i++)
         {
            if (roomsLst[i].roomLocation == newMove)
            {
               if(currentLoc.canMove[EAST] != NULL_VAL && roomsLst[i].isLocked == false)
               {
                  player.characterLocation.x = newMove.x;
                  update_playerPos(player.characterLocation, currentLoc, roomsLst);
                  moveOutput(roomsLst[i], true, false);
                  break;
               }
               else if(roomsLst[i].isLocked == true)
               {
                  moveOutput(roomsLst[i], false, true);
                  break;
               }
               else if (currentLoc.canMove[EAST] == NULL_VAL)
               {
                  noRm_F = true;
                  break;
               }
            }
         }
         if(player.characterLocation == prevRm.roomLocation)
         {
            noRm_F = true;
         }
      }
   }
   else if (commandDir[1] == "WEST")
   {
      newMove.x--;

      if(!noRm_F)
      {
         for (int i = 0; i < MAX_ROOM_AMT; i++)
         {
            if (roomsLst[i].roomLocation == newMove)
            {
               if (currentLoc.canMove[WEST] != NULL_VAL && roomsLst[i].isLocked == false)
               {
                  player.characterLocation.x = newMove.x;
                  update_playerPos(player.characterLocation, currentLoc, roomsLst);
                  moveOutput(roomsLst[i], true, false);
                  break;
               }
               else if (roomsLst[i].isLocked == true)
               {
                  moveOutput(roomsLst[i], false, true);
                  break;
               }
               else if (currentLoc.canMove[WEST] == NULL_VAL)
               {
                  noRm_F = true;
                  break;
               }
            }
         }
         if (player.characterLocation == prevRm.roomLocation)
         {
            noRm_F = true;
         }
      }
   }
   else if (commandDir[1] == "NORTH")
   {
      newMove.y++;

      if(!noRm_F)
      {
         for (int i = 0; i < MAX_ROOM_AMT; i++)
         {
            if (roomsLst[i].roomLocation == newMove)
            {
               if (currentLoc.canMove[NORTH] != NULL_VAL && roomsLst[i].isLocked == false)
               {
                  player.characterLocation.y = newMove.y;
                  update_playerPos(player.characterLocation, currentLoc, roomsLst);
                  moveOutput(roomsLst[i], true, false);
                  break;
               }
               else if (roomsLst[i].isLocked == true)
               {
                  moveOutput(roomsLst[i], false, true);
                  break;
               }
               else if (currentLoc.canMove[NORTH] == NULL_VAL)
               {
                  noRm_F = true;
                  break;
               }
            }
         }
      }
      if (player.characterLocation == prevRm.roomLocation)
      {
         noRm_F = true;
      }
   }
   else if (commandDir[1] == "SOUTH")
   {
      newMove.y--;

      if(!noRm_F)
      {
         for (int i = 0; i < MAX_ROOM_AMT; i++)
         {
            if (roomsLst[i].roomLocation == newMove)
            {
               if (currentLoc.canMove[SOUTH] != NULL_VAL && roomsLst[i].isLocked == false)
               {
                  player.characterLocation.y = newMove.y;
                  update_playerPos(player.characterLocation, currentLoc, roomsLst);
                  moveOutput(roomsLst[i], true, false);
                  break;
               }
               else if (roomsLst[i].isLocked == true)
               {
                  moveOutput(roomsLst[i], false, true);
                  break;
               }
               else if (currentLoc.canMove[SOUTH] == NULL_VAL)
               {
                  noRm_F = true;
                  break;
               }
            }
         }
      }
      if (player.characterLocation == prevRm.roomLocation)
      {
         noRm_F = true;
      }
   }
   if (noRm_F)
   {
      moveOutput(currentLoc, false, false);
   }
}

void lookCommand(std::vector<std::string> &commandDir, room &currentLoc, Player &player) 
{
	if (commandDir[1] == "ROOM")
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
		for (int i = 0; i < MAX_INV_AMT; ++i)
		{
			std::cout << player.playerInv[i].itemName;
			if (i != 1)
			{
				std::cout << ", ";
			}
			else
			{
				std::cout << ".\"";
			}
		}
	}
   else if (commandDir[1] == "AMULET")
   {
      std::cout << player.playerInv[0].itemExamine << std::endl;
   }
   else if (commandDir[1] == "KEY")
   {
      std::cout << player.playerInv[1].itemExamine << std::endl;
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

void talkCommand(std::vector<std::string> &commandDir, room &currentLoc)
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

void takeCommand(std::vector<std::string> &commandDir, room &currentLoc, Player &player)
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

void useCommand(room &currentLoc, room *Rooms, Player &player)
{
	if (currentLoc.useItem == true)
	{
		for (int i = 0; i < MAX_ROOM_AMT; i++)
		{
			for (int j = 0; j < MAX_INV_AMT; j++)
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
	char illegalChars[41] = "0123456789`~!@#$%^&*()-_=+[]{}|;\'\",.<>?/";

	ezStr::RemoveChar(input, illegalChars);
	ezStr::ToUpper(input);
	commandVec = ezStr::ToVector(input);

	if (commandVec.size() > 0 && commandVec.size() < 3)
	{
		if (commandVec[0] == "EXIT")
		{
			exit(0);
		}
		else if (commandVec[0] == "CLEAR")
		{
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
		}
		else if (commandVec[0] == "MOVE")
		{
			moveCommand(commandVec, Rooms, player, currentRm);
		}
		else if (commandVec[0] == "LOOK")
		{
			lookCommand(commandVec, currentRm, player);
		}
		else if (commandVec[0] == "TAKE")
		{
			takeCommand(commandVec, currentRm, player);
		}
		else if (commandVec[0] == "USE")
		{
			useCommand(currentRm, Rooms, player);
		}
		else if (commandVec[0] == "TALK")
		{
			talkCommand(commandVec, currentRm);
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

void puzzle_NUM()
{
   int numAns = 14;
   int response;

   std::cout << "Asgoth: \"Alright! The objective is to guess the number! My superior 14 year-old "
               << "intellect, makes you no match! HA! You'll have THREE TRIES, before this cool "
               << "teen beats it outta yeah! ";

   for (int i = 0; i < 3; i++)
   {
      if (i == 0)
      {
         std::cout << "Nya-ha! First try! Let's see if you can outsmart this 14 years young "
                  << "barbarian master! Haha!\"\n" << std::endl;
         std::cout << "\nYour guess:\t";
         std::cin >> response;
      }
      else if (i == 1 && response != numAns)
      {
         std::cout << "Asgoth: \"Ha-ha! Second try! Am I getting in your head bro?! You need to brush "
                  << "up on your guessing skills! I knew your primitive baby mind couldn't match my "
                  << "own!\"\n" << std::endl;
         std::cout << "\nYour guess:\t";
         std::cin >> response;
      }
      else if (i == 2 && response != numAns)
      {
         std::cout << "Asgoth: \"Ho-ho! Third try! This is pathetic! Why don't you summon some skeletons "
            << "to help you out?! Ahaha! You need to git gud in order to face THIS bombacious teen!\""
            << "\n" << std::endl;
         std::cout << "\nYour guess:\t";
         std::cin >> response;
      }
      if (response == numAns)
      {
         switch (i)
         {
         case 0:
            i = 2;
            std::cout << "Asgoth: \"W-what?! H-how...?! CHEATER! There is no way! Prepare to feel the "
                  << "wrath of this teenage fury!!!\"\n" << std::endl;
            NUM_PUZZ_CMPT = true;
            break;
         case 1:
            i = 2;
            std::cout << "Asgoth: \"N-No way! What in the...?! FRAUD! You must've cheated! Prepare "
                  << "yourself necromancer!\"\n" << std::endl;
            NUM_PUZZ_CMPT = true;
            break;
         case 2:
            std::cout << "Asgoth: \"You almost l-lost...?! No... This isn't possible! You had to have "
                  << " cheated! I will not allow this! Fight!\"\n" << std::endl;
            NUM_PUZZ_CMPT = true;
            break;
         default:
            std::cout << "Asgoth: \"Ha-ha! Of course you couldn't succeed! Your tiny, necromancer mind "
                  << "just couldn't grasp such a simple game! Now, get read for the beat-down, necro!\"\n" << std::endl;
            NUM_PUZZ_CMPT = true;
            break;
         }
      }
   }
   GAME_STATE = COMBAT;
}

void update_gameBoard(int& tries)
{
   // roof of gallows
   for (int i = 0; i < 9; i++)
   {
      std::cout << "#";
   }

   switch (tries)
   {
   case 0:
      for (int i = 0; i < 8; i++)
      {
         if (i == 0)
         {
            std::cout << "\n@\t|";
         }
         else if (i == 1)
         {
            std::cout << "\n@\tO";
         }
         else if (i == 2)
         {
            std::cout << "\n@      /|\\";
         }
         else if (i == 3)
         {
            std::cout << "\n@\t|";
         }
         else if (i == 4)
         {
            std::cout << "\n@\t^";
         }
         else if (i >= 5 && i < 7)
         {

            std::cout << "\n@";
         }
         else
         {
            std::cout << "\n@\n";
         }
      }
      break;
   case 1:
      for (int i = 0; i < 8; i++)
      {
         if (i == 0)
         {
            std::cout << "\n@\t|";
         }
         else if (i == 1)
         {
            std::cout << "\n@\tO";
         }
         else if (i == 2)
         {
            std::cout << "\n@      /|\\";
         }
         else if (i == 3)
         {
            std::cout << "\n@\t|";
         }
         else if (i >= 4 && i < 7)
         {

            std::cout << "\n@";
         }
         else
         {
            std::cout << "\n@\n";
         }
      }
      break;
   case 2:
      for (int i = 0; i < 8; i++)
      {
         if (i == 0)
         {
            std::cout << "\n@\t|";
         }
         else if (i == 1)
         {
            std::cout << "\n@\tO";
         }
         else if (i == 2)
         {
            std::cout << "\n@      /|";
         }
         else if (i == 3)
         {
            std::cout << "\n@\t|";
         }
         else if (i >= 4 && i < 7)
         {

            std::cout << "\n@";
         }
         else
         {
            std::cout << "\n@\n";
         }
      }
      break;
   case 3:
      for (int i = 0; i < 8; i++)
      {
         if (i == 0)
         {
            std::cout << "\n@\t|";
         }
         else if (i == 1)
         {
            std::cout << "\n@\tO";
         }
         else if (i == 2)
         {
            std::cout << "\n@\t|";
         }
         else if (i == 3)
         {
            std::cout << "\n@\t|";
         }
         else if (i >= 4 && i < 7)
         {

            std::cout << "\n@";
         }
         else
         {
            std::cout << "\n@\n";
         }
      }
      break;
   case 4:
      for (int i = 0; i < 8; i++)
      {
         if (i == 0)
         {
            std::cout << "\n@\t|";
         }
         else if (i == 1)
         {
            std::cout << "\n@\tO";
         }
         else if (i == 2)
         {
            std::cout << "\n@\t|";
         }
         else if (i >= 3 && i < 7)
         {

            std::cout << "\n@";
         }
         else
         {
            std::cout << "\n@\n";
         }
      }
      break;
   case 5:
      for (int i = 0; i < 8; i++)
      {
         if (i == 0)
         {
            std::cout << "\n@\t|";
         }
         else if (i == 1)
         {
            std::cout << "\n@\tO";
         }
         else if (i >= 2 && i < 7)
         {

            std::cout << "\n@";
         }
         else
         {
            std::cout << "\n@\n";
         }
      }
      break;
   default:
      for (int i = 0; i < 8; i++)
      {
         if (i == 0)
         {
            std::cout << "\n@\t|";
         }
         else if (i <= 6)
         {

            std::cout << "\n@";
         }
         else
         {
            std::cout << "\n@\n";
         }
      }
      break;
   }

   // floor of gallows
   for (int i = 0; i < 15; i++)
   {
      std::cout << "#";
   }

   std::cout << "\n" << std::endl;
}

void puzzle_HANG()
{
   std::string inputStr, bufferStr;
   std::string word_to_guess = "TEST STRING";
   bufferStr = word_to_guess;
   int TRIES = 6;
   bool GAME_WON = false;

   // initializes the buffer string
   for (size_t i = 0; i < word_to_guess.length(); i++)
   {
      if (bufferStr[i] != ' ')
      {
         bufferStr[i] = '-';
         continue;
      }
      else
      {
         bufferStr[i] = ' ';
         continue;
      }
   }

   while (TRIES > 0)
   {
      size_t count = 0;
      bool notFound = true;

      // initialize execuitioner's gallows
      update_gameBoard(TRIES);

      // displays the buffer string each iteration and checks if it is completely dashes
      for (size_t i = 0; i < word_to_guess.length(); i++)
      {
         std::cout << bufferStr[i];

         if (bufferStr[i] != '-')
         {
            count++;
            continue;
         }
         else if (count >= (word_to_guess.length() - 1))
         {
            GAME_WON = true;
         }
      }

      // accepts input
      std::cout << "\n\nInput a letter before you hang the man!\n\nYou currently have " << TRIES << " tries left.\n\n" << "Letter: ";
      std::cin >> inputStr;
      ezStr::ToUpper(inputStr);

      // checks against the word to guess and edits the buffer accordingly
      for (size_t i = 0; i < word_to_guess.length(); i++)
      {
         if (inputStr[0] == word_to_guess[i])
         {
            bufferStr[i] = inputStr[0];
            notFound = false;
            continue;
         }
      }
      if (notFound)
      {
         std::cout << "\n\nUh-oh! Looks like you missed a letter!\n" << std::endl;
         --TRIES;
      }
      else if (GAME_WON)
      {
         break;
      }
   }

   if (GAME_WON)
   {
      update_gameBoard(TRIES);
      std::cout << "\nTHE ANSWER WAS:\t" << bufferStr;
      std::cout << "\n$$$$$YOU WON!!!$$$$$\n\n";
   }
   else
   {
      update_gameBoard(TRIES);
      std::cout << "\nTHE ANSWER WAS:\t" << bufferStr;
      std::cout << "\n######YOU LOST!!!#####\n\n";
   }

   system("PAUSE");
}

void PUZZLE_STATE(bool isDEBUG)
{
   std::string input;
   std::vector<std::string> commands;

   if (IS_DEBUG)
   {
      std::cout << "#####\n\nPUZZLE STATE\n\n#####\n" << std::endl;

      std::getline(std::cin, input);
      ezStr::ToLower(input);
      commands = ezStr::ToVector(input);

      if (commands[0] == "move" && commands[1] == "state")
      {
         GAME_STATE = FREE_ROAM;
      }
      else if (commands[0] == "start" && commands[1] == "guess")
      {
         puzzle_NUM();
      }
      else if (commands[0] == "start" && commands[1] == "hang")
      {
         puzzle_HANG();
      }
   }
   else
   {

   }
   
                        
}

void COMBAT_STATE(bool isDEBUG)
{
   std::string input;
   std::vector<std::string> commands;

   std::cout << "#####\n\nCOMBAT STATE\n\n#####\n" << std::endl;

   std::getline(std::cin, input);
   ezStr::ToLower(input);
   commands = ezStr::ToVector(input);

   if (commands[0] == "move" && commands[1] == "state")
   {
      GAME_STATE = PUZZLE;
   }
}

void FREE_ROAM_STATE(bool isDEBUG)
{
   std::string userInput;
   std::vector<std::string> inputVec;
   room Rooms[MAX_ROOM_AMT];
   room currentRoom;
   item itemList[MAX_INV_AMT];
   vector2 startLoc = { 1,8 };
   set_Rooms(Rooms);
   set_items(Rooms, itemList);
   
   if (isDEBUG)
   {
      Player DEBUG_Player;
      DEBUG_Player.characterName = "**DEBUG_Player";
      DEBUG_Player.characterLocation = startLoc;
      update_playerPos(DEBUG_Player.characterLocation, currentRoom, Rooms);
      giveItem(itemList[0], DEBUG_Player);

      std::wcout << "########### DEBUGGING BUILD: " << gameVer << ", IS ACTIVE ##########\n";

      std::cout << "\nAll the available commands with all the available items:\n";

      std::cout << "\nType in \"Move North/South/East/West\" in order to navigate the map."
         << "\nType in \"Look Room/NPC/Inventory/Item\" in order to look around the map and at NPCs in a room."
         << "\nType in \"Use Item\" in order to use an item."
         << "\nType in \"Talk NPC\" in order to speak with an NPC if they're present."
         << "\nType in \"Take Item\" in order to grab an item if available in a room."
         << "\nType in \"Examine Item\" in order to grab an item if available.\n";

      std::cout << "\nPlease input a command: ";
      std::getline(std::cin, userInput);
      DEBUG::echo(userInput);
      std::cout << "Vallore: ";
      double inGame_Update = GetCurrentTime();
      parse(userInput, DEBUG_Player, currentRoom, Rooms);
      double inGame_InputUpdate = GetCurrentTime();
      std::cout << "\n" << std::endl;
      DEBUG::updateTick_Display(inGame_Update, inGame_InputUpdate);
      std::cout << "*DEBUG* " << "Current PLAYER location is: (" << DEBUG_Player.characterLocation.x
         << ", " << DEBUG_Player.characterLocation.y << ")" << std::endl;
      std::cout << "*DEBUG* " << "Current room: " << currentRoom.roomName
         << "\n*DEBUG* Current Room description: " << currentRoom.roomLook << std::endl;
   }
   else if (!isDEBUG)
   {

   }
}