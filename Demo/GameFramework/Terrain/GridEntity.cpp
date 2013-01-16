//
//  GridEntity.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#include "GridEntity.h"
#include "GridEvents.h"
#include "textures/CCTextureCache.h"
#include "WorldManager.h"
#include "Camera/Camera.h"
#include "cocoa/CCObject.h"

USING_NS_CC;
namespace Game
{
	GridEntity::GridEntity(void)
	{

	}
	GridEntity::~GridEntity(void)
	{

	}

	void GridEntity::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		if (NULL == event)
		{
			return;
		}
		switch (event->GetNotifyEventType())
		{
		case ENGridEventType::enInitGrid:
			{
				setScale(WorldManager::Instance()->GetCamera()->GetObjectScale());
				const GridEventInit *gridEvent = reinterpret_cast<const GridEventInit*>(event);
				init();
				setPosition(gridEvent->m_position);
				cocos2d::CCTextureCache::sharedTextureCache()->addImageAsync(gridEvent->m_imageName.c_str(), this, callfuncO_selector(GridEntity::OnImageLoaded));
			}
			break;
		case ENGridEventType::enRemoveGrid:
			{
				getParent()->removeChild(this, true);
			}
			break;
		default:
			break;
		}
	}

	void GridEntity::OnImageLoaded( cocos2d::CCObject *obj )
	{
		initWithTexture(reinterpret_cast<cocos2d::CCTexture2D*>(obj));
		setAnchorPoint(cocos2d::CCPointZero);
	}

}