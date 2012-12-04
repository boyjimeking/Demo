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
#include "cocoa/CCGeometry.h"

namespace Game
{
	struct ENActorEvent
	{
		enum
		{
			enNone,
			enActorEvent_Create,
			enActorEvent_Release,
			enActorEvent_ChangePos,
			enActorEvent_UpdateDirection,
		};
	};

	struct ActorEventCreate
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enActorEvent_Create; }

		ActorEventCreate(bool isMain) : m_isMain(isMain) {}

		bool IsMain(void) const { return m_isMain; }
	private:
		bool m_isMain;
	};

	struct ActorEventRelease
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enActorEvent_Release; }
	};

	struct ActorEventChangePos
		:public INotifyEvent
	{
		ActorEventChangePos(const cocos2d::CCPoint &worldPos) : m_targetPos(worldPos) {}
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enActorEvent_ChangePos; }
		const cocos2d::CCPoint& GetWorldPos(void) const { return m_targetPos; };
	private:
		cocos2d::CCPoint m_targetPos;
	};

	struct ActorEventUpdateDirection
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enActorEvent_UpdateDirection; }

		ActorEventUpdateDirection(const cocos2d::CCPoint &targetPos) : m_targetPos(targetPos) {}
		const cocos2d::CCPoint& GetWorldPos(void) const { return m_targetPos; };
	private:
		cocos2d::CCPoint m_targetPos;
	};
}


#endif
