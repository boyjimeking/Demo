#include "ActorEntity.h"
#include "ActorEvents.h"
#include "Animation/FrameAnimation.h"
#include "Animation/BoneAnimation.h"
#include "ActorTouch.h"
#include "ActorProp.h"
#include "WorldManager.h"
#include "Camera/Camera.h"
#include "particle_nodes/CCParticleExamples.h"
#include "Tools/AvatarData.h"

namespace Game
{
	ActorEntity::ActorEntity(void)
	:m_touchCallBack(NULL)
	,m_frameAnimation(NULL)
	,m_boneAnimation(NULL)
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
					const ActorEventCreate *actorEvent = reinterpret_cast<const ActorEventCreate*>(event);
					switch (actorEvent->GetType())
					{
					case ENActorType::enMain:
						{
							//if (NULL == m_boneAnimation)
							//{
							//	m_boneAnimation = new BoneAnimation;
							//}
							//m_boneAnimation->LoadAvatarFromFile("MainActor.bva");
							//addChild(m_boneAnimation);
							//setScale(m_boneAnimation->GetTransScale());

							if (NULL == m_frameAnimation)
							{
								m_frameAnimation = new FrameAnimation;
							}
							m_frameAnimation->LoadAvatarFromFile("MainActor.ava");
							setScale(m_frameAnimation->GetTransScale());
							addChild(m_frameAnimation);

							//CCParticleFire *particle = CCParticleFire::create();
							//addChild(particle);
							//particle->AttachTarget(getParent());
							//particle->setPosition(CCPointMake(-100.0f, 20.0f));
							//particle->setAngle(180.0f);
						}
						break;
					default:
						{
							//性能测试
							//if (NULL == m_boneAnimation)
							//{
							//	m_boneAnimation = new BoneAnimation;
							//}
							//m_boneAnimation->LoadAvatarFromFile("MainActor.bva");
							//addChild(m_boneAnimation);
							//setScale(m_boneAnimation->GetTransScale());

							if (NULL == m_frameAnimation)
							{
								m_frameAnimation = new FrameAnimation;
							}
							m_frameAnimation->LoadAvatarFromFile("NPCActor.ava");
							setScale(m_frameAnimation->GetTransScale());
							addChild(m_frameAnimation);
							CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
							m_touchCallBack = new TouchMonster(reinterpret_cast<ActorProp*>(notify));
						}
						break;
					}
					PlayAnimation(ENAnimation::Idle, ENDirection::enSouth);
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
					CCPoint newPos = actorEvent->GetLogicPos();
					PlayAnimation(ENAnimation::Move, CalDirection(newPos, getPosition()));
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
					PlayAnimation(ENAnimation::Idle, ENDirection::enError);
				}
				break;
			case ENActorEvent::enAttack:
				{
					const ActorEventPlayAttack *actorEvent = reinterpret_cast<const ActorEventPlayAttack*>(event);
					PlayAnimation(ENAnimation::Attack, CalDirection(actorEvent->m_target->GetPosition(), actorEvent->m_src->GetPosition()));
				}
				break;
			case ENActorEvent::enChangeAvatar:
				{
					const ActorEventChangeAvatar *actorEvent = reinterpret_cast<const ActorEventChangeAvatar*>(event);
					unsigned char buff[16384] = {0};
					unsigned int size = actorEvent->m_avatar->Write(buff, 16384);
					m_frameAnimation->LoadAvatar(buff, size);
					RePlayAnimation();
				}
				break;
			case ENActorEvent::enChangeEquip:
				{
					const ActorEventChangeEquip *actorEvent = reinterpret_cast<const ActorEventChangeEquip*>(event);
					if (NULL != m_frameAnimation)
					{
						m_frameAnimation->ChangeEquip(actorEvent->m_type, actorEvent->m_equipFile);
					}
				}
				break;
			case ENActorEvent::enDead:
				{
					PlayAnimation(ENAnimation::Dead, ENDirection::enError, false);
				}
				break;
			default:
				break;
		}
	}
	ENDirection::Decl ActorEntity::CalDirection(const CCPoint &targetPos, const CCPoint &currentPos)
	{
		float angle = ccpToAngle(ccpSub(targetPos, currentPos));

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
	void ActorEntity::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
	{
		
	}
	bool ActorEntity::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
	{
		CCPoint localTouch = m_frameAnimation->convertTouchToNodeSpace(pTouch);
		CCSize size = m_frameAnimation->getContentSize();
		CCRect rect = CCRectMake(size.width / 3.0f, size.height / 3.0f, size.width / 3.0f, size.height / 3.0f);
		if (rect.containsPoint(localTouch))
		{
			return m_touchCallBack->OnTouch(localTouch);
		}
		else
		{
			return false;
		}
	}

	void ActorEntity::PlayAnimation(const char *type, ENDirection::Decl direction, bool isLoop /* = true */)
	{
		if (NULL != m_frameAnimation)
		{
			m_frameAnimation->PlayAnimation(type, direction, isLoop);
		}
		else if (NULL != m_boneAnimation)
		{
			m_boneAnimation->PlayAnimation(type, direction, isLoop);
		}
		else
		{
			//
		}
	}

	void ActorEntity::RePlayAnimation( void )
	{
		PlayAnimation(ENAnimation::Error, ENDirection::enError);
	}

	ActorEntity* ActorEntity::Create( void )
	{
		if (!INotifier::NotifyMode)
		{
			return NULL;
		}
		ActorEntity *entity = new ActorEntity();
		if (entity/* && entity->init()*/)
		{
			entity->autorelease();
			return entity;
		}
		CC_SAFE_DELETE(entity);
		return NULL;
	}

}