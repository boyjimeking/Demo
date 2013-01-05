//
//  ActorAction.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-6.
//
//

#include "ActorAction.h"
#include "WorldManager.h"
#include "ActorsControl.h"
#include "ActorProp.h"
#include "ActorEvents.h"
#include "support/CCPointExtension.h"
#include "platform/CCCommon.h"
#include "Camera/Camera.h"
#include "../CSProtocol/ActorBattleInfo.h"
#include <stdlib.h>
#include "SceneInfo.h"
#include <algorithm>
#include "boost/bind.hpp"

namespace Game
{
	//	enFollow,	//正常添加到后面，当前执行完毕再执行
	//	enInterupt,	//打断当前动作，添加新动作
	//	enInsert,	//插入新动作，当前动作延后
	//	enForbid,	//禁止执行新动作
	const ENInterrupt::Type ENInterrupt::Interrupt[ENAction::Count/*原动作*/][ENAction::Count/*新加入动作*/] = 
	{
		//enNone,	enMove,		enAttack,	enStop,		enDead	<- 新加入动作
		{ enFollow,	enFollow,	enFollow,	enFollow,	enInterupt	},	//enNone
		{ enFollow,	enInterupt,	enInterupt,	enInterupt,	enInterupt	},	//enMove
		{ enFollow,	enInterupt,	enInterupt,	enInterupt,	enInterupt	},	//enAttack
		{ enFollow,	enInterupt,	enInterupt,	enInterupt,	enInterupt	},	//enStop
		{ enForbid,	enForbid,	enForbid,	enForbid,	enForbid	},	//enDead
	};
	ENInterrupt::Type ENInterrupt::Check(ENAction::Type oldAction, ENAction::Type newAction)
	{
		return Interrupt[oldAction][newAction];
	}

