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

	void GridEntity::OnNotifyChange( const INotifier *notify, const INotifyEvent *event )
	{
		if (NULL == event)
		{
			return;
		}
		switch (event->GetNotifyEventType())
		{
			case ENGridEventType::enGridEvent_Load:
				{
					const GridEvent_Load *loadEvent = reinterpret_cast<const GridEvent_Load*>(event);
					Load(loadEvent->GetImageName(), loadEvent->GetWidth(), loadEvent->GetHeight(), loadEvent->GetPosX(), loadEvent->GetPosY());
				}
				break;
			default:
				break;
		}
	}

	void GridEntity::Load(const char *imageName, int width, int height, int posX, int posY)
	{
        cocos2d::CCTexture2D *texture = cocos2d::CCTextureCache::sharedTextureCache()->addImage(imageName);
		initWithTexture(texture);
		setPositionX(posX);
		setPositionY(posY);
	}
}