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
			case ENTerrainEventType::enTerrainEvent_LoadTerrain:
				{
					const TerrainEvent_LoadTerrain *loadEvent = reinterpret_cast<const TerrainEvent_LoadTerrain*>(event);
					for (int index = 0; index < loadEvent->GetLength(); ++index)
					{
						GridEntity *entity = loadEvent->GetEntity(index);
						this->addChild(entity);
					}
				}
				break;
			default:
				break;
		}
	}

	void TerrainLayer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
	{
		cocos2d::CCLayer::ccTouchesBegan(pTouches, pEvent);
		cocos2d::CCTouch *touch = reinterpret_cast<cocos2d::CCTouch*>(*pTouches->begin());
		cocos2d::CCPoint pos = touch->getLocation();
		//什么都没点到的时候，主角移动
		ProcessMainActorMove(pos);
		// static int actorCount = 1;
		// for (int index = 0; index < 10; ++index)
		// {
		// 	cocos2d::CCLog("actorCount: %d", actorCount);
		// 	WorldManager::Instance()->GetActorsControl()->CreateActor(++actorCount);
		// }
	}
	void TerrainLayer::ProcessMainActorMove(const cocos2d::CCPoint &screenPos)
	{
		ActorProp *mainActor = WorldManager::Instance()->GetActorsControl()->GetMainActor();
		cocos2d::CCPoint worldPos = WorldManager::ScreenPosToWorld(screenPos);
		mainActor->MoveTo(worldPos);
	}
}

