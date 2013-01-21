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
		ActorProp *prop = LookupActor(actorID);
		if (NULL != prop)
		{
			return prop;
		}
		ActorProp *actor = new ActorProp(type, actorID);
		ActorEntity *entity = ActorEntity::Create();
		if (NULL == entity)
		{
			//Create error.
			delete actor;
			return NULL;
		}
		ActorsControlEventCreateActor event(entity, "default");
		NotifyChange(&event);

		actor->AttachObserver(entity);
		actor->Init();
		actor->SetPosition(ccp(x, y));
		actor->Stop();
		m_actorMap.push_back(std::make_pair(actorID, actor));
		return actor;
	}
	void ActorsControl::ReleaseActor(int actorID)
	{
		for (int index = 0; index < m_actorMap.size(); ++index)
		{
			if (m_actorMap[index].first == actorID)
			{
				ActorProp *prop = m_actorMap[index].second;
				prop->Release();
				delete prop;

				ActorsControlEventReleaseActor event;
				NotifyChange(&event);
				break;
			}
		}
	}
	void ActorsControl::ClearActor(void)
	{
		for (int index = 0; index < m_actorMap.size(); ++index)
		{
			ActorProp *prop = m_actorMap[index].second;
			prop->Release();
			delete prop;
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
		for (int index = 0; index < m_actorMap.size(); ++index)
		{
			if (m_actorMap[index].first == actorID)
			{
				return m_actorMap[index].second;
			}
		}
		return NULL;
	}
	void ActorsControl::Tick(float dt)
	{
		for (int index = 0; index < m_actorMap.size(); ++index)
		{
			m_actorMap[index].second->Tick(dt);
		}
	}
	float ActorsControl::Distance(const ActorProp *firstActor, const ActorProp *secondActor)
	{
		return cocos2d::ccpDistance(firstActor->GetPosition(), secondActor->GetPosition());
	}

	void ActorsControl::PickupActor( const cocos2d::CCPoint &worldPos )
	{

	}

}