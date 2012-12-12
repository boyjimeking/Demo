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
#include "Buildings/SceneControl.h"
#include "CCDrawingPrimitives.h"
#include "ccTypes.h"

namespace Game
{
	TerrainLayer* TerrainLayer::create( void )
	{
		TerrainLayer *pRet = new TerrainLayer();
		if (pRet && pRet->init())
		{
			pRet->setTouchEnabled(true);
			pRet->setAnchorPoint(cocos2d::CCPointMake(0.0f, 0.0f));
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
						entity->setAnchorPoint(cocos2d::CCPointMake(0.0f, 0.0f));
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
		cocos2d::CCPoint worldPos = WorldManager::DesignPosToWorld(screenPos);
		mainActor->MoveTo(worldPos);
	}
#ifdef _ShowGrid_
	void TerrainLayer::draw()
	{
		SceneControl *scene = WorldManager::Instance()->GetSceneControl();
		for (int index = 0; index < scene->GetRow() ; ++index)
		{
			for (int innerIndex = 0; innerIndex < scene->GetColumn(); ++innerIndex)
			{
				if (scene->GetGrid(innerIndex, index))
				{
					cocos2d::ccDrawSolidRect(cocos2d::CCPointMake(innerIndex * scene->GetGridSize(), index * scene->GetGridSize())
                                             , cocos2d::CCPointMake((innerIndex + 1) * scene->GetGridSize() - 1, (index + 1) * scene->GetGridSize() - 1), cocos2d::ccc4f(0.0f, 0.0f, 1.0f, 1.0f));
				}
                else
                {
                    cocos2d::ccDrawSolidRect(cocos2d::CCPointMake(innerIndex * scene->GetGridSize(), index * scene->GetGridSize())
                                             , cocos2d::CCPointMake((innerIndex + 1) * scene->GetGridSize() - 1, (index + 1) * scene->GetGridSize() - 1), cocos2d::ccc4f(1.0f, 0.0f, 0.0f, 1.0f));
                }
			}
		}
	}
#endif
}

