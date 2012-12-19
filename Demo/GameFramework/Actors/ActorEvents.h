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
			enCreate,
			enRelease,
			enChangePos,
			enStop,
			enAttack,
		};
	};

	struct ActorEventCreate
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enCreate; }

		ActorEventCreate(ENActorType::Decl type) : m_type(type) {}
		ENActorType::Decl GetType(void) const { return m_type; }
	private:
		ENActorType::Decl m_type;
	};

	struct ActorEventRelease
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enRelease; }
	};

	struct ActorEventChangePos
		:public INotifyEvent
	{
		ActorEventChangePos(const cocos2d::CCPoint &worldPos) : m_targetPos(worldPos) {}
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enChangePos; }
		const cocos2d::CCPoint& GetWorldPos(void) const { return m_targetPos; };
	private:
		cocos2d::CCPoint m_targetPos;
	};

	struct ActorEventStop
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enStop; }
	};
	struct ActorEventPlayAttack
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enAttack; }
	};

}


#endif
