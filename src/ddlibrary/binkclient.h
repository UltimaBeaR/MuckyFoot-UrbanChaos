// BinkClient.h
//
// simple client for BINK file playback

#pragma once

#include "../mfstdlib/mfstdlib.h"

extern void BinkPlay(const char* filename, IDirectDrawSurface* lpdds, bool (*flip)());

extern void BinkMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
