//
// A whole new world...
//

#pragma once

//
// Big map!
//

#define QMAP_SIZE 1024

// ========================================================
//
// CREATING THE MAP
//
// ========================================================

void QMAP_init(void);

void QMAP_add_road(
    SLONG x1, SLONG z1,
    SLONG x2, SLONG z2);

void QMAP_add_cube(
    SLONG x1, SLONG z1,
    SLONG x2, SLONG z2,
    SLONG height);

void QMAP_add_prim(
    SLONG x,
    SLONG y,
    SLONG z,
    SLONG prim,
    SLONG yaw);

// ========================================================
//
// Accessing the map.
//
// ========================================================

//
// Calculates the height of the map at (x,z) ignoring the cubes.
// Coordinates are in 8-bit fixed point.  i.e. from 0 << 8 to QMAP_SIZE << 8
//

SLONG QMAP_calc_height_at(SLONG x, SLONG z);

//
// Returns the block coordinates of the given cube.
//

void QMAP_get_cube_coords(
    UWORD cube,
    SLONG* x1, SLONG* y1, SLONG* z1,
    SLONG* x2, SLONG* y2, SLONG* z2);

// ========================================================
//
// THE MAP DATA STRUCTURE
//
// ========================================================

//
// The styles.
//

#define QMAP_MAX_TEXTURES 4096

extern UWORD QMAP_texture[QMAP_MAX_TEXTURES];
extern SLONG QMAP_texture_upto;

#define QMAP_STYLE_USED (1 << 0)
#define QMAP_STYLE_WRAP_X (1 << 1)
#define QMAP_STYLE_WRAP_Y (1 << 2)

struct QMAP_Style {
    UBYTE size_x;
    UBYTE size_y;
    UWORD flag;
    UWORD index; // Index into the QMAP_texture array.
};

#define QMAP_MAX_STYLES 256

extern QMAP_Style QMAP_style[QMAP_MAX_STYLES];
extern SLONG QMAP_style_upto;

//
// The roads.
//

struct QMAP_Road {
    UWORD x;
    UWORD z;
    UBYTE size_x;
    UBYTE size_z;
};

#define QMAP_MAX_ROADS 1024

extern QMAP_Road QMAP_road[QMAP_MAX_ROADS];
extern SLONG QMAP_road_upto;

//
// The cubes.
//

struct QMAP_Cube {
    UWORD x;
    UWORD z;
    UBYTE size_x;
    UBYTE size_y;
    UBYTE size_z;
    UBYTE flag;
    UWORD style[5];
};

#define QMAP_MAX_CUBES 1024

extern QMAP_Cube QMAP_cube[QMAP_MAX_CUBES];
extern SLONG QMAP_cube_upto;

//
// The ground textures.
//

struct QMAP_Gtex {
    UWORD x;
    UWORD z;
    UBYTE size_x;
    UBYTE size_z;
    UWORD style;
};

#define QMAP_MAX_GTEXES 4096

extern QMAP_Gtex QMAP_gtex[QMAP_MAX_GTEXES];
extern SLONG QMAP_gtex_upto;

//
// The cables.
//

struct QMAP_Cable {
    UWORD x1;
    UWORD z1;
    UWORD x2;
    UWORD z2;
    UBYTE y1;
    UBYTE y2;
    UBYTE flag;
    UBYTE along;
};

#define QMAP_MAX_CABLES 512

extern QMAP_Cable QMAP_cable[QMAP_MAX_CABLES];
extern SLONG QMAP_cable_upto;

//
// The heights used by the height maps.
//

#define QMAP_MAX_HEIGHTS 8192

extern SBYTE QMAP_height[QMAP_MAX_HEIGHTS];
extern SLONG QMAP_height_upto;

//
// The heightmaps.
//

struct QMAP_Hmap {
    UWORD x;
    UWORD z;
    UBYTE size_x;
    UBYTE size_z;

    //
    // If the top bit is set then the height map is at a
    // constant height, otherwise the height map defines
    // a bitmap.
    //
    // top bit  one: height - 0xa000 is the signed constant height of the heightmap.
    // top bit zero: height is an index into the QMAP_height array.
    //

    UWORD height;
};

#define QMAP_MAX_HMAPS 64

extern QMAP_Hmap QMAP_hmap[QMAP_MAX_HMAPS];
extern SLONG QMAP_hmap_upto;

//
// Fences/walls...
//

#define QMAP_FENCE_NORMAL 1
#define QMAP_FENCE_BARBED 2
#define QMAP_FENCE_WALL 3

struct QMAP_Fence {
    UBYTE type;
    UBYTE y; // Above the ground.
    UWORD x1;
    UWORD z1;
    UBYTE size_x;
    UBYTE size_z;
};

#define QMAP_MAX_FENCES 1024

extern QMAP_Fence QMAP_fence[QMAP_MAX_FENCES];
extern SLONG QMAP_fence_upto;

//
// Static lights / anti-lights.  Some lights
// are automatically allocted to prims aswell.
//

struct QMAP_Light {
    UBYTE x;
    UBYTE y;
    UBYTE z;
    SBYTE red;
    SBYTE green;
    SBYTE blue;
    UBYTE range;
};

#define QMAP_MAX_LIGHTS 2048

extern QMAP_Light QMAP_light[QMAP_MAX_LIGHTS];
extern SLONG QMAP_light_upto;

//
// The prims.
//

