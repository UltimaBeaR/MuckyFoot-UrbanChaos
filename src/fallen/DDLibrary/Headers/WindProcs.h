// WindProcs.h
// Guy Simmons, 14th November 1997.

#pragma once

#include "DDManager.h"

//---------------------------------------------------------------

typedef struct
{
    DDDriverInfo *DriverCurrent,
        *DriverNew;

    D3DDeviceInfo *DeviceCurrent,
        *DeviceNew;

    DDModeInfo *ModeCurrent,
        *ModeNew;
} ChangeDDInfo;

//---------------------------------------------------------------

LRESULT CALLBACK DDLibShellProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//---------------------------------------------------------------

