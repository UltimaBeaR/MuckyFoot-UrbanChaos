#pragma once
// #define	STATE_LOCAL					5
// Thing states.
#define STATE_INIT 0
#define STATE_NORMAL 1
#define STATE_COLLISION 2
#define STATE_ABOUT_TO_REMOVE 3
#define STATE_REMOVE_ME 4

#define STATE_MOVEING 5 // walking ,running, siddling // MA And a moving bit of furniture!
#define STATE_FDRIVING 6 // furniture drives!!!!!
#define STATE_IDLE 6 // standing,waiting,
#define STATE_LANDING 7
#define STATE_FDOOR 7 // Furniture that is a door...
#define STATE_JUMPING 8
#define STATE_FIGHTING 9
#define STATE_FALLING 10
#define STATE_USE_SCENERY 11
#define STATE_DOWN 12
#define STATE_HIT 13
#define STATE_CHANGE_LOCATION 14 // entering/leaving  buildings/vehicles
#define STATE_DYING 16
#define STATE_DEAD 17
#define STATE_DANGLING 18
#define STATE_CLIMB_LADDER 19
#define STATE_HIT_RECOIL 20
#define STATE_CLIMBING 21
#define STATE_GUN 22
#define STATE_SHOOT 23
#define STATE_DRIVING 24
#define STATE_NAVIGATING 25
#define STATE_WAIT 26
#define STATE_FIGHT 27
#define STATE_STAND_UP 28
#define STATE_MAVIGATING 29
#define STATE_GRAPPLING 30 // Using the grappling hook.
#define STATE_GOTOING 31 // Going to a point with no navigation.
#define STATE_CANNING 32 // Coke-can stuff.
#define STATE_CIRCLING 33 // Circling around someone you're going to attack.
#define STATE_HUG_WALL 34 // Circling around someone you're going to attack.
#define STATE_SEARCH 35 // Circling around someone you're going to attack.
#define STATE_CARRY 36
#define STATE_FLOAT 37 // A person floating in the air!

#define SUB_STATE_WALKING 1
#define SUB_STATE_RUNNING 2
#define SUB_STATE_SIDELING 3
#define SUB_STATE_STOPPING 4
#define SUB_STATE_HOP_BACK 5
#define SUB_STATE_STEP_LEFT 6
#define SUB_STATE_STEP_RIGHT 7
#define SUB_STATE_FLIPING 8
#define SUB_STATE_RUNNING_THEN_JUMP 9
#define SUB_STATE_STOPPING_OT 10
#define SUB_STATE_WALKING_BACKWARDS 16 // must be unique
#define SUB_STATE_RUNNING_SKID_STOP 17
#define SUB_STATE_STOPPING_DEAD 18
#define SUB_STATE_CRAWLING 19
#define SUB_STATE_SNEAKING 20
#define SUB_STATE_STOP_CRAWL 21
#define SUB_STATE_SLIPPING 22 // must be unique
#define SUB_STATE_SLIPPING_END 23 // must be unique
#define SUB_STATE_SIMPLE_ANIM 24
#define SUB_STATE_RUNNING_VAULT 25
#define SUB_STATE_SIMPLE_ANIM_OVER 26
#define SUB_STATE_RUNNING_HIT_WALL 27
#define SUB_STATE_RUNNING_HALF_BLOCK 28
#define SUB_STATE_RUN_STOP 29

#define SUB_STATE_WAITING 11
#define SUB_STATE_WATCHING 12
#define SUB_STATE_SCRATCHING 13

#define SUB_STATE_DROP_LAND 14
#define SUB_STATE_RUNNING_LAND 15
#define SUB_STATE_DEATH_LAND 42

