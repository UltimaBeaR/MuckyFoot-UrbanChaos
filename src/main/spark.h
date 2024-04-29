//
// Electric sparks...
//

#pragma once

#include "../mfstdlib/mfstdlib.h"

//
// Removes all sparks.
//

void SPARK_init(void);

//
// Creates a new spark between two points...
//

#define SPARK_TYPE_POINT 1
#define SPARK_TYPE_LIMB 2
#define SPARK_TYPE_GROUND 3
#define SPARK_TYPE_CIRCULAR 4

#define SPARK_FLAG_CLAMP_X (1 << 0)
#define SPARK_FLAG_CLAMP_Y (1 << 1)
#define SPARK_FLAG_CLAMP_Z (1 << 2)
#define SPARK_FLAG_FAST (1 << 3)
#define SPARK_FLAG_SLOW (1 << 4)
#define SPARK_FLAG_DART_ABOUT (1 << 5)
#define SPARK_FLAG_STILL (SPARK_FLAG_CLAMP_X | SPARK_FLAG_CLAMP_Y | SPARK_FLAG_CLAMP_Z)

struct SPARK_Pinfo {
    UBYTE type;
    UBYTE flag;
    UBYTE padding;

    UBYTE dist; // For circular types... the distance from the first point.

    UWORD x; // Point and ground types...
    UWORD y;
    UWORD z;

    THING_INDEX person; // The limb to use.
    UWORD limb;
};

void SPARK_create(
    SPARK_Pinfo* point1,
    SPARK_Pinfo* point2,
    UBYTE max_life);

//
// Creates a spark somwhere in the given sphere.
//

void SPARK_in_sphere(
    SLONG mid_x,
    SLONG mid_y,
    SLONG mid_z,
    SLONG radius,
    UBYTE max_life,
    UBYTE max_create);

//
// Makes sparks appear on all the electric fences.
//

void SPARK_show_electric_fences(void);

//
// Process the sparks.
//

void SPARK_process(void);

//
// Draw the sparks...
//

#define SPARK_MAX_POINTS 5

struct SPARK_Info {
    SLONG num_points;
    ULONG colour;
    SLONG size;

    SLONG x[SPARK_MAX_POINTS];
    SLONG y[SPARK_MAX_POINTS];
    SLONG z[SPARK_MAX_POINTS];
};

void SPARK_get_start(UBYTE xmin, UBYTE xmax, UBYTE z);
SPARK_Info* SPARK_get_next(void); // NULL => No more sparks...
