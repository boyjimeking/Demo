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

namespace Game
{
	// enNothing,	//正常添加到后面，当前执行完毕再执行
	// enInterupt,	//打断当前动作，添加新动作
	// enFobbid,	//新动作无法添加
	const ENInterrupt::Type ENInterrupt::Interrupt[ENAction::Count/*原动作*/][ENAction::Count/*新加入动作*/] = 
	{
		//enNone,		enAction_Move,	enAction_Attack,	enAction_Stop	<- 新加入动作
		{ enFollow,		enFollow,		enFollow,			enFollow },	//enNone
		{ enFollow,		enInterupt,		enInterupt,			enInterupt },	//enAction_Move
		{ enFollow,		enInterupt,		enInterupt,			enInterupt },	//enAction_Attack
		{ enFollow,		enInterupt,		enInterupt,			enInterupt },	//enAction_Stop
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
		m_direction = cocos2d::ccpNormalize(cocos2d::ccpSub(m_pos, m_startPos));
		ActorEventUpdateDirection event(m_pos);
		prop->NotifyChange(&event);
	}
	void MoveAction::OnInterrupt(ActorProp *prop)
	{
		ActorEventStop event;
		prop->NotifyChange(&event);
	}
	void MoveAction::OnExit(ActorProp *prop)
	{
		prop->SetPosition(m_pos);
		ActorEventStop event;
		prop->NotifyChange(&event);
	}
	bool MoveAction::Tick(float dt, ActorProp *prop)
	{
		if (m_direction.equals(cocos2d::CCPointZero))
		{
			return true;
		}
		cocos2d::CCPoint newPos = cocos2d::ccpAdd(prop->GetPosition(), cocos2d::ccpMult(m_direction, dt * prop->GetSpeed()));
		if (cocos2d::ccpDistanceSQ(m_pos, m_startPos) <= cocos2d::ccpDistanceSQ(newPos, m_startPos))
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
	void AttackAction::OnExit(ActorProp *prop)
	{
		ActorEventChangeScaleX scaleEvent(1);
		prop->NotifyChange(&scaleEvent);
	}
	void AttackAction::OnInterrupt(ActorProp *prop)
	{
		ActorEventChangeScaleX scaleEvent(1);
		prop->NotifyChange(&scaleEvent);
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
		if (!m_fired && ActorsControl::Distance(target, prop) > 48.0f)
		{
			ActorEventChangeScaleX scaleEvent(1);
			prop->NotifyChange(&scaleEvent);

			m_fired = false;
			m_fireTime = 0.0f;
			MoveAction::Tick(dt, prop);
			return false;
		}
		else
		{
			if (!m_fired)
			{
				ActorEventPlayAttack event;
				prop->NotifyChange(&event);

				m_direction = cocos2d::ccpNormalize(cocos2d::ccpSub(m_pos, m_startPos));
				ActorEventChangeScaleX scaleEvent(m_direction.x > 0.0f ? -1 : 1);
				prop->NotifyChange(&scaleEvent);

				m_fired = true;
				return false;
			}
			else
			{
				m_fireTime += dt;
				if (m_fireTime > 1.6f)
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
}