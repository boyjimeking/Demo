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
#include "ActorActions.h"


namespace Game
{
	const float AnimationData[4/*动作ID*/][4/*动作帧序列*/][2/*(x,y)*/] = 
		{
			{ {0,0}, {47,0}, {94,0}, {141,0} },
			{ {0,95}, {47,95}, {94,95}, {141,95} },
			{ {0,190}, {47,190}, {94,190}, {141,190} },
			{ {0,285}, {47,285}, {94,285}, {141,285} }
		};
	ActorEntity::ActorEntity(void)
	{

	}
	ActorEntity::~ActorEntity(void)
	{

	}

	void ActorEntity::OnNotifyChange( const INotifier *notify, const INotifyEvent *event )
	{
		if (NULL == event)
		{
			return;
		}
		switch (event->GetNotifyEventType())
		{
			case ENActorEvent::enActorEvent_Create:
				{
					PlayAnimation(enActorDirection_Down);
					cocos2d::CCSize visibleSize = cocos2d::CCDirector::sharedDirector()->getVisibleSize();
					this->setPosition(cocos2d::CCPointZero);
				}
				break;
			case ENActorEvent::enActorEvent_Release:
				{

				}
				break;
			case ENActorEvent::enActorEvent_ChangePos:
				{
					const ActorEventChangePos *actorEvent = reinterpret_cast<const ActorEventChangePos*>(event);
					MoveTo(actorEvent->GetWorldPos());
				}
				break;
			default:
				break;
		}
	}
	void ActorEntity::PlayAnimation(ENDirection direction)
	{
		cocos2d::CCTexture2D *texture = cocos2d::CCTextureCache::sharedTextureCache()->addImage("actor.png");
		cocos2d::CCArray *frameArray = cocos2d::CCArray::createWithCapacity(4);
		//width:47 height:95
		static const int FrameWidth = 47;
		static const int FrameHeight = 95;
		for (int index = 0; index < 4; ++index)
		{
			cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrame::createWithTexture(texture
				, cocos2d::CCRectMake(AnimationData[direction][index][0]
									, AnimationData[direction][index][1]
									, FrameWidth
									, FrameHeight));
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
	void ActorEntity::MoveTo(const cocos2d::CCPoint &worldPos)
	{
		this->stopActionByTag(enActorAction_MoveTo);
		cocos2d::CCPoint disVec = cocos2d::ccpSub(worldPos, getPosition());
		if (abs(disVec.x) > abs(disVec.y))
		{
			if (disVec.x > 0)
			{
				PlayAnimation(enActorDirection_Right);
			}
			else
			{
				PlayAnimation(enActorDirection_Left);
			}
		}
		else
		{
			if (disVec.y > 0)
			{
				PlayAnimation(enActorDirection_Up);
			}
			else
			{
				PlayAnimation(enActorDirection_Down);
			}
		}
		float distance = cocos2d::ccpLength(disVec);
		static const float speed = 480.0f;
		cocos2d::CCAction *action = MainActor_Move::create(distance / speed, worldPos);
		action->setTag(enActorAction_MoveTo);
		this->runAction(action);
	}
}