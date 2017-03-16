#include <iostream>
#include <vector>
#include <string>

#include "debug.h"
#include "ezstr.hpp"
#include "game_settings.h"
#include "game_logic.h"

int GAME_STATE = FREE_ROAM;

int main()
{
	set_Settings();
   bool GAME_ACTIVE = TRUE;
   expo_intro();

   // a rudimentary game loop for our purposes
	while (GAME_ACTIVE)
	{
      if (GAME_STATE == FREE_ROAM)
      {
         FREE_ROAM_STATE(IS_DEBUG);
      }
      else if (GAME_STATE == COMBAT)
      {
         COMBAT_STATE(IS_DEBUG);
      }
      else if (GAME_STATE == PUZZLE)
      {
         PUZZLE_STATE(IS_DEBUG);
      }
      else
      {
         std::cout << "\n\n\nINVALID GAME STATE. RESTART.\n\n\n";
      }
   }

return 0;
}