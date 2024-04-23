//
// Entering buildings.
//

#include "game.h"
#include "pap.h"
#include "enter.h"
#include "id.h"
#include "stair.h"
#include "supermap.h"
#include "memory.h"

//
// Returns TRUE if the building is valid to enter.
//

SLONG ENTER_valid(SLONG dbuilding)
{
    SLONG i;
    SLONG dx;
    SLONG dz;

    DBuilding* db;
    DFacet* df;

    ASSERT(WITHIN(dbuilding, 1, next_dbuilding - 1));

    db = &dbuildings[dbuilding];

    //
    // Make sure all the facets are orthogonal.
    //

    for (i = db->StartFacet; i < db->EndFacet; i++) {
        ASSERT(WITHIN(i, 1, next_dfacet - 1));

        df = &dfacets[i];

        dx = df->X[1] - df->X[0];
        dz = df->Z[1] - df->Z[0];

        if (dx && dz) {
            //
            // Invalid building.
            //

            return FALSE;
        }
    }

    return TRUE;
}

//
// Returns the outline of the building thing. This does not
// include fire-escapes and add-ons, it only looks at the
// STOREY_TYPE_NORMAL walls. It is non-inclusive, so a 1x1
// building has a bounding box of (0,0)-(1,1)
//

void ENTER_building_box(SLONG dbuilding, SLONG* bx1, SLONG* bz1, SLONG* bx2, SLONG* bz2)
{
    SLONG i;

    SLONG x;
    SLONG z;

    SLONG x1;
    SLONG z1;
    SLONG x2;
    SLONG z2;

    DBuilding* db;
    DFacet* df;

    SLONG height;

    //
    // Initialise the bounding box.
    //

    x1 = +INFINITY;
    z1 = +INFINITY;
    x2 = -INFINITY;
    z2 = -INFINITY;

    //
    // Find the building.
    //

    ASSERT(WITHIN(dbuilding, 1, next_dbuilding - 1));

    db = &dbuildings[dbuilding];

    //
    // Go through the dfacets for this building.
    //

    for (i = db->StartFacet; i < db->EndFacet; i++) {
        ASSERT(WITHIN(i, 1, next_dfacet - 1));

        df = &dfacets[i];

        if (df->FacetType == STOREY_TYPE_NORMAL) {
            x = df->X[0];
            z = df->Z[0];

            if (x < x1) {
                x1 = x;
            }
            if (x > x2) {
                x2 = x;
            }
            if (z < z1) {
                z1 = z;
            }
            if (z > z2) {
                z2 = z;
            }

            x = df->X[1];
            z = df->Z[1];

            if (x < x1) {
                x1 = x;
            }
            if (x > x2) {
                x2 = x;
            }
            if (z < z1) {
                z1 = z;
            }
            if (z > z2) {
                z2 = z;
            }
        }
    }

    //
    // Return the bounding box.
    //

    *bx1 = x1;
    *bz1 = z1;
    *bx2 = x2;
    *bz2 = z2;
}

