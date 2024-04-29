//
// An A-Z of the current city.
//

#pragma once

#include "../mfstdlib/mfstdlib.h"

//
// Creates a line-based representation of the current city. Make sure
// you have already sunken the roads before calling this function.
//

#define AZ_LINE_TYPE_ROAD 0
#define AZ_LINE_TYPE_BUILDING 1
#define AZ_LINE_TYPE_FENCE 2
#define AZ_LINE_TYPE_NUMBER 3

struct AZ_Line {
    UBYTE type;
    UBYTE x1;
    UBYTE z1;
    UBYTE x2;
    UBYTE z2;
};

extern AZ_Line AZ_line[];
extern SLONG AZ_line_upto;
