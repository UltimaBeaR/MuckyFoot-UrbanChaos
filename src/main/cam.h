//
// An 'intelligent' camera?
//

#pragma once

//
// Set up the camera. Make sure the camera has a sensible focus,
// zoom and mode before you call CAM_process().
//

#define CAM_MODE_CRAPPY 0
#define CAM_MODE_NORMAL 1
#define CAM_MODE_STATIONARY 2
#define CAM_MODE_BEHIND 3
#define CAM_MODE_FIRST_PERSON 4
#define CAM_MODE_THIRD_PERSON 5
#define CAM_MODE_SHOOT_NORMAL 6
#define CAM_MODE_FIGHT_NORMAL 7

#define CAM_LENS_NORMAL 0
#define CAM_LENS_WIDEANGLE 1
#define CAM_LENS_ZOOM 2

extern SLONG CAM_lens;

//
// Predefined camera types.
//

#define CAM_TYPE_STANDARD 1
#define CAM_TYPE_LOWER 2
#define CAM_TYPE_BEHIND 3
#define CAM_TYPE_WIDE 4
#define CAM_TYPE_ZOOM 5

//
// Processes the camera.
//

void CAM_process(void);

//
// Puts the camera in a good position to watch the given
// person climb out of the sewers.
//

void CAM_set_to_leave_sewers_position(Thing*);
