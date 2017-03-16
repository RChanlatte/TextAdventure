#include <iostream>
#include <vector>
#include <string>

#include "debug.h"
#include "ezstr.hpp"
#include "game_settings.h"
#include "game_logic.h"

int main()
{
	set_Settings();
   bool GAME_ACTIVE = TRUE;

	if (IS_DEBUG)
	{
      std::wcout << "########### DEBUGGING BUILD: " << gameVer << ", IS ACTIVE ##########\n";

      std::cout << "\nAll the available commands with all the available items:\n";

      std::cout << "\nType in \"Move North/South/East/West\" in order to navigate the map."
         << "\nType in \"Look Room/NPC/Inventory/Item\" in order to look around the map and at NPCs in a room."
         << "\nType in \"Use Item\" in order to use an item."
         << "\nType in \"Talk NPC\" in order to speak with an NPC if they're present."
         << "\nType in \"Take Item\" in order to grab an item if available in a room."
         << "\nType in \"Examine Item\" in order to grab an item if available.\n";

		// a rudimentary game loop for our purposes
		while (GAME_ACTIVE)
		{
         if (CURRENT_GAME_STATE == FREE_ROAM)
         {
            FREE_ROAM_STATE(TRUE);
         }
         else if (CURRENT_GAME_STATE == COMBAT)
         {
            COMBAT_STATE(TRUE);
         }
         else if (CURRENT_GAME_STATE == PUZZLE)
         {
            PUZZLE_STATE(TRUE);
         }
         else
         {
            std::cout << "\n\n\nINVALID GAME STATE. RESTART.\n\n\n";
         }
         
		}
	}
	else if (!IS_DEBUG)
	{
		Player player;

		std::cout << "Welcome to my text adventure.";
	}

    return 0;
}