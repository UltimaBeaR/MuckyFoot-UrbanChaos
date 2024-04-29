// Gamut.h
// Guy Simmons, 4th November 1997.

#pragma once

#include "../mfstdlib/mfstdlib.h"

//---------------------------------------------------------------

#define MAX_GAMUT_RADIUS (24)

//---------------------------------------------------------------

struct GamutElement {
    SBYTE DX,
        DZ;
    SWORD Angle;
};

//---------------------------------------------------------------

extern GamutElement gamut_ele_pool[],
    *gamut_ele_ptr[];

void build_gamut_table(void);
void draw_gamut(SLONG x, SLONG y);

//---------------------------------------------------------------
