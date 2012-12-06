#include "ActorProp.h"
#include "ActorEvents.h"
#include "ActorEntity.h"

namespace Game
{
	ActorProp::ActorProp(ENActorType::Decl type, int id)
	:m_id(id)
	,m_type(type)
	,m_speed(100.0f)
	,m_currentAction(NULL)
	,m_nextAction(NULL)
	{

	}
	ActorProp::~ActorProp(void)
	{

	}

	void ActorProp::Init(void)
	{
		switch (GetType())
		{
			case ENActorType::enMain:
				{
					
				}
				break;
			default:
				break;
		}
	}
	ActorEntity* ActorProp::Create(void)
	{
		ActorEntity *entity = new ActorEntity(this);
		entity->init();
		AttachObserver(entity);

		ActorEventCreate event(GetType());
		NotifyChange(&event);
		return entity;
	}

	void ActorProp::Release(void)
	{
		ActorEventRelease event;
		NotifyChange(&event);
	}
	void ActorProp::MoveTo(const cocos2d::CCPoint &pos)
	{
		AddAction(new MoveAction(pos));
	}
	void ActorProp::SetPosition(const cocos2d::CCPoint &pos)
	{
		if (m_position.equals(pos))
		{
			return;
		}
		m_position = pos;
		ActorEventChangePos event(pos);
		NotifyChange(&event);
	}
	void ActorProp::Stop(void)
	{
		AddAction(new StopAction);
	}
	void ActorProp::Attack(ActorProp *target)
	{
		AddAction(new AttackAction(target));
	}
	void ActorProp::Tick(float dt)
	{
		if (NULL == m_currentAction)
		{
			SwitchNext();
		}
		if (NULL == m_currentAction)
		{
			return;
		}
		if (m_currentAction->Tick(dt, this))
		{
			m_currentAction->OnExit(this);
			delete m_currentAction;
			m_currentAction = NULL;
		}
	}
	void ActorProp::SwitchNext(void)
	{
		if (NULL != m_nextAction)
		{
			m_nextAction->OnEnter(this);
			m_currentAction = m_nextAction;
			m_nextAction = NULL;
		}
	}
	void ActorProp::AddAction(IAction *action)
	{
		if (NULL == m_currentAction)
		{
			AddFollowAction(action);
			return;
		}
		switch (ENInterrupt::Check(m_currentAction->GetType(), action->GetType()))
		{
			case ENInterrupt::enFollow:
				{
					AddFollowAction(action);
				}
				break;
			case ENInterrupt::enInterupt:
				{
					m_currentAction->OnInterrupt(this);
					delete m_currentAction;
					m_currentAction = NULL;
					AddFollowAction(action);
				}
				break;
			case ENInterrupt::enInsert:
				{
					if (NULL != m_nextAction)
					{
						delete m_nextAction;
						m_nextAction = m_currentAction;
					}
					m_currentAction = action;
				}
				break;
			default:
				delete action;
				break;
		}
	}
	void ActorProp::AddFollowAction(IAction *action)
	{
		if (NULL == m_nextAction)
		{
			m_nextAction = action;
			return;
		}
		switch (ENInterrupt::Check(m_nextAction->GetType(), action->GetType()))
		{
			case ENInterrupt::enFollow:
				{
					delete action;
				}
				break;
			case ENInterrupt::enInterupt:
				{
					delete m_nextAction;
					m_nextAction = action;
				}
				break;
			case ENInterrupt::enInsert:
				{
					delete m_nextAction;
					m_nextAction = action;
				}
				break;
			default:
				delete action;
				break;
		}
	}
}