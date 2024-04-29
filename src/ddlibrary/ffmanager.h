// FFManager.h
// 18th Sept 98
//
// Limitations: Currently assumes first joystick

#pragma once

#include "../mfstdlib/mfstdlib.h"

#include "dimanager.h"

#if 0

PC doesn't have DIDeviceInfo's any more

class FFManager {
	private:
	  SLONG  ForceFeedback;
	  LPDIRECTINPUTEFFECT testeffect;
	  DIDeviceInfo* DeviceInfo;
	  LPDIRECTINPUTDEVICE2	lpdiInputDevice;			// DI Device.
	public:
		FFManager();
		~FFManager();
		
		BOOL FFSupported(LPDIRECTINPUTDEVICE2 device);
		void ReleaseFX();
		BOOL Test();
};

extern FFManager* the_ff_manager;

#endif
