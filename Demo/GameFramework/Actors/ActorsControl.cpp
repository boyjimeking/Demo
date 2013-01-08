#include "ActorsControl.h"
#include "ActorProp.h"
#include "ActorsControlEvents.h"
#include "support/CCPointExtension.h"
#include "ActorEntity.h"

namespace Game
{
	ActorsControl::ActorsControl(void)
	{

	}
	ActorsControl::~ActorsControl(void)
	{
		ClearActor();
	}
	ActorProp* ActorsControl::CreateActor(ENActorType::Decl type, int actorID, float x, float y)
	{
		ActorMap::iterator it = m_actorMap.find(actorID);
		if (m_actorMap.end() != it)
		{
			//Already have.
			return NULL;
		}
		ActorProp *actor = new ActorProp(type, actorID);
		ActorEntity *entity = ActorEntity::Create();
		if (NULL == entity)
		{
			//Create error.
			delete actor;
			return NULL;
		}
		ActorsControlEventCreateActor event(entity);
		NotifyChange(&event);

		actor->AttachObserver(entity);
		actor->Init();
		actor->SetPosition(ccp(x, y));
		actor->Stop();
		m_actorMap.insert(std::make_pair(actorID, actor));
		return actor;
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
	void ActorsControl::Tick(float dt)
	{
		for (ActorMap::iterator it = m_actorMap.begin(); it != m_actorMap.end(); ++it)
		{
			it->second->Tick(dt);
		}
	}
	float ActorsControl::Distance(const ActorProp *firstActor, const ActorProp *secondActor)
	{
		return ccpDistance(firstActor->GetPosition(), secondActor->GetPosition());
	}
}