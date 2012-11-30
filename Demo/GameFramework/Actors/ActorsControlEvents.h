//
//  ActorsControlEvents.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#ifndef Demo_ActorsControlEvents_h
#define Demo_ActorsControlEvents_h

#include "Base/INotifyEvent.h"

namespace Game
{

	struct ENActorsControlEvents
	{
		enum
		{
			enNone,
			enActorsControlEvent_CreateActor,
			enActorsControlEvent_ReleaseActor,
			enActorsControlEvent_ReleaseAll,
		};
	};

	class ActorEntity;
	struct ActorsControlEventCreateActor
		:public INotifyEvent
	{
		ActorsControlEventCreateActor(ActorEntity *entity);
		/* data */
		virtual int GetNotifyEventType(void) const { return ENActorsControlEvents::enActorsControlEvent_CreateActor; }
		ActorEntity* GetActorEntity(void) const { return m_entity; }
	private:
		ActorEntity *m_entity;
	};

	struct ActorsControlEventReleaseActor
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorsControlEvents::enActorsControlEvent_ReleaseActor; }
	};

	struct ActorsControlEventReleaseAll
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorsControlEvents::enActorsControlEvent_ReleaseAll; }
	};
}

#endif
