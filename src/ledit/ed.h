//
// Light editor.
//

#pragma once

typedef struct
{
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

} ED_Light;