#define SUB_STATE_STANDING_JUMP 30
#define SUB_STATE_STANDING_GRAB_JUMP 31
#define SUB_STATE_RUNNING_JUMP 32
#define SUB_STATE_RUNNING_JUMP_FLY 33
#define SUB_STATE_RUNNING_GRAB_JUMP 34
#define SUB_STATE_RUNNING_JUMP_LAND 35
#define SUB_STATE_RUNNING_JUMP_LAND_FAST 36
#define SUB_STATE_RUNNING_JUMP_FLY_STOP 37
#define SUB_STATE_STANDING_JUMP_FORWARDS 38
#define SUB_STATE_STANDING_JUMP_BACKWARDS 39
#define SUB_STATE_FLYING_KICK 40
#define SUB_STATE_FLYING_KICK_FALL 41

#define SUB_STATE_FLOAT_UP 43
#define SUB_STATE_FLOAT_BOB 44
#define SUB_STATE_FLOAT_DOWN 45

// #define	SUB_STATE_MANOUVER				40

#define SUB_STATE_LATCHING_ON 50
#define SUB_STATE_LATCHING_OFF 51
#define SUB_STATE_VAULTING 52
#define SUB_STATE_CLIMBING 53

#define SUB_STATE_SIDLE 60

#define SUB_STATE_IDLE_CROUTCH 61
#define SUB_STATE_IDLE_CROUTCHING 62
#define SUB_STATE_IDLE_CROUTCH_ARREST 63 // unique?
#define SUB_STATE_IDLE_UNCROUCH 64

#define SUB_STATE_FALLING_NORMAL 0

#define SUB_STATE_PUNCH 90
#define SUB_STATE_KICK 91
#define SUB_STATE_BLOCK 92
#define SUB_STATE_GRAPPLE 93
#define SUB_STATE_GRAPPLEE 94
#define SUB_STATE_WALL_KICK 95
#define SUB_STATE_STEP 96
#define SUB_STATE_STEP_FORWARD 97
#define SUB_STATE_GRAPPLE_HOLD 98
#define SUB_STATE_GRAPPLE_HELD 99 // unique?
#define SUB_STATE_ESCAPE 100
#define SUB_STATE_GRAPPLE_ATTACK 101
#define SUB_STATE_HEADBUTT 102
#define SUB_STATE_STRANGLE 103
#define SUB_STATE_HEADBUTTV 104
#define SUB_STATE_STRANGLEV 105

#define SUB_STATE_ENTERING_VEHICLE 140
#define SUB_STATE_INSIDE_VEHICLE 141
#define SUB_STATE_EXITING_VEHICLE 142

#define SUB_STATE_MOUNTING_BIKE 145
#define SUB_STATE_RIDING_BIKE 146
#define SUB_STATE_DISMOUNTING_BIKE 147

#define SUB_STATE_DEAD_ARREST_TURN_OVER 170
#define SUB_STATE_DEAD_CUFFED 171
#define SUB_STATE_DEAD_ARRESTED 172
#define SUB_STATE_DEAD_INJURED 173
#define SUB_STATE_DEAD_RESPAWN 174

#define SUB_STATE_GRAB_TO_DANGLE 180
#define SUB_STATE_DANGLING 181
#define SUB_STATE_PULL_UP 182
#define SUB_STATE_DROP_DOWN 183
#define SUB_STATE_DROP_DOWN_LAND 184
#define SUB_STATE_DANGLING_CABLE 185
#define SUB_STATE_DANGLING_CABLE_FORWARD 186
#define SUB_STATE_DANGLING_CABLE_BACKWARD 187
#define SUB_STATE_DROP_DOWN_OFF_FACE 188
#define SUB_STATE_DEATH_SLIDE 189
#define SUB_STATE_TRAVERSE_LEFT 190 // who cares
#define SUB_STATE_TRAVERSE_RIGHT 191

#define SUB_STATE_MOUNT_LADDER 192
#define SUB_STATE_ON_LADDER 193
#define SUB_STATE_CLIMB_UP_LADDER 194
#define SUB_STATE_CLIMB_DOWN_LADDER 195
#define SUB_STATE_CLIMB_OFF_LADDER_BOT 196
#define SUB_STATE_CLIMB_OFF_LADDER_TOP 197
#define SUB_STATE_CLIMB_DOWN_ONTO_LADDER 198

