//
//  ActorEvents.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#ifndef Demo_ActorEvents_h
#define Demo_ActorEvents_h

#include "Base/INotifyEvent.h"

struct ENActorEvent
{
	enum
	{
		enNone,
		enActorEvent_Create,
		enActorEvent_Release,
	};
};

struct ActorEventCreate
	:public INotifyEvent
{
	virtual int GetNotifyEventType(void) const { return ENActorEvent::enActorEvent_Create; }
};

struct ActorEventRelease
	:public INotifyEvent
{
	virtual int GetNotifyEventType(void) const { return ENActorEvent::enActorEvent_Release; }
};

#endif
