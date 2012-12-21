#include "ActorEntity.h"
#include "ActorEvents.h"
#include "textures/CCTextureCache.h"
#include "sprite_nodes/CCSpriteFrame.h"
#include "sprite_nodes/CCAnimation.h"
#include "cocoa/CCGeometry.h"
#include "cocoa/CCArray.h"
#include "actions/CCActionInterval.h"
#include "CCDirector.h"
#include "support/CCPointExtension.h"
#include "WorldManager.h"
#include "../Camera/Camera.h"
#include "CCDirector.h"
#include "touch_dispatcher/CCTouchDispatcher.h"
#include "ActorProp.h"
#include "ActorTouch.h"
#include "sprite_nodes/CCSpriteFrameCache.h"


namespace Game
{
	char* strDirection[] = 
	{
		"e",
		"en",
		"n",
		"wn",
		"w",
		"ws",
		"s",
		"es"
	};

	ActorEntity::ActorEntity(ActorProp *prop)
	:m_currentDirection(enError)
	,m_touchCallBack(NULL)
	,m_currentAction(ENAction::enIdle)
	{
		
	}
	ActorEntity::~ActorEntity(void)
	{

	}

	void ActorEntity::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		if (NULL == event)
		{
			return;
		}
		switch (event->GetNotifyEventType())
		{
			case ENActorEvent::enCreate:
				{
					setScale(WorldManager::Instance()->GetCamera()->GetObjectScale());
					setAnchorPoint(cocos2d::CCPointMake(0.0f, 0.0f));
					const ActorEventCreate *actorEvent = reinterpret_cast<const ActorEventCreate*>(event);
					switch (actorEvent->GetType())
					{
					case ENActorType::enMain:
						cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("MainRun.plist");
						m_actionTable[ENAction::enIdle] = "1_0_w_0_0_standby_0_%s_%d.png";
						m_actionTable[ENAction::enMove] = "1_0_w_0_0_run_0_%s_%d.png";
						m_actionTable[ENAction::enAttack] = "1_0_w_0_0_attack_0_%s_%d.png";
						break;
					default:
						{
							this->setContentSize(cocos2d::CCSizeMake(47, 95));
							cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
							m_touchCallBack = new TouchMonster(reinterpret_cast<ActorProp*>(notify));
							cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("NPCRun.plist");
							m_actionTable[ENAction::enIdle] = "2_yuanhun_w_idle_0_%s_%d.png";
							m_actionTable[ENAction::enMove] = "2_yuanhun_w_run_0_%s_%d.png";
							m_actionTable[ENAction::enAttack] = "2_yuanhun_w_attack_0_%s_%d.png";
						}
						break;
					}
					PlayAnimation(ENAction::enIdle, enDirection_South);
				}
				break;
			case ENActorEvent::enRelease:
				{
					getParent()->removeChild(this, true);
				}
				break;
			case ENActorEvent::enChangePos:
				{
					const ActorEventChangePos *actorEvent = reinterpret_cast<const ActorEventChangePos*>(event);
					cocos2d::CCPoint newPos = WorldManager::LogicToPoint(actorEvent->GetLogicPos());
					PlayAnimation(ENAction::enMove, CalDirection(newPos, getPosition()));
					setPosition(newPos);
					if (NULL != this->getParent())
					{
						this->getParent()->reorderChild(this, -getPosition().y);
					}
					else
					{
						_setZOrder(-getPosition().y);
					}
					if (ENActorType::enMain == reinterpret_cast<const ActorProp*>(notify)->GetType())
					{
						WorldManager::Instance()->GetCamera()->SetPosition(actorEvent->GetLogicPos());
					}
				}
				break;
			case ENActorEvent::enStop:
				{
					PlayAnimation(ENAction::enIdle, m_currentDirection);
				}
				break;
			case ENActorEvent::enAttack:
				{
					PlayAnimation(ENAction::enAttack, m_currentDirection);
				}
				break;
			default:
				break;
		}
	}
	ActorEntity::ENDirection ActorEntity::CalDirection(const cocos2d::CCPoint &targetPos, const cocos2d::CCPoint &currentPos)
	{
		float angle = ccpToAngle(cocos2d::ccpSub(targetPos, currentPos));

		static const float M_PI_8 = (float)M_PI / 8.0f;

		if (abs(angle) < M_PI_8)
		{
			return enDirection_East;
		}
		if (M_PI_8 < angle && angle < M_PI_8 * 3)
		{
			return enDirection_NorthEast;
		}
		if (M_PI_8 * 3 < angle && angle < M_PI_8 * 5)
		{
			return enDirection_North;
		}
		if (M_PI_8 * 5 < angle && angle < M_PI_8 * 7)
		{
			return enDirection_NorthWest;
		}
		if (abs(angle) > M_PI_8 * 7)
		{
			return enDirection_West;
		}
		if (M_PI_8 * -5 > angle && angle > M_PI_8 * -7)
		{
			return enDirection_SouthWest;
		}
		if (M_PI_8 * -3 > angle && angle > M_PI_8 * -5)
		{
			return enDirection_South;
		}
		if (-M_PI_8 > angle && angle > M_PI_8 * -3)
		{
			return enDirection_SouthEast;
		}
		return enDirection_East;
	}
	void ActorEntity::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
	{
		
	}
	bool ActorEntity::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
	{
		cocos2d::CCPoint local = WorldManager::DesignPosToWorld(pTouch->getLocation());
		cocos2d::CCRect rect = cocos2d::CCRectMake( m_tPosition.x - m_tContentSize.width * m_tAnchorPoint.x, 
                      m_tPosition.y - m_tContentSize.height * m_tAnchorPoint.y,
                      m_tContentSize.width, m_tContentSize.height);
		if (rect.containsPoint(local))
		{
			return m_touchCallBack->OnTouch(local);
		}
		else
		{
			return false;
		}
	}

	void ActorEntity::PlayAnimation( ENAction::Type type, ENDirection direction )
	{
		if (m_currentDirection == direction && m_currentAction == type)
		{
			return;
		}
		m_currentDirection = direction;
		m_currentAction = type;
		cocos2d::CCArray *frameArray = cocos2d::CCArray::createWithCapacity(4);

		for (int index = 0; index < 4; ++index)
		{
			char buff[64];
			sprintf(buff, m_actionTable[type], strDirection[direction], index + 1);
			cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(buff);
			frameArray->addObject(frame);
		}
		this->initWithSpriteFrame(reinterpret_cast<cocos2d::CCSpriteFrame*>(frameArray->lastObject()));
		setAnchorPoint(cocos2d::CCPointMake(0.5f, 0.3f));
		cocos2d::CCAnimation *animation = cocos2d::CCAnimation::createWithSpriteFrames(frameArray, 0.2f);
		cocos2d::CCAnimate *animate = cocos2d::CCAnimate::create(animation);
		cocos2d::CCAction *action = cocos2d::CCRepeatForever::create(animate);
		this->stopActionByTag(enActorAction_PlayAnimation);
		action->setTag(enActorAction_PlayAnimation);
		this->runAction(action);
	}

}