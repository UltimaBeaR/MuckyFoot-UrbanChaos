// Structs.h
// Guy Simmons, 17th October 1997.

#pragma once

#include "../editor/anim.h"

//---------------------------------------------------------------

struct GameCoord {
    SLONG X,
        Y,
        Z;
};

struct SVector {
    SLONG X, Y, Z;
};

struct SmallSVector {
    SWORD X, Y, Z;
};

struct SVECTOR {
    SLONG X, Y, Z;
};

struct TinyXZ {
    SBYTE Dx, Dz;
    SWORD Angle;
};

struct MiniTextureBits {
    UWORD X : 3;
    UWORD Y : 3;
    UWORD Page : 4;
    UWORD Rot : 2;
    UWORD Flip : 2;
    UWORD Size : 2;
};

struct MAV_Action {
    UBYTE action;
    UBYTE dir;
    UBYTE dest_x;
    UBYTE dest_z;
};

//---------------------------------------------------------------

struct Thing; //	Prototype the 'Thing' structure.
struct CommandList; //	Prototype 'CommandList' structure.

#define COMMON(TYPE)   \
    UBYTE TYPE;        \
    UBYTE padding;     \
    THING_INDEX Thing; \
    ULONG Flags;

/*
#define	COMMON(TYPE)	UBYTE			TYPE,			\
                                                                                State;			\
                                                UWORD			CommandRef,		\
                                                                                Command;		\
                                                SWORD			Velocity;		\
                                                ULONG			Flags;			\
                                                SLONG			Timer;			\
                                                CommandList		*ComList;		\
                                                THING_INDEX		Thing,padding;
*/

//---------------------------------------------------------------

#define FLAGS_DRAW_SHADOW (1 << 0)

//---------------------------------------------------------------
