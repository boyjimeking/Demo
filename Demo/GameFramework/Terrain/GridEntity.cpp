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
			case ENGridEventType::enLoad:
				{
					const GridEvent_Load *loadEvent = reinterpret_cast<const GridEvent_Load*>(event);
					Load(loadEvent->GetImageName(), loadEvent->GetPosX(), loadEvent->GetPosY());
				}
				break;
			case ENGridEventType::enRelease:
				{
					getParent()->removeChild(this, true);
				}
				break;
			default:
				break;
		}
	}

	void GridEntity::Load(const char *imageName, float posX, float posY)
	{
		setAnchorPoint(cocos2d::CCPointMake(0.0f, 0.0f));
        cocos2d::CCTexture2D *texture = cocos2d::CCTextureCache::sharedTextureCache()->addImage(imageName);
		initWithTexture(texture);
		setPositionX(posX);
		setPositionY(posY);
	}
}