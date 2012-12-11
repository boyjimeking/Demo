#include "BuildingEntity.h"
#include "BuildingEvents.h"

namespace Game
{
	BuildingEntity* BuildingEntity::Create(void)
	{
		BuildingEntity *entity = new BuildingEntity();
	    if (entity && entity->init())
	    {
	        entity->autorelease();
	        return entity;
	    }
	    CC_SAFE_DELETE(entity);
	    return NULL;
	}
	BuildingEntity::BuildingEntity(void)
	{

	}
	BuildingEntity::~BuildingEntity(void)
	{

	}
	void BuildingEntity::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		switch (event->GetNotifyEventType())
		{
			case ENBuildingEvent::enBuildingEvent_Create:
				{
					
				}
				break;
			default:
				break;
		}
	}
}