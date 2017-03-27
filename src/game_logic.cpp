#include "game_logic.h"

#pragma warning (disable:4702)

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

void expo_story(int milestone)
{
   std::string exposition;

   switch (milestone)
   {
      case INTRO:
         exposition = "It's the last day of school at Gammorah Intermediate Prep. Our story centers"
                     " around the adventures of a thirteen year-old, socially awkward necromancer"
                     " named \"Valorre\". Valorre is currently daydreaming in his Wizard's class."
                     " His morning hallucinations are, to the say the least, unusual. Inundated by"
                     " images of salacious skeletons occupy his view, whispering unspeakables into"
                     " his young ear. Valorre's breath quickens, unsure of himself, and hopelessly"
                     " confused. \"Can skeletons even...?!\" Valorre sneakily utters under his"
                     " breath. As Valorre grows increasingly uncomfortable with his confounding"
                     " circumstances and apathetic libdo, he reaches for-- *WHAM*! A loud thud"
                     " rattles Valorre's, now steamy, insides. Startled, Valorre leapt from his"
                     " desk and looks around anxiously and prepared. There were audible laughs"
                     " amongst his peers around him. Regardless, alert and ready, what Valorre would"
                     " do if faced with"
                     " imminent danger, he knows not, but he thinks himself ready. The Wizard at"
                     " the front of the room sized up Valorre, looked visibly distressed and bellowed"
                     " \"Wizard: I-uhh. You belong not here if you, uhh, can't even remain attentive!"
                     " Out you go! Get out!\" The Wizard pushes Valorre, by his back, out of the"
                     " classroom. A bit dazzed from his recent awakening, Valorre dusts off his"
                     " robe, and-- \"Oh, my g-god...\" Valorre looks to a conspicuous and salacious"
                     " tent pitched under his lower-robe. Valorre is at a loss for words. \"Guess I"
                     " ought to go home... I'd g-go, uhh, South, I guess.\"";
         break;
      case BULLY_PUZZLE:
         exposition = "With his head held low, Valorre walks through the Commons double door. Before" 
                     " he could react, he's immediately stopped by Asgoth, the warrior prince" 
                     " outfitted with a tacky orange jersey plastered with a black \"14\" on the" 
                     " front. Accompanying Asgoth was his meagre accomplice, Volkun, the male" 
                     " Valkyrie. \"Hey, Necro! I heard you got a boner for the wizard! How pathetic!"
                     " A mature 14 year-old LIKE ME would NEVER be caught with my pants down like"
                     " that! Ha!\" Asgoth laughed and Volkun nervously chortled in passive agreement." 
                     " Not fully paying attention, Valorre wondered where he got that jersey. He had"
                     " never seen Asgoth wear it before. Not fully knowing or understanding Asgoth's"
                     " great vanity, Valorre sincerely hoped he didn't get a jersey just to" 
                     " commemorate his 14th birthday... Did he? \"Listen, since getting aroused by" 
                     " dudes isn't in the warrior's spirit, and this 14, basically adult, teen has" 
                     " things to do, I'll keep this short.I'll take it easy on ya today, so try and"
                     " guess the number I'm thinking of and this magnanimous 10 + 4 year - old will"
                     " let you go.\" With his chest puffed out and a cowering Volkun at his side,"
                     " he gets ready to continue.";
         break;
      case PUNISH:
         exposition = "Dragged into the white enchantress's office, Valorre and Asgoth sit still and"
                     " await further instruction. Asgoth appears apathetic as his father, is a known"
                     " PTA member with financial interest in the school. It doesn't seem like"
                     " anything meaningful will come of this despite Asgoth's deliberate agitation,"
                     " and Valorre will most likely be blamed. Again. The mere thought plunges"
                     " Valorre into a silent state of disarray. He cannot get into any trouble again!"
                     "  His father has gotten increasingly aggressive at his proclaimed"
                     " \"participation\" in these scuffles with Asgoth. Why won't he understand!"
                     " There isn't much a necromancer can do, especially not around here. If anyone"
                     " would understand, Valorre figured it'd be his own father. Without a second"
                     " thought, the door is flung open and the Dean saunters in. \"Oh.It's you two"
                     " again. A trial in Pond for Valorre and a word with Asgoth. The portal is there,"
                     " Valorre, go now!\" Valorre is hurried through a portal and transported. The"
                     " trip is much of the same. Flashing lights and disorientating images flicker"
                     " before Valorre's stone - cold face.Stoic from a numbing abject despair and a"
                     " frequent acceptance of lop - sided dealings at his expense.Abruptly, Valorre"
                     " is dropped on his backside in an unusual, but no less familiar place.Black sky,"
                     " desolate ground, strange cinnamon snack smell, Pond hadn't changed, but Valorre"
                     " had. \"I guess I ought to go South. A-about the only w-way I can go.\"";
         break;
      case EXE_HANGMAN:
         exposition = "Valorre steps down South and finds a gallow set up high.A young school kid is"
                     " strapped to the gallow tightly, he cannot be freed it seems. \"What in the world"
                     " is going on h-?!\" Before Valorre could finish a stocky pig-man drops from the"
                     " sky and stops Valorre in his tracks. \"Nya-ha! Looks like you're back, Valorre..."
                     " You may have bested me the last twelve times this year, but I'VE GOT YOU THIS"
                     " TIME! This kawaii piggu is gonna get-you! \" Valorre can hardly contain his"
                     " disgust at the prospect of this morbidly obese pig-man being cute, let alone"
                     " kawaii. \"I've got you now, young-blood! You won't be able to guess this cute"
                     " descriptor, and if you can't, this young boy will be... Well, let's just say,"
                     " I'll take out this kawaii trash, NYA!~\" At the pig-man's raccuous laughter,"
                     " the boy is awakened and, at the sudden realization of the current state of"
                     " affairs, begins to freak out. \"By t-the gods! I j-just won a Magic: The"
                     " Gathering game! We never agreeed to this! You were supposed to give me your"
                     " cute shoes! This is bull-!\" The kawaii pig-man slams his piggu-foot down and"
                     " rattles the gallows. \"Silence knave! Your flattering boyish charm won't get"
                     " you out of this mess, this time!... Now then... You surely understand the"
                     " severity of the situation, no? Now you must fight for this kawa-- I mean,"
                     " obnoxious boy's life! NYA-HA!\" Mildly annoyed, Valorre complies.";
         break;
      case REDEMPTION:
         exposition = "Returning from Pond was somber. Nobody seemed to care, which is typical."
                     " Valorre isn't convinced they've ever cared, but it doesn't matter. A quick"
                     " glance at the clock reveals that Valorre wasted a bit more time than necessary."
                     " It's about 4 o'clock now. Time to go. \"Guess I need to go East. I j-just want"
                     " to go home... I need to make it South, past the Commons.\"";
         break;
      case BULLY_END:
         exposition = "Valorre walks into the Courtyard. It's pretty dead, nobody is around. Everyone"
                     " would've left about two hours ago, so the barren yard is typical. \"I hate"
                     " leaving so early... I-I never h-have time for anything when this h-happens.\""
                     " Valorre begins to hurry toward the Portal Crossings so he could leave, but it"
                     " swiftly knocked down by Asgoth. Enraged, Valorre gets up fast and with purpose."
                     " He's tired of being bullied by this vain jerk. Asgoth laughes, but says"
                     " nothing. Valorre furrows his brow, and the two scowl at each other for what"
                     " seems like eternity. Within a moment's notice, Asgoth begins his assault, but"
                     " Valorre is not nearly as swift. Valorre is knocked to the ground, but don't"
                     " count him out just yet! Valorre begins an encantation and--! At just that"
                     " moment, Valorre is interrupted by the Dean. Who throws them both to opposite"
                     " ends of the courtyard with a strong push of force. At that point in time, The"
                     " Dean exclaims \"Go, Valorre. I'll handle Asgoth, and ensure that his father is"
                     " aware of his behavior. It is about time Asgoth got his.\" Asgoth begins to"
                     " pout and throw a tantrum. \"B-BUT, THIS IS BULL--\" At that point, the Dean"
                     " conjures an ethereal chain that hinders Asgoth's speaking. \"Be, QUIET! You've"
                     " said enough. Go, Valorre. Just continue South, and you will be fine.\" Valorre"
                     " in disbelief, scrambles up and begins his way South to the Portal Crossing.";
         break;
      case END_GAME:
         exposition = "Valorre makes it to the crossing. As he stands in front of a massive portal,"
                     " he reflects. Unsure of himself or his future. Although glad he never has to"
                     " come to this forsaken school again, he wonders if his secondary school"
                     " experience will be better... \"P - portals are... Interesting. Incorrectly"
                     " traverse and you could... just oblivion. Doesn't sound half bad.\" Valorre's"
                     " increasingly reckless and debased thinking edges him toward an awkward angle,"
                     " relative to the portal.At this strange angle, it should be easy, to..."
                     " Preferring this fate to what his father may do to him, he inches closer to the"
                     " portal. \"It would be so... ea--!\" At that moment, Volkun quickly emerges from"
                     " the portal. The two exchange glances momentarily. Empathetically, Volkun says,"
                     " \"H-hey, uhh. I'm sorry. He didn't mean it, I don't think a-at least. I.. I"
                     " know you're not a bad guy. I'm just too much of a c-coward to s-stop him, I"
                     " guess. I know it isn't fair t-to you, b-but I hope you u-understand... See you"
                     " n-next year, I guess.\" Volkun awkwardly pats Valorre on the shoulder, not"
                     " entirely sure of himself or whether or not his words are welcome. Volkun frowns,"
                     " looks forward, and continues on. Vallore is speechless and slightly less"
                     " dejected than before, processes what just occurred and Volkun's surprisingly"
                     " kind words. Valorre stands silent for about five minutes, staring deeply into"
                     " the portal. \"I guess... It's okay. I don't know, I-I don't really c-care. I..."
                     " Whatever.\" Valorre rights his angling and walks into the portal properly,"
                     " careening himself home to his father's swamp home.";
         break;
      default:
         exposition = "\n###INVALID STORY MILESTONE.###\n";
         break;
   }

   exposition = ezStr::ConsoleBuffer_Newline(exposition, CONSOLE_BUFFER_WIDTH);
   std::cout << "\n" << exposition << "\n\nPress any key to continue...";
   getchar();
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
         GAME_STATE = PUZZLE;
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
   if (commandDir[1] == "ITEM")
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
         std::cout << "\"There is no item to take.\"";
      }
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

   ezStr::Remove_Chars(input, ezStr::PUNCTUATION);
   ezStr::Remove_Chars(input, ezStr::NUMBERS_10);
   ezStr::To_Upper(input);
	commandVec = ezStr::To_Vector(input);

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
   int response = -1;

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
}

