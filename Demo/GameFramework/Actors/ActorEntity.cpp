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


namespace Game
{
	struct FrameInfo
	{
		int x;
		int y;
		int width;
		int height;
	};
	struct ImageInfo
	{
		int width;
		int height;
		int row;
		int column;

		const FrameInfo& GetFrameInfo(int index)
		{
			info.width = width / column;
			info.height = height / row;
			info.x = index % column * info.width;
			info.y = index / column * info.height;
			return info;
		}
	private:
		FrameInfo info;
	};
	ActorEntity::ActorEntity(ActorProp *prop)
	:m_currentDirection(enError)
	,m_touchCallBack(NULL)
	,m_imageName(NULL)
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
			case ENActorEvent::enActorEvent_Create:
				{
					const ActorEventCreate *actorEvent = reinterpret_cast<const ActorEventCreate*>(event);
					switch (actorEvent->GetType())
					{
						case ENActorType::enMain:
							m_imageName = "mn.png";
							break;
						default:
							{
								this->setContentSize(cocos2d::CCSizeMake(47, 95));
								cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
								m_touchCallBack = new TouchMonster(reinterpret_cast<ActorProp*>(notify));
								m_imageName = "npc.png";
							}
							break;
					}
					PlayMove(enActorDirection_Down);
				}
				break;
			case ENActorEvent::enActorEvent_Release:
				{

				}
				break;
			case ENActorEvent::enActorEvent_ChangePos:
				{
					const ActorEventChangePos *actorEvent = reinterpret_cast<const ActorEventChangePos*>(event);
					setPosition(actorEvent->GetWorldPos());
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
						WorldManager::Instance()->GetCamera()->SetPosition(getPosition());
					}
				}
				break;
			case ENActorEvent::enActorEvent_UpdateDirection:
				{
					const ActorEventUpdateDirection *actorEvent = reinterpret_cast<const ActorEventUpdateDirection*>(event);
					PlayMove(CalDirection(actorEvent->GetWorldPos(), getPosition()));
				}
                break;
			case ENActorEvent::enActorEvent_Stop:
				{
					PlayMove(enActorDirection_Down);
				}
				break;
			case ENActorEvent::enActorEvent_Attack:
				{
					PlayAttack();
				}
				break;
			case ENActorEvent::enActorEvent_ChangeScaleX:
				{
					const ActorEventChangeScaleX *actorEvent = reinterpret_cast<const ActorEventChangeScaleX*>(event);
					setScaleX(actorEvent->GetXScale());
				}
				break;
			default:
				break;
		}
	}
	void ActorEntity::PlayMove(ENDirection direction)
	{
		if (m_currentDirection == direction)
		{
			return;
		}
		m_currentDirection = direction;
		cocos2d::CCTexture2D *texture = cocos2d::CCTextureCache::sharedTextureCache()->addImage(m_imageName);
		cocos2d::CCArray *frameArray = cocos2d::CCArray::createWithCapacity(4);

		ImageInfo info;
		info.width = texture->getPixelsWide();
		info.height = texture->getPixelsHigh();
		info.row = 4;
		info.column = 4;

		for (int index = 0; index < 4; ++index)
		{
			const FrameInfo &frameInfo = info.GetFrameInfo(index + direction * info.column);
			cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrame::createWithTexture(texture
				, cocos2d::CCRectMake(frameInfo.x, frameInfo.y, frameInfo.width, frameInfo.height));
			frameArray->addObject(frame);
		}
		this->initWithSpriteFrame(reinterpret_cast<cocos2d::CCSpriteFrame*>(frameArray->lastObject()));
		cocos2d::CCAnimation *animation = cocos2d::CCAnimation::createWithSpriteFrames(frameArray, 0.2f);
		cocos2d::CCAnimate *animate = cocos2d::CCAnimate::create(animation);
		cocos2d::CCAction *action = cocos2d::CCRepeatForever::create(animate);
		this->stopActionByTag(enActorAction_PlayAnimation);
		action->setTag(enActorAction_PlayAnimation);
		this->runAction(action);
	}
	void ActorEntity::PlayAttack(void)
	{
		cocos2d::CCTexture2D *texture = cocos2d::CCTextureCache::sharedTextureCache()->addImage("mnattack.png");
		cocos2d::CCArray *frameArray = cocos2d::CCArray::createWithCapacity(8);

		ImageInfo info;
		info.width = texture->getPixelsWide();
		info.height = texture->getPixelsHigh();
		info.row = 3;
		info.column = 5;

		for (int index = 0; index < 8; ++index)
		{
			const FrameInfo &frameInfo = info.GetFrameInfo(index);
			cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrame::createWithTexture(texture
				, cocos2d::CCRectMake(frameInfo.x, frameInfo.y, frameInfo.width, frameInfo.height));
			frameArray->addObject(frame);
		}
		this->initWithSpriteFrame(reinterpret_cast<cocos2d::CCSpriteFrame*>(frameArray->lastObject()));
		cocos2d::CCAnimation *animation = cocos2d::CCAnimation::createWithSpriteFrames(frameArray, 0.2f);
		cocos2d::CCAnimate *animate = cocos2d::CCAnimate::create(animation);
		this->stopActionByTag(enActorAction_PlayAnimation);
		animate->setTag(enActorAction_PlayAnimation);
		this->runAction(animate);
	}
	ActorEntity::ENDirection ActorEntity::CalDirection(const cocos2d::CCPoint &targetPos, const cocos2d::CCPoint &currentPos)
	{
		cocos2d::CCPoint disVec = cocos2d::ccpSub(targetPos, currentPos);
		if (abs(disVec.x) > abs(disVec.y))
		{
			if (disVec.x > 0)
			{
				return enActorDirection_Right;
			}
			else
			{
				return enActorDirection_Left;
			}
		}
		else
		{
			if (disVec.y > 0)
			{
				return enActorDirection_Up;
			}
			else
			{
				return enActorDirection_Down;
			}
		}
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
}