	std::set<IAction*> IAction::m_record;
	IAction::IAction(void)
	{
		m_record.insert(this);
	}
	IAction::~IAction(void)
	{
		if (m_record.find(this) == m_record.end())
		{
			cocos2d::CCLog("Warning!!!");
		}
		m_record.erase(this);
	}
	ActionControl::ActionControl(void)
		:m_currentAction(NULL)
		,m_nextAction(NULL)
	{

	}
	void ActionControl::Tick(ActorProp *prop, float dt)
	{
		if (NULL == m_currentAction)
		{
			SwitchNext(prop);
		}
		if (NULL == m_currentAction)
		{
			return;
		}
		if (m_currentAction->Tick(dt, prop))
		{
			m_currentAction->OnExit(prop);
			delete m_currentAction;
			m_currentAction = NULL;
		}
	}
	void ActionControl::SwitchNext(ActorProp *prop)
	{
		if (NULL != m_nextAction)
		{
			m_nextAction->OnEnter(prop);
			m_currentAction = m_nextAction;
			m_nextAction = NULL;
		}
	}
	void ActionControl::AddAction(ActorProp *prop, IAction *action)
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
				m_currentAction->OnInterrupt(prop);
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
		case ENInterrupt::enForbid:
			{
				delete action;
			}
			break;
		default:
			delete action;
			break;
		}
	}
	void ActionControl::AddFollowAction(IAction *action)
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
		case ENInterrupt::enForbid:
			{
				delete action;
			}
			break;
		default:
			delete action;
			break;
		}
	}
	//移动
	MoveAction::MoveAction(const cocos2d::CCPoint &pos)
	:m_pos(pos)
	{

	}
	void MoveAction::OnEnter(ActorProp *prop)
	{
		m_startPos = prop->GetPosition();
		if (m_pos.equals(m_startPos))
		{
			return;
		}
		m_direction = cocos2d::ccpNormalize(cocos2d::ccpSub(m_pos, prop->GetPosition()));
	}
	void MoveAction::OnInterrupt(ActorProp *prop)
	{
		
	}
	void MoveAction::OnExit(ActorProp *prop)
	{
		ActorEventStop event;
		prop->NotifyChange(&event);
	}
	bool MoveAction::Tick(float dt, ActorProp *prop)
	{
		m_direction = cocos2d::ccpNormalize(cocos2d::ccpSub(m_pos, prop->GetPosition()));
		if (m_direction.equals(cocos2d::CCPointZero))
		{
			return true;
		}
		cocos2d::CCPoint changed = cocos2d::ccpMult(m_direction, dt * prop->GetSpeed());
		cocos2d::CCPoint newPos = cocos2d::ccpAdd(prop->GetPosition(), changed);
		if (!WorldManager::Instance()->GetSceneInfo()->IsPointCanStanc(newPos))
		{
			changed.x = dt * prop->GetSpeed();
			changed.x *= m_direction.x > 0 ? 1 : -1;
			changed.y = 0.0f;
			newPos = cocos2d::ccpAdd(prop->GetPosition(), changed);
			if (!WorldManager::Instance()->GetSceneInfo()->IsPointCanStanc(newPos))
			{
				changed.y = m_direction.y * dt * prop->GetSpeed();
				changed.y *= m_direction.y > 0 ? 1 : -1;
				changed.x = 0.0f;
				newPos = cocos2d::ccpAdd(prop->GetPosition(), changed);
				if (!WorldManager::Instance()->GetSceneInfo()->IsPointCanStanc(newPos))
				{
					return true;
				}
				else
				{

				}
			}
			else
			{

			}
		}
		else
		{

		}
		if (m_used.end() != std::find_if(m_used.begin(), m_used.end(), boost::bind(&cocos2d::CCPoint::CCPointEqualToPoint, newPos, _1)))
		{
			return true;
		}
		m_used.push_back(newPos);
		if (cocos2d::ccpDistanceSQ(m_pos, newPos) <= cocos2d::ccpLengthSQ(changed))
		{
			prop->SetPosition(m_pos);
			return true;
		}
		else
		{
			prop->SetPosition(newPos);
			return false;
		}
	}

	//攻击
	AttackAction::AttackAction(ActorProp *prop)
	:MoveAction(prop->GetPosition())
	,m_targetID(prop->GetID())
	,m_fired(false)
	,m_fireTime(0.0f)
	{

	}
	bool AttackAction::Tick(float dt, ActorProp *prop)
	{
		ActorProp *target = WorldManager::Instance()->GetActorsControl()->LookupActor(m_targetID);
		if (NULL == target)
		{
			return true;
		}
        m_pos = target->GetPosition();
		OnEnter(prop);
		if (!m_fired && ActorsControl::Distance(target, prop) > 0.5f)
		{
			m_fired = false;
			m_fireTime = 0.0f;
			MoveAction::Tick(dt, prop);
			return false;
		}
		else
		{
			if (!m_fired)
			{
				if (!target->GetBattleInfo()->IsAlive())
				{
					return true;
				}
				ActorEventPlayAttack event(target, prop);
				prop->NotifyChange(&event);
				if (rand() % 2 == 0)
				{
					WorldManager::Instance()->GetCamera()->Shake();
				}
				if (prop->GetActorType() == ENActorType::enMain)
				{
					prop->SendAttack(m_targetID);
				}
				m_direction = cocos2d::ccpNormalize(cocos2d::ccpSub(m_pos, m_startPos));
				m_fired = true;
				return false;
			}
			else
			{
				m_fireTime += dt;
				if (m_fireTime > 0.8f)
				{
					m_fired = false;
					m_fireTime = 0.0f;
					return false;
				}
				else
				{
					return false;
				}
			}
		}
	}

	void StopAction::OnEnter(ActorProp *prop)
	{
		ActorEventStop event;
		prop->NotifyChange(&event);
	}

	void DeadAction::OnEnter( ActorProp *prop )
	{
		ActorEventDead event;
		prop->NotifyChange(&event);
	}

}