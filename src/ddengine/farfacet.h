//
// Faster far-facets...
//

#pragma once

#include "../mfstdlib/mfstdlib.h"

//
// Creates optimised data for drawing farfacets.
// Call after all facets have been loaded.
//

void FARFACET_init(void);

//
// Draws the far facets that can be seen from this view.
//

void FARFACET_draw(
    float x,
    float y,
    float z,
    float yaw,
    float pitch,
    float roll,
    float draw_dist,
    float lens);

//
// Frees up memory.
//

void FARFACET_fini(void);
