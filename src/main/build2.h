//
// The other building file!  A simpler map...
//

#pragma once

#include "../mfstdlib/mfstdlib.h"

//
// Puts all the facets and walkable faces on the mapwho.
//

void build_quick_city(void);

//
// Puts an single walkable face onto the Walkable mapwho.
// Removes a walkable face from the mapwho.
//

void attach_walkable_to_map(SLONG face);
void remove_walkable_from_map(SLONG face);

//
// Adds a dfacet to the mapwho.
//

void add_facet_to_map(SLONG dfacet);