void update_gameBoard(const int& tries)
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
   std::string word_to_guess = "KAWAII";
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

   // initialize execuitioner's gallows
   update_gameBoard(TRIES);

   while (TRIES > 0)
   {
      size_t count = 0;
      bool notFound = true;

      // displays the buffer string each iteration and checks if it is completely dashes
      for (size_t i = 0; i < word_to_guess.length(); i++)
      {
         std::cout << bufferStr[i];

         if (count == (word_to_guess.length() - 1))
         {
            GAME_WON = true;
         }
         else if (bufferStr[i] != '-')
         {
            count++;
         }
      }

      std::wcout << "\n" <<std::endl;

      if (GAME_WON)
      {
         break;
      }
      else if (!GAME_WON)
      {
         // accepts input
         std::cout << "\n\nInput a letter before you hang the man!\n\nYou currently have " << TRIES << " tries left.\n\n" << "Letter: ";
         std::cin >> inputStr;
         ezStr::Cleanse_Alpha(inputStr, 'u');

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
         // update gallows
         update_gameBoard(TRIES);
      }
      
      if (notFound)
      {
         std::cout << "\n\nUh-oh! Looks like you missed a letter!\n" << std::endl;
         --TRIES;
         continue;
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

   if (isDEBUG)
   {
      std::cout << "#####\n\nPUZZLE STATE\n\n#####\n" << std::endl;

      std::getline(std::cin, input);
      ezStr::To_Lower(input);
      ezStr::Remove_Chars(input, ezStr::PUNCTUATION);
      commands = ezStr::To_Vector(input);

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
      else
      {
         std::cout << "\nI don't understand that!\n" << std::endl;
      }
   }
   else
   {

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
      std::cout << "\n" << std::endl;
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