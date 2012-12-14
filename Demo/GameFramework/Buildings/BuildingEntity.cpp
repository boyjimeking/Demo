#include "BuildingEntity.h"
#include "BuildingEvents.h"
#include "sprite_nodes/CCSpriteFrameCache.h"

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
			case ENBuildingEvent::enCreate:
				{
					this->setAnchorPoint(cocos2d::CCPointMake(0.0f, 0.0f));
					const BuildingEventCreate *createEvent = reinterpret_cast<const BuildingEventCreate*>(event);
					setPosition(cocos2d::CCPointMake(createEvent->GetX(), createEvent->GetY()));
					cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(createEvent->GetImageName().c_str());
					setDisplayFrame(frame);
				}
				break;
			default:
				break;
		}
	}
}