ENTER_Okay ENTER_can_i(THING_INDEX me)
{
    SLONG dx;
    SLONG dz;

    SLONG x1;
    SLONG z1;
    SLONG x2;
    SLONG z2;

    SLONG mx;
    SLONG mz;

    SLONG mx1;
    SLONG mz1;
    SLONG mx2;
    SLONG mz2;

    SLONG facet;
    SLONG f_list;
    SLONG exit;

    DFacet* df;

    ENTER_Okay ans;

    Thing* p_me = TO_THING(me);

    ASSERT(p_me->Class == CLASS_PERSON);

    //
    // If I were to walk forward... would I cross a colvect
    // generated by a recessed door?
    //

    dx = -SIN(p_me->Draw.Tweened->Angle) >> 9;
    dz = -COS(p_me->Draw.Tweened->Angle) >> 9;

    x1 = p_me->WorldPos.X >> 8;
    z1 = p_me->WorldPos.Z >> 8;

    x2 = x1 + dx;
    z2 = z1 + dz;

    //
    // Is the square we are going to inside a building?
    //

    mx = x2 >> PAP_SHIFT_HI;
    mz = z2 >> PAP_SHIFT_HI;

    if (!WITHIN(mx, 0, PAP_SIZE_HI - 1) || !WITHIN(mz, 0, PAP_SIZE_HI - 1)) {
        //
        // We can't be going to a building off the map!
        //

        ans.dbuilding = NULL;

        return ans;
    }

    //	if (PAP_2HI(mx,mz).Flags & PAP_FLAG_HIDDEN)
    {
        //
        // To find which building we are in, we must
        // check which facet the movement vector crosses.
        //

        mx1 = x2 - 0x100 >> PAP_SHIFT_LO;
        mz1 = z2 - 0x100 >> PAP_SHIFT_LO;
        mx2 = x2 + 0x100 >> PAP_SHIFT_LO;
        mz2 = z2 + 0x100 >> PAP_SHIFT_LO;

        if (mx1 < 0) {
            mx1 = 0;
        }
        if (mz1 < 0) {
            mz1 = 0;
        }

        if (mx2 > PAP_SIZE_LO - 1) {
            mx2 = PAP_SIZE_LO - 1;
        }
        if (mz2 > PAP_SIZE_LO - 1) {
            mz2 = PAP_SIZE_LO - 1;
        }

        for (mx = mx1; mx <= mx2; mx++)
            for (mz = mz1; mz <= mz2; mz++) {
                f_list = PAP_2LO(mx, mz).ColVectHead;

                if (f_list) {
                    exit = FALSE;

                    while (1) {
                        ASSERT(WITHIN(f_list, 1, next_facet_link - 1));

                        facet = facet_links[f_list];

                        if (facet < 0) {
                            facet = -facet;
                            exit = TRUE;
                        }

                        ASSERT(WITHIN(facet, 1, next_dfacet - 1));

                        df = &dfacets[facet];

                        if (two4_line_intersection(
                                x1, z1,
                                x2, z2,
                                df->X[0], df->Z[0],
                                df->X[1], df->Z[1])) {
                            //
                            // Only enter if the building is valid.
                            //

                            if (ENTER_valid(df->Building)) {
                                //
                                // We have entered this building this facet belongs to.
                                //

                                ans.dbuilding = df->Building;
                                ans.map_x = x2 >> PAP_SHIFT_HI;
                                ans.map_z = z2 >> PAP_SHIFT_HI;

                                return ans;
                            }
                        }

                        if (exit) {
                            break;
                        }

                        f_list += 1;
                    }
                }
            }
    }

    ans.dbuilding = NULL;

    return ans;
}

SLONG ENTER_leave(THING_INDEX me, UBYTE* map_x, UBYTE* map_z)
{
    //
    // We can do this in a really bad way!  Move forward and turn around.
    // If you can then go into the INSIDE_BUILDING, then we can leave
    // the current building!
    //

    return FALSE;
}

void ENTER_get_extents(
    SLONG dbuilding,
    SLONG* height_ground_floor,
    SLONG* height_of_top_storey)
{
    ASSERT(WITHIN(dbuilding, 1, next_dbuilding - 1));

    DFacet* df;
    DBuilding* db = &dbuildings[dbuilding];

    SLONG i;
    SLONG top;
    SLONG bot;

    SLONG max = -INFINITY;
    SLONG min = +INFINITY;

    for (i = db->StartFacet; i < db->EndFacet; i++) {
        ASSERT(WITHIN(i, 1, next_dfacet - 1));

        df = &dfacets[i];

        //
        // What is the height of this facet?
        //

        bot = df->Y[0];
        top = bot + df->Height * 64;
        top -= 256; // The floor not the ceiling...

        if ((bot & 0x3f) || (top & 0x3f)) {
            //
            // I thought that we were going to retrict the height of
            // building to quarter mapsquares?
            //

            ASSERT(0);
        }

        if (top > max) {
            max = top;
        }
        if (bot < min) {
            min = bot;
        }
    }

    ASSERT((bot & 0xff) == (top & 0xff));

    *height_ground_floor = min;
    *height_of_top_storey = max;
}

