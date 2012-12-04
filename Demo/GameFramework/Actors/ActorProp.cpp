#include "ActorProp.h"
#include "ActorEvents.h"
#include "ActorEntity.h"
#include "Physical/PhysicalObj.h"

namespace Game
{
	ActorProp::ActorProp(void)
	:m_physicalObj(NULL)
	,m_isMain(false)
	{

	}
	ActorProp::~ActorProp(void)
	{

	}

	ActorEntity* ActorProp::Create(void)
	{
		m_physicalObj = new PhysicalObj;
		m_physicalObj->SetPositionFunc(boost::bind(&ActorProp::SetPosition, this, _1));

		ActorEntity *entity = new ActorEntity;
		entity->init();
		AttachObserver(entity);

		ActorEventCreate event(m_isMain);
		NotifyChange(&event);
		return entity;
	}

	void ActorProp::Release(void)
	{
		ActorEventRelease event;
		NotifyChange(&event);
	}
	void ActorProp::MoveTo(const cocos2d::CCPoint &pos)
	{
		m_physicalObj->Move(m_position, pos);
		
		ActorEventUpdateDirection event(pos);
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
}