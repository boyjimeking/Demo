#include "ActorProp.h"
#include "ActorEvents.h"
#include "ActorEntity.h"

namespace Game
{
	ActorProp::ActorProp(void)
	{

	}
	ActorProp::~ActorProp(void)
	{

	}

	ActorEntity* ActorProp::Create(void)
	{
		ActorEntity *entity = new ActorEntity;
		entity->init();
		AttachObserver(entity);

		ActorEventCreate event;
		NotifyChange(&event);
		return entity;
	}

	void ActorProp::Release(void)
	{
		ActorEventRelease event;
		NotifyChange(&event);
	}
	void ActorProp::SetPosition(const cocos2d::CCPoint &pos)
	{
		if (m_position.equals(pos))
		{
			return;
		}
		m_position = pos;
		ActorEventChangePos event(pos);
		NotifyChange(&event);
	}
	void ActorProp::MoveTo(const cocos2d::CCPoint &pos)
	{
		SetPosition(pos);
	}
}