SLONG ENTER_num_blocks(SLONG x1, SLONG z1, SLONG x2, SLONG z2)
{
    SLONG dx = abs(x2 - x1);
    SLONG dz = abs(z2 - z1);

    SLONG num_blocks;

    //
    // Wall are always orthogonal nowadays.
    //

    ASSERT(dx == 0 || dz == 0);

    num_blocks = dx + dz;

    return num_blocks;
}

SLONG ENTER_get_type(SLONG id, SLONG block)
{
    //
    // Maybe we should be a bit cleverer than this!
    //

    return ID_BLOCK_TYPE_WINDOW;
}

//
// Sets up the stair module with the given dbuilding.
// Returns FALSE if it couldn't put the stairs in.
//

SLONG ENTER_setup_stairs(SLONG dbuilding)
{
    SLONG i;
    SLONG y;

    SLONG bx1;
    SLONG bz1;
    SLONG bx2;
    SLONG bz2;

    SLONG bot;
    SLONG top;

    SLONG storey_bot;
    SLONG storey_top;

    SLONG storey;

    ASSERT(WITHIN(dbuilding, 1, next_dbuilding - 1));

    DFacet* df;
    DBuilding* db = &dbuildings[dbuilding];

    //
    // Initialise the stair module.
    //

    STAIR_init();

    //
    // Tell the stair module about the bounding box of the building.
    //

    ENTER_building_box(
        dbuilding,
        &bx1,
        &bz1,
        &bx2,
        &bz2);

    bx1 >>= PAP_SHIFT_HI;
    bz1 >>= PAP_SHIFT_HI;
    bx2 >>= PAP_SHIFT_HI;
    bz2 >>= PAP_SHIFT_HI;

    STAIR_set_bounding_box(
        bx1, bz1,
        bx2, bz2);

    //
    // Find the extent of the stories of this building.
    //

    ENTER_get_extents(
        dbuilding,
        &bot,
        &top);

    //
    // Go through each storey of the building.
    //

    storey = 0;

    for (y = bot; y <= top; y += 256) {
        STAIR_storey_new(y, storey);

        for (i = db->StartFacet; i < db->EndFacet; i++) {
            ASSERT(WITHIN(i, 1, next_dfacet - 1));

            df = &dfacets[i];

            storey_bot = df->Y[0];
            storey_top = storey_bot + df->Height * 64;
            storey_top -= 256;

            if (WITHIN(y, storey_bot, storey_top)) {
                STAIR_storey_wall(
                    df->X[0] >> PAP_SHIFT_HI,
                    df->Z[0] >> PAP_SHIFT_HI,
                    df->X[1] >> PAP_SHIFT_HI,
                    df->Z[1] >> PAP_SHIFT_HI,
                    FALSE);
            }
        }

        if (STAIR_storey_finish() == FALSE) {
            //
            // This is an invalid storey.
            //

            return FALSE;
        }
    }

    //
    // The stair module knows about all the stories now so
    // it can put down the stairs.
    //

    STAIR_calculate(db->SeedStairs);

    return TRUE;
}

