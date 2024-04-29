// Editor.hpp
// Guy Simmons, 18th February 1997.

#pragma once

#include "../mfstdlib/mfstdlib.h"

#include "editorlib.h"
#pragma warning(disable : 4244)
#include "map.h"
#include "edit.h"

#define EDITOR_NORMAL (1 << 0)
#define EDITOR_RECORD (1 << 1)

extern UBYTE editor_status;

UBYTE editor_loop(void);

#define ShowWorkScreen(f) editor_show_work_screen(f)
#define ShowWorkWindow(f) editor_show_work_window(f)

#define LOAD_SHARED_TEXTURES (1 << 0)
#define LOAD_UNSHARED_TEXTURES (1 << 1)
#define LOAD_ALL_TEXTURES (3)

#define FREE_SHARED_TEXTURES (1 << 0)
#define FREE_UNSHARED_TEXTURES (1 << 1)
#define FREE_ALL_TEXTURES (3)

extern void load_game_textures(UBYTE flags);
extern void free_game_textures(UBYTE flags);
