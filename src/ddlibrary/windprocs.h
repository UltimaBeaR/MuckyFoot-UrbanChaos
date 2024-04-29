// WindProcs.h
// Guy Simmons, 14th November 1997.

#pragma once

#include "../mfstdlib/mfstdlib.h"

#include "ddmanager.h"

//---------------------------------------------------------------

struct ChangeDDInfo {
    DDDriverInfo *DriverCurrent,
        *DriverNew;

    D3DDeviceInfo *DeviceCurrent,
        *DeviceNew;

    DDModeInfo *ModeCurrent,
        *ModeNew;
};

//---------------------------------------------------------------

LRESULT CALLBACK DDLibShellProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//---------------------------------------------------------------
