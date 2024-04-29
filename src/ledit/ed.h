//
// Light editor.
//

#pragma once

#include "../mfstdlib/mfstdlib.h"

// Note: ultimabear: used in night.cpp as struct for loading game format file for initializing light stuff. It's not editor-only stuff, so mabe better to rename it and move to night.cpp
struct ED_Light {
    UBYTE range;
    SBYTE red;
    SBYTE green;
    SBYTE blue;
    UBYTE next;
    UBYTE used;
    UBYTE flags;
    UBYTE padding;
    //	UWORD padding;
    SLONG x;
    SLONG y;
    SLONG z;
};
