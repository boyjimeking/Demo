#include "TerrainLayer.h"
#include "../Base/INotifier.h"
#include "support/CCPointExtension.h"
#include "sprite_nodes/CCSprite.h"
#include "CCDirector.h"
#include "TerrainEvent.h"
#include "WorldManager.h"
#include "Actors/ActorProp.h"
#include "Actors/ActorsControl.h"
#include "Camera/Camera.h"
#include "GridEntity.h"
#include "Actors/ActorAction.h"

namespace Game
{
	TerrainLayer::TerrainLayer(void)
	{

	}
	TerrainLayer::~TerrainLayer(void)
	{
		
	}

	void TerrainLayer::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		if (NULL == event)
		{
			return;
		}
		switch (event->GetNotifyEventType())
		{
		case ENTerrainEventType::enAddTerrain:
			{
				const TerrainEvent_AddTerrain *terrainEvent = reinterpret_cast<const TerrainEvent_AddTerrain*>(event);
				cocos2d::CCLayer *layer = WorldManager::Instance()->LookupLayer(terrainEvent->m_layerName);
				if (NULL != layer)
				{
					layer->addChild(terrainEvent->m_eneity);
				}
			}
			break;
		default:
			break;
		}
	}

}

