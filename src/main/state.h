// State.h
// Guy Simmons, 4th January 1998.

#pragma once

#include "../mfstdlib/mfstdlib.h"

struct Thing;
//---------------------------------------------------------------

struct StateFunction {
    UBYTE State;
    void (*StateFn)(Thing*);
};

//---------------------------------------------------------------

struct GenusFunctions {
    UBYTE Genus;
    StateFunction* StateFunctions;
};

//---------------------------------------------------------------

extern void set_state_function(Thing* t_thing, UBYTE state);
extern void set_generic_person_state_function(Thing* t_thing, UBYTE state);
extern void set_generic_person_just_function(Thing* t_thing, UBYTE state);

//---------------------------------------------------------------
