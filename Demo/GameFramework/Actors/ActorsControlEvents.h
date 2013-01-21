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
			enCreateActor,
			enReleaseActor,
			enReleaseAll,
		};
	};

	class ActorEntity;
	struct ActorsControlEventCreateActor
		:public INotifyEvent
	{
		ActorsControlEventCreateActor(ActorEntity *entity, const char *layerName);
		/* data */
		virtual int GetNotifyEventType(void) const { return ENActorsControlEvents::enCreateActor; }
		ActorEntity* GetActorEntity(void) const { return m_entity; }
		const char* GetLayerName(void) const { return m_layerName; }
	private:
		ActorEntity *m_entity;
		const char *m_layerName;
	};

	struct ActorsControlEventReleaseActor
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorsControlEvents::enReleaseActor; }
	};

	struct ActorsControlEventReleaseAll
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorsControlEvents::enReleaseAll; }
	};
}

#endif
