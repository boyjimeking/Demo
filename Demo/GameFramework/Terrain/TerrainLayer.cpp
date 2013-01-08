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
	TerrainLayer* TerrainLayer::create( void )
	{
		TerrainLayer *pRet = new TerrainLayer();
		if (pRet && pRet->init())
		{
			pRet->setTouchEnabled(true);
			pRet->autorelease();
			return pRet;
		}
		else
		{
			CC_SAFE_DELETE(pRet);
			return NULL;
		}
	}

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
				addChild(terrainEvent->m_eneity);
			}
			break;
		default:
			break;
		}
	}
	void TerrainLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
	{
		CCLayer::ccTouchesBegan(pTouches, pEvent);
		CCTouch *touch = reinterpret_cast<CCTouch*>(*pTouches->begin());
		CCPoint pos = touch->getLocation();
		//什么都没点到的时候，主角移动
		ProcessMainActorMove(pos);
	}
	void TerrainLayer::ProcessMainActorMove(const CCPoint &screenPos)
	{
		ActorProp *mainActor = WorldManager::Instance()->GetActorsControl()->GetMainActor();
		CCPoint worldPos = WorldManager::DesignPosToWorld(screenPos);
		mainActor->MoveTo(worldPos);
	}

}

