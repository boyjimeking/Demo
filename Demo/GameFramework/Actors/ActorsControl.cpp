#include "ActorsControl.h"
#include "ActorProp.h"
#include "ActorsControlEvents.h"

namespace Game
{
	ActorsControl::ActorsControl(void)
	{

	}
	ActorsControl::~ActorsControl(void)
	{
		ClearActor();
	}
	bool ActorsControl::CreateActor(int actorID)
	{
		ActorMap::iterator it = m_actorMap.find(actorID);
		if (m_actorMap.end() != it)
		{
			//Already have.
			return false;
		}
		ActorProp *actor = new ActorProp;
		ActorEntity *entity = actor->Create();
		if (NULL == entity)
		{
			//Create error.
			delete actor;
			return false;
		}
		m_actorMap.insert(std::make_pair(actorID, actor));

		ActorsControlEventCreateActor event(entity);
		NotifyChange(&event);
		return false;
	}
	void ActorsControl::ReleaseActor(int actorID)
	{
		ActorMap::iterator it = m_actorMap.find(actorID);
		if (m_actorMap.end() != it)
		{
			/* code */
			it->second->Release();
			delete it->second;
			m_actorMap.erase(it);

			ActorsControlEventReleaseActor event;
			NotifyChange(&event);
		}
		else
		{
			//Can not find actor.
		}
	}
	void ActorsControl::ClearActor(void)
	{
		for (ActorMap::iterator it = m_actorMap.begin(); m_actorMap.end() != it; ++it)
		{
			/* code */
			it->second->Release();
			delete it->second;
		}
		m_actorMap.clear();

		ActorsControlEventReleaseAll event;
		NotifyChange(&event);
	}
	ActorProp* ActorsControl::GetMainActor(void) const
	{
		return LookupActor(1);
	}
	ActorProp* ActorsControl::LookupActor(int actorID) const
	{
		ActorMap::const_iterator it = m_actorMap.find(actorID);
		if (m_actorMap.end() != it)
		{
			return it->second;
		}
		else
		{
			return NULL;
		}
	}
}