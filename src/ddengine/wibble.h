//
// Wibbles the given bit of screen.
//

#pragma once

#include "../mfstdlib/mfstdlib.h"

//
// ALL THESE FUNCTIONS MUST ONLY BE CALLED WHEN THE SCREEN IS LOCKED.
//
// Make sure the bounding boxes are all well on screen!
//

void WIBBLE_simple(
    SLONG x1, SLONG y1,
    SLONG x2, SLONG y2,
    UBYTE wibble_y1,
    UBYTE wibble_y2,
    UBYTE wibble_g1,
    UBYTE wibble_g2,
    UBYTE wibble_s1,
    UBYTE wibble_s2);