SLONG ENTER_setup(SLONG dbuilding, SLONG height, UBYTE furnished, UBYTE find_best_layout)
{
    SLONG i;

    SLONG x1;
    SLONG z1;
    SLONG x2;
    SLONG z2;
    SLONG num_blocks;
    SLONG building_bot;
    SLONG building_top;
    SLONG storey_bot;
    SLONG storey_top;
    SLONG id_storey_type;
    SLONG result;
    SLONG ground_floor;

    ID_Stair* stair;
    SLONG num_stairs;
    SLONG stairs_ok;

    ASSERT(WITHIN(dbuilding, 1, next_dbuilding - 1));

    DFacet* df;
    DBuilding* db = &dbuildings[dbuilding];

    if (db->Type == BUILDING_TYPE_CRATE_IN || db->Type == BUILDING_TYPE_CRATE_OUT) {
        //
        // You cant go inside crates.
        //

        return FALSE;
    }

    if (!ENTER_valid(dbuilding)) {
        //
        // Cant go into this building.
        //

        return FALSE;
    }

    //
    // The top and bottom floors of the building.
    //

    ENTER_get_extents(
        dbuilding,
        &building_bot,
        &building_top);

    if (!WITHIN(height, building_bot, building_top)) {
        //
        // No storey at this height.
        //

        return FALSE;
    }

    if ((height & 0xff) != (building_bot & 0xff)) {
        //
        // This height is not at the floor level of any storey.
        //

        return FALSE;
    }

    //
    // Store the INDOORS stuff.
    //

    ASSERT((height & 0x3f) == 0);

    INDOORS_HEIGHT_FLOOR = height;
    INDOORS_DBUILDING = dbuilding;

    if (db->Type == BUILDING_TYPE_WAREHOUSE) {
        //
        // Warehouses are two storeys high...
        //

        INDOORS_HEIGHT_CEILING = INDOORS_HEIGHT_FLOOR + 0x200;
    } else {
        INDOORS_HEIGHT_CEILING = INDOORS_HEIGHT_FLOOR + 0x100;
    }

    //
    // Find the position of the stairs throughout this building.
    //

    if (ENTER_setup_stairs(dbuilding) == FALSE) {
        //
        // Couldn't setup the stairs... one of the storeys is not circular?
        //

        return FALSE;
    }

    //
    // Create the floorplan for this storey.
    //

    ID_clear_floorplan();

    for (i = db->StartFacet; i < db->EndFacet; i++) {
        ASSERT(WITHIN(i, 1, next_dfacet - 1));

        df = &dfacets[i];

        storey_bot = df->Y[0];
        storey_top = storey_bot + df->Height * 64;
        storey_top -= 256;

        if (WITHIN(height, storey_bot, storey_top)) {
            x1 = df->X[0] >> PAP_SHIFT_HI;
            z1 = df->Z[0] >> PAP_SHIFT_HI;
            x2 = df->X[1] >> PAP_SHIFT_HI;
            z2 = df->Z[1] >> PAP_SHIFT_HI;

            //
            // How many blocks in this wall?
            //

            num_blocks = ENTER_num_blocks(x1, z1, x2, z2);

            //
            // Tell the interior designer about this wall.
            //

            ID_set_outline(x1, z1, x2, z2, i, num_blocks);
        }
    }

    //
    // The function that says what type each block of each
    // wall is.
    //

    ID_set_get_type_func(ENTER_get_type);

    //
    // What is the storey type?
    //

    ground_floor = (height == building_bot);

    switch (db->Type) {
    case BUILDING_TYPE_HOUSE:
        id_storey_type = (ground_floor) ? ID_STOREY_TYPE_HOUSE_GROUND : ID_STOREY_TYPE_HOUSE_UPPER;
        break;
    case BUILDING_TYPE_OFFICE:
        id_storey_type = (ground_floor) ? ID_STOREY_TYPE_OFFICE_GROUND : ID_STOREY_TYPE_OFFICE_UPPER;
        break;
    case BUILDING_TYPE_WAREHOUSE:
        id_storey_type = ID_STOREY_TYPE_WAREHOUSE;
        break;
    case BUILDING_TYPE_APARTEMENT:
        id_storey_type = (ground_floor) ? ID_STOREY_TYPE_APARTEMENT_GROUND : ID_STOREY_TYPE_APARTEMENT_UPPER;
        break;

    default:
        ASSERT(0);
        break;
    }

    if (id_storey_type == ID_STOREY_TYPE_WAREHOUSE) {
        //
        // No stairs in a warehouse.
        //

        stairs_ok = TRUE;
        num_stairs = 0;
        stair = NULL;
    } else {
        //
        // Where are the stairs on this storey?
        //

        stairs_ok = STAIR_get(
            height,
            &stair,
            &num_stairs);
    }

    if (stairs_ok) {
        //
        // Generate the floorplan.
        //

        result = ID_generate_floorplan(
            id_storey_type,
            stair,
            num_stairs,
            db->SeedInside,
            find_best_layout,
            furnished);

        if (result >= 0) {
            ASSERT(find_best_layout || result == db->SeedInside);

            //
            // Succeeded and used seed 'result'.
            //

            db->SeedInside = result;

            return TRUE;
        } else {
            //
            // Could not generate the floorplan.
            //

            return FALSE;
        }
    } else {
        //
        // Could not get stairs.
        //

        return FALSE;
    }
}