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
#include "../Tools/AnimationGroup.h"
#include "../Tools/AvatarData.h"
#include "../Tools/AnimationData.h"
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
		m_sBlendFunc.src=GL_SRC_ALPHA;
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
					setAnchorPoint(cocos2d::CCPointMake(0.5f, 0.3f));
					const ActorEventCreate *actorEvent = reinterpret_cast<const ActorEventCreate*>(event);
					switch (actorEvent->GetType())
					{
					case ENActorType::enMain:
						{
							LoadAvatarFromFile("MainActor.ava");
							setScale(GetAvatar()->GetTransScale());
							cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(GetAvatar()->GetPList());
						}
						break;
					default:
						{
							cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
							m_touchCallBack = new TouchMonster(reinterpret_cast<ActorProp*>(notify));
							LoadAvatarFromFile("NPCActor.ava");
							setScale(GetAvatar()->GetTransScale());
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
						this->getParent()->reorderChild(this, -getPosition().y * 1000);
					}
					else
					{
						_setZOrder(-getPosition().y * 1000);
					}
					if (ENActorType::enMain == reinterpret_cast<const ActorProp*>(notify)->GetActorType())
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
					const ActorEventPlayAttack *actorEvent = reinterpret_cast<const ActorEventPlayAttack*>(event);
					PlayAnimation(ENAnimation::enAttack, CalDirection(actorEvent->m_target->GetPosition(), actorEvent->m_src->GetPosition()));
				}
				break;
			case ENActorEvent::enChangeAvatar:
				{
					const ActorEventChangeAvatar *actorEvent = reinterpret_cast<const ActorEventChangeAvatar*>(event);
					SetAvatar(m_avatar);
					RePlayAnimation();
				}
				break;
			case ENActorEvent::enChangeEquip:
				{
					const ActorEventChangeEquip *actorEvent = reinterpret_cast<const ActorEventChangeEquip*>(event);
					cocos2d::CCArray *childArray = getChildren();
					CCObject* pObj = NULL;
					EquipObject* child = NULL;
					CCARRAY_FOREACH(childArray,pObj)
					{
						child = (EquipObject*)pObj;
						if (child->GetType() == actorEvent->m_type)
						{
							break;
						}
						else
						{
							child = NULL;
						}
					}
					if (NULL == actorEvent->m_equipFile)
					{
						if (NULL != child)
						{
							removeChild(child, true);
						}
					}
					else
					{
						if (NULL == child)
						{
							child = EquipObject::Create();
							child->SetType(actorEvent->m_type);
							addChild(child);
							child->setPosition(cocos2d::CCPointZero);
						}
						child->LoadAvatarFromFile(actorEvent->m_equipFile);
						RePlayAnimation();
					}
				}
				break;
			case ENActorEvent::enDead:
				{
					PlayAnimation(ENAnimation::enDead, m_currentDirection, false);
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

		if (fabs(angle) < M_PI_8)
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
		if (fabs(angle) > M_PI_8 * 7)
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
		cocos2d::CCPoint localTouch = convertTouchToNodeSpace(pTouch);
		cocos2d::CCRect rect = cocos2d::CCRectMake(getContentSize().width / 3.0f, getContentSize().height / 3.0f, getContentSize().width / 3.0f, getContentSize().height / 3.0f);
		if (rect.containsPoint(localTouch))
		{
			return m_touchCallBack->OnTouch(localTouch);
		}
		else
		{
			return false;
		}
	}

	void ActorEntity::PlayAnimation(ENAnimation::Decl type, ENDirection::Decl direction, bool isLoop /* = true; */)
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
		cocos2d::CCAction *action = isLoop ? (cocos2d::CCAction*)cocos2d::CCRepeatForever::create(animate) : (cocos2d::CCAction*)animate;
		this->stopActionByTag(enActorAction_PlayAnimation);
		action->setTag(enActorAction_PlayAnimation);
		this->runAction(action);

		cocos2d::CCArray *childArray = getChildren();
		CCObject* pObj = NULL;
		CCARRAY_FOREACH(childArray,pObj)
		{
			EquipObject* child = (EquipObject*)pObj;
			child->PlayAnimation(type, direction);
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

	void ActorEntity::RePlayAnimation( void )
	{
		ENAnimation::Decl type = m_currentAnimation;
		ENDirection::Decl direction = m_currentDirection;
		m_currentAnimation = ENAnimation::enError;
		m_currentDirection = ENDirection::enError;
		PlayAnimation(type, direction);
	}

}