struct QMAP_Prim {
    UBYTE x;
    UBYTE y;
    UBYTE z;
    UBYTE yaw;
    UBYTE prim;
};

#define QMAP_MAX_PRIMS 16384

extern QMAP_Prim QMAP_prim[QMAP_MAX_PRIMS];
extern SLONG QMAP_prim_upto;

//
// The map is stored on a high-level 32x32 mapwho basis.
//

#define QMAP_MAPSIZE (QMAP_SIZE / 32)

//
// The all array...
//

#define QMAP_MAX_ALL 32768

extern UWORD QMAP_all[QMAP_MAX_ALL];
extern SLONG QMAP_all_upto;

//
// The map.
//

struct QMAP_Map {
    UWORD index_all;
    UWORD index_prim;

    UBYTE num_roads; // We don't need a UBYTE for each of these.
    UBYTE num_cubes;
    UBYTE num_gtexes;
    UBYTE num_cables;
    UBYTE num_hmaps;
    UBYTE num_fences;
    UBYTE num_lights;

    UBYTE num_prims;
};

extern QMAP_Map QMAP_map[QMAP_MAPSIZE][QMAP_MAPSIZE];

//
// For getting the index into the all array for each type of thing.
//

#define QMAP_ALL_INDEX_ROADS(qm) ((qm)->index_all)
#define QMAP_ALL_INDEX_CUBES(qm) ((qm)->index_all + (qm)->num_roads)
#define QMAP_ALL_INDEX_GTEXES(qm) ((qm)->index_all + (qm)->num_roads + (qm)->num_cubes)
#define QMAP_ALL_INDEX_CABLES(qm) ((qm)->index_all + (qm)->num_roads + (qm)->num_cubes + (qm)->num_gtexes)
#define QMAP_ALL_INDEX_HMAPS(qm)  ((qm)->index_all + (qm)->num_roads + (qm)->num_cubes + (qm)->num_gtexes) + (qm)->num_cables)
#define QMAP_ALL_INDEX_FENCES(qm) ((qm)->index_all + (qm)->num_roads + (qm)->num_cubes + (qm)->num_gtexes) + (qm)->num_cables + (qm)->num_hmaps)
#define QMAP_ALL_INDEX_LIGHTS(qm) ((qm)->index_all + (qm)->num_roads + (qm)->num_cubes + (qm)->num_gtexes) + (qm)->num_cables + (qm)->num_hmaps + (qm)->num_fences)

//
// The total amount of ALL info used by a mapsquare.
//

#define QMAP_TOTAL_ALL(qm) ((qm)->num_roads + (qm)->num_cubes + (qm)->num_gtexes + (qm)->num_cables + (qm)->num_hmaps + (qm)->num_fences + (qm)->num_lights)

// ========================================================
//
// DRAWING THE MAP DATA-STRUCTURE.
//
// ========================================================

//
// The normals in the points.
//

#define QMAP_POINT_NORMAL_XPOS 0
#define QMAP_POINT_NORMAL_XNEG 1
#define QMAP_POINT_NORMAL_YPOS 2
#define QMAP_POINT_NORMAL_YNEG 3
#define QMAP_POINT_NORMAL_ZPOS 4
#define QMAP_POINT_NORMAL_ZNEG 5
#define QMAP_POINT_NORMAL_NUMBER 6

//
// The points.
//

struct QMAP_Point {
    UWORD x; // Relative to the mapsquare the point is in (8-bit fixed point)
    SWORD y;
    UWORD z;
    UBYTE red;
    UBYTE green;
    UBYTE blue;
    UBYTE trans; // Last last GAMETURN this point was transformed.
    UBYTE normal;
    UBYTE padding;
    UWORD next;
};

#define QMAP_MAX_POINTS 2048

extern QMAP_Point QMAP_point[QMAP_MAX_POINTS];
extern UWORD QMAP_point_free;

//
// The faces
//

#define QMAP_FACE_FLAG_SHADOW1 (1 << 0)
#define QMAP_FACE_FLAG_SHADOW2 (1 << 1)

struct QMAP_Face {
    UWORD point[4];
    UWORD texture;
    UWORD flag;
    UWORD next;
};

#define QMAP_MAX_FACES 2048

extern QMAP_Face QMAP_face[QMAP_MAX_FACES];
extern UWORD QMAP_face_free;

//
// Each height-field square and height-field point.
//

struct QMAP_Hsquare {
    UWORD texture;
    UWORD flag;
    SBYTE height;
    UBYTE red;
    UBYTE green;
    UBYTE blue;
};

//
// This is the structure you use to draw a mapsquare.
//

struct QMAP_Draw {
    //
    // A 32x32 height-field. It goes up to 33, so you can
    // have the last row of points available.
    //

    QMAP_Hsquare hf[33][33];
    UBYTE map_x;
    UBYTE map_z;
    UBYTE trans;

    //
    // The points and faces created from the cubes, fences and walls.
    //

    UWORD next_point;
    UWORD next_face;
};

//
// Initialises all the points and faces.
//

void QMAP_draw_init(void);

//
// Fills in the QMAP_Draw structure for the given mapsquare.
//

void QMAP_create(QMAP_Draw* fill_me_in, SLONG map_x, SLONG map_z);

//
// Frees all the points and faces from the given QMAP_Draw structure.
//

void QMAP_free(QMAP_Draw* free_me_up);
