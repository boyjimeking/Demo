#include "ActorEntity.h"
#include "ActorEvents.h"
#include "textures/CCTextureCache.h"
#include "sprite_nodes/CCSpriteFrame.h"
#include "sprite_nodes/CCAnimation.h"
#include "cocoa/CCGeometry.h"
#include "cocoa/CCArray.h"
#include "actions/CCActionInterval.h"
#include "CCDirector.h"

namespace Game
{
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
					cocos2d::CCTexture2D *texture = cocos2d::CCTextureCache::sharedTextureCache()->addImage("actor.png");
					cocos2d::CCArray *frameArray = cocos2d::CCArray::createWithCapacity(4);
					//width:47 height:95
					static const int FrameWidth = 47;
					static const int FrameHeight = 95;
					for (int index = 0; index < 4; ++index)
					{
						cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrame::createWithTexture(texture, cocos2d::CCRectMake(index * FrameWidth, 0, FrameWidth, FrameHeight));
						frameArray->addObject(frame);
					}
					this->initWithSpriteFrame(reinterpret_cast<cocos2d::CCSpriteFrame*>(frameArray->lastObject()));
					cocos2d::CCAnimation *animation = cocos2d::CCAnimation::createWithSpriteFrames(frameArray, 0.2f);
					cocos2d::CCAnimate *animate = cocos2d::CCAnimate::create(animation);
					this->runAction(cocos2d::CCRepeatForever::create(animate));
					cocos2d::CCSize visibleSize = cocos2d::CCDirector::sharedDirector()->getVisibleSize();
					this->setPosition(cocos2d::CCPointMake(visibleSize.width / 2, visibleSize.height / 2));
				}
				break;
			case ENActorEvent::enActorEvent_Release:
				{

				}
				break;
			default:
				break;
		}
	}

}