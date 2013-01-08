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
				CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(gridEvent->m_imageName.c_str());
				initWithTexture(texture);
				setPosition(gridEvent->m_position);
				setAnchorPoint(CCPointZero);
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

}