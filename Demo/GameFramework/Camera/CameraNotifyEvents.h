//
//  CameraNotifyEvents.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#ifndef Demo_CameraNotifyEvents_h
#define Demo_CameraNotifyEvents_h

#include "Base/INotifyEvent.h"

struct ENCameraEvent
{
	enum
	{
		enNone,
		enCameraEvent_Inited,
	};
};

struct CameraInited
	:public INotifyEvent
{
	virtual int GetNotifyEventType(void) const { return ENCameraEvent::enCameraEvent_Inited; }
};

#endif
