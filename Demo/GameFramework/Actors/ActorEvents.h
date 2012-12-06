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
#include "Base/GlobalDef.h"

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
			enActorEvent_Stop,
			enActorEvent_Attack,
			enActorEvent_ChangeScaleX,
		};
	};

	struct ActorEventCreate
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enActorEvent_Create; }

		ActorEventCreate(ENActorType::Decl type) : m_type(type) {}
		ENActorType::Decl GetType(void) const { return m_type; }
	private:
		ENActorType::Decl m_type;
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
	struct ActorEventStop
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enActorEvent_Stop; }
	};
	struct ActorEventPlayAttack
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enActorEvent_Attack; }
	};
	struct ActorEventChangeScaleX
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enActorEvent_ChangeScaleX; }
		ActorEventChangeScaleX(int xScale) : m_xScale(xScale) {}
		int GetXScale(void) const { return m_xScale; }
	private:
		int m_xScale;
	};
}


#endif