#define SUB_STATE_CLIMB_LANDING 210
#define SUB_STATE_CLIMB_AROUND_WALL 211
#define SUB_STATE_CLIMB_UP_WALL 212
#define SUB_STATE_CLIMB_DOWN_WALL 213
#define SUB_STATE_CLIMB_OVER_WALL 214
#define SUB_STATE_CLIMB_OFF_BOT_WALL 215
#define SUB_STATE_CLIMB_LANDING2 216
#define SUB_STATE_CLIMB_LEFT_WALL 217
#define SUB_STATE_CLIMB_RIGHT_WALL 218

#define SUB_STATE_DRAW_GUN 220
#define SUB_STATE_AIM_GUN 221 // must be unique
#define SUB_STATE_SHOOT_GUN 222
#define SUB_STATE_GUN_AWAY 223
#define SUB_STATE_DRAW_ITEM 224
#define SUB_STATE_ITEM_AWAY 225

#define SUB_STATE_DYING_INITIAL_ANI 230
#define SUB_STATE_DYING_FINAL_ANI 231
#define SUB_STATE_DYING_ACTUALLY_DIE 232
#define SUB_STATE_DYING_KNOCK_DOWN 233 // Doesn't die- gets back up again!
#define SUB_STATE_DYING_GET_UP_AGAIN 234
#define SUB_STATE_DYING_PRONE 235 // Falling as a projectile in the middle of dying.
#define SUB_STATE_DYING_KNOCK_DOWN_WAIT 236 // Doesn't die- gets back up again!

#define SUB_STATE_TAKE_HIT 240
#define SUB_STATE_ATTACKING 241
#define SUB_STATE_ACROBATIC 242

#define SUB_STATE_DRIVING_ENTER_CAR 243

#define SUB_STATE_GRAPPLING_PICKUP 244
#define SUB_STATE_GRAPPLING_WINDUP 245
#define SUB_STATE_GRAPPLING_RELEASE 246

#define SUB_STATE_CANNING_PICKUP 247
#define SUB_STATE_CANNING_RELEASE 248
#define SUB_STATE_CANNING_GET_SPECIAL 249 // Bending down to pick up a special rather than a can or head
#define SUB_STATE_CANNING_GET_BARREL 250
#define SUB_STATE_CANNING_GOT_SPECIAL 251

#define SUB_STATE_CIRCLING_CHANGE_POS 150
#define SUB_STATE_CIRCLING_ATTACK 151
#define SUB_STATE_CIRCLING_CIRCLE 152
#define SUB_STATE_CIRCLING_HORROR 153
#define SUB_STATE_CIRCLING_BACK_OFF 154

#define SUB_STATE_HUG_WALL_TURN 156
#define SUB_STATE_HUG_WALL_STAND 157
#define SUB_STATE_HUG_WALL_STEP_LEFT 158
#define SUB_STATE_HUG_WALL_STEP_RIGHT 159

#define SUB_STATE_SEARCH_PRIM 160
#define SUB_STATE_SEARCH_CORPSE 161
#define SUB_STATE_HUG_WALL_LOOK_L 162
#define SUB_STATE_HUG_WALL_LOOK_R 163
#define SUB_STATE_HUG_WALL_LEAP_OUT 164
#define SUB_STATE_SEARCH_GETUP 165

#define SUB_STATE_PICKUP_CARRY 110
#define SUB_STATE_DROP_CARRY 111
#define SUB_STATE_STAND_CARRY 112

#define SUB_STATE_PICKUP_CARRY_V 113
#define SUB_STATE_DROP_CARRY_V 114
#define SUB_STATE_STAND_CARRY_V 115
#define SUB_STATE_CARRY_MOVE_V 116