#include "SceneObjectEntity.h"
#include "SceneObjectEvents.h"
#include "sprite_nodes/CCSpriteFrameCache.h"

namespace Game
{
	SceneObjectEntity* SceneObjectEntity::Create(void)
	{
		SceneObjectEntity *entity = new SceneObjectEntity();
	    if (entity && entity->init())
	    {
	        entity->autorelease();
	        return entity;
	    }
	    CC_SAFE_DELETE(entity);
	    return NULL;
	}
	SceneObjectEntity::SceneObjectEntity(void)
	{

	}
	SceneObjectEntity::~SceneObjectEntity(void)
	{

	}
	void SceneObjectEntity::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		switch (event->GetNotifyEventType())
		{
			case ENSceneObjectEvent::enCreate:
				{
					this->setAnchorPoint(cocos2d::CCPointMake(0.0f, 0.0f));
					const SceneObjectEventCreate *createEvent = reinterpret_cast<const SceneObjectEventCreate*>(event);
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