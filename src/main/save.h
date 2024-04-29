//
// Ingame save functions.
//

#pragma once

#include "../mfstdlib/mfstdlib.h"

//
// Return FALSE on failure.
//

SLONG SAVE_ingame(CBYTE* fname);
SLONG LOAD_ingame(CBYTE* fname);
