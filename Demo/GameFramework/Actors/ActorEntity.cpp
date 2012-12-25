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
#include "Tools/AnimationGroup.h"
#include "Tools/AvatarData.h"
#include "Tools/AnimationData.h"
#include "../CCFileUtils.h"
#include "EquipObject.h"


namespace Game
{
	ActorEntity::ActorEntity(ActorProp *prop)
	:m_currentDirection(ENDirection::enError)
	,m_touchCallBack(NULL)
	,m_currentAnimation(ENAnimation::enIdle)
	,m_avatar(NULL)
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
						LoadAvatarFromFile("MainActor.anim");
						cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(GetAvatar()->GetPList());
						break;
					default:
						{
							this->setContentSize(cocos2d::CCSizeMake(0.7f, 1.8f));
							cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
							m_touchCallBack = new TouchMonster(reinterpret_cast<ActorProp*>(notify));
							LoadAvatarFromFile("NPCActor.anim");
							cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(GetAvatar()->GetPList());
						}
						break;
					}
					PlayAnimation(ENAnimation::enIdle, ENDirection::enSouth);
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
					cocos2d::CCPoint newPos = actorEvent->GetLogicPos();
					PlayAnimation(ENAnimation::enMove, CalDirection(newPos, getPosition()));
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
						WorldManager::Instance()->GetCamera()->SetPosition(getPosition());
					}
				}
				break;
			case ENActorEvent::enStop:
				{
					PlayAnimation(ENAnimation::enIdle, m_currentDirection);
				}
				break;
			case ENActorEvent::enAttack:
				{
					PlayAnimation(ENAnimation::enAttack, m_currentDirection);
				}
				break;
			case ENActorEvent::enChangeAvatar:
				{
					const ActorEventChangeAvatar *actorEvent = reinterpret_cast<const ActorEventChangeAvatar*>(event);
					SetAvatar(m_avatar);
					PlayAnimation(m_currentAnimation, m_currentDirection);
				}
				break;
			case ENActorEvent::enChangeEquip:
				{
					const ActorEventChangeEquip *actorEvent = reinterpret_cast<const ActorEventChangeEquip*>(event);

				}
				break;
			default:
				break;
		}
	}
	ENDirection::Decl ActorEntity::CalDirection(const cocos2d::CCPoint &targetPos, const cocos2d::CCPoint &currentPos)
	{
		float angle = ccpToAngle(cocos2d::ccpSub(targetPos, currentPos));

		static const float M_PI_8 = (float)M_PI / 8.0f;

		if (abs(angle) < M_PI_8)
		{
			return ENDirection::enEast;
		}
		if (M_PI_8 < angle && angle < M_PI_8 * 3)
		{
			return ENDirection::enNorthEast;
		}
		if (M_PI_8 * 3 < angle && angle < M_PI_8 * 5)
		{
			return ENDirection::enNorth;
		}
		if (M_PI_8 * 5 < angle && angle < M_PI_8 * 7)
		{
			return ENDirection::enNorthWest;
		}
		if (abs(angle) > M_PI_8 * 7)
		{
			return ENDirection::enWest;
		}
		if (M_PI_8 * -5 > angle && angle > M_PI_8 * -7)
		{
			return ENDirection::enSouthWest;
		}
		if (M_PI_8 * -3 > angle && angle > M_PI_8 * -5)
		{
			return ENDirection::enSouth;
		}
		if (-M_PI_8 > angle && angle > M_PI_8 * -3)
		{
			return ENDirection::enSouthEast;
		}
		return ENDirection::enEast;
	}
	void ActorEntity::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
	{
		
	}
	bool ActorEntity::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
	{
		cocos2d::CCPoint local = WorldManager::DesignPosToWorld(pTouch->getLocation());
		if (boundingBox().containsPoint(local))
		{
			return m_touchCallBack->OnTouch(local);
		}
		else
		{
			return false;
		}
	}

	void ActorEntity::PlayAnimation(ENAnimation::Decl type, ENDirection::Decl direction)
	{
		if (m_currentDirection == direction && m_currentAnimation == type)
		{
			return;
		}
		m_currentDirection = direction;
		m_currentAnimation = type;

		if (NULL == GetAvatar())
		{
			return;
		}
		Tools::AnimationGroup *animGroup = GetAvatar()->Lookup(type);
		if (NULL == animGroup)
		{
			return;
		}
		Tools::AnimationData *animData = animGroup->LookupAnimation(direction);
		if (NULL == animData)
		{
			return;
		}
		cocos2d::CCArray *frameArray = cocos2d::CCArray::createWithCapacity(animData->GetFrameCount());
		for (unsigned int index = 0; index < animData->GetFrameCount(); ++index)
		{
			cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(animData->GetFrame(index));
			if (NULL == frame)
			{
				continue;
			}
			frameArray->addObject(frame);
		}
		this->initWithSpriteFrame(reinterpret_cast<cocos2d::CCSpriteFrame*>(frameArray->lastObject()));
		setAnchorPoint(cocos2d::CCPointMake(0.5f, 0.3f));
		cocos2d::CCAnimation *animation = cocos2d::CCAnimation::createWithSpriteFrames(frameArray, animData->GetDelay());
		cocos2d::CCAnimate *animate = cocos2d::CCAnimate::create(animation);
		cocos2d::CCAction *action = cocos2d::CCRepeatForever::create(animate);
		this->stopActionByTag(enActorAction_PlayAnimation);
		action->setTag(enActorAction_PlayAnimation);
		this->runAction(action);
		for (int index = 0; index < m_equipList.size() ; ++index)
		{
			m_equipList[index]->PlayAnimation(type, direction);
		}
	}

	void ActorEntity::LoadAvatarFromFile( const char *file )
	{
		const char *fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(file);
		unsigned long size = 0;
		unsigned char *buff = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(fullPath, "rb", &size);
		LoadAvatar(buff, size);
		delete[] buff;
	}

	void ActorEntity::LoadAvatar( unsigned char *data, unsigned int size )
	{
		if (0 == size)
		{
			return;
		}
		if (NULL == m_avatar)
		{
			m_avatar = new Tools::AvatarData;
		}
		m_avatar->Read(data, size);
	}

	void ActorEntity::SetAvatar( Tools::AvatarData *avatar )
	{
		if (m_avatar == avatar)
		{
			return;
		}
		if (NULL != m_avatar)
		{
			delete m_avatar;
		}
		m_avatar = avatar;
	}

}