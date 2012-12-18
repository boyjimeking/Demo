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
		case ENSceneObjectEvent::enInitObject:
			{
				const SceneObjectEventInit *objectEvent = reinterpret_cast<const SceneObjectEventInit*>(event);
				cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(objectEvent->m_imageName.c_str());
				setDisplayFrame(frame);
				setPosition(objectEvent->m_position);
				setContentSize(objectEvent->m_size);
				setAnchorPoint(cocos2d::CCPointZero);
				if (NULL != getParent())
				{
					getParent()->reorderChild(this, -getPosition().y);
				}
				else
				{
					_setZOrder(-getPosition().y);
				}
			}
			break;
		case ENSceneObjectEvent::enRemoveObject:
			{
				getParent()->removeChild(this, true);
			}
			break;
		default:
			break;
		}
	}
}