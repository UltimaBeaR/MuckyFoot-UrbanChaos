/************************************************************
 *
 *   pause.h
 *   Handles pause mode
 *
 *   Prolly overkill giving it one of these all of it's own
 *   but game.cpp is messy enuff already...
 *
 */

#pragma once

#include "../mfstdlib/mfstdlib.h"

//
// Returns TRUE if you should exit the game loop...
//

SLONG PAUSE_handler();
