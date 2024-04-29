//
// frontend.h
//
// matthew rosenfeld 8 july 99
//
// this is our new front end thingy to replace the hideous startscr.cpp
//

#pragma once

#include "../mfstdlib/mfstdlib.h"

void FRONTEND_init(bool bGoToTitleScreen = FALSE);
SBYTE FRONTEND_loop();
void FRONTEND_level_won();
void FRONTEND_level_lost();

extern UBYTE IsEnglish;
