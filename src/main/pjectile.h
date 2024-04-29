// Pjectile.h
// Guy Simmons, 4th January 1998.

#pragma once

#include "../mfstdlib/mfstdlib.h"

//---------------------------------------------------------------

#define MAX_PROJECTILES 10

#define PROJECTILE_NONE 0
#define PROJECTILE_TEST 1

//---------------------------------------------------------------

struct Projectile {
    COMMON(ProjectileType)
};

typedef Projectile* ProjectilePtr;

//---------------------------------------------------------------

void init_projectiles(void);
Thing* alloc_projectile(UBYTE type);
void free_projectile(Thing* proj_thing);

//---------------------------------------------------------------
