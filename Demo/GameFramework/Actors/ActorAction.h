//
//  ActorAction.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-6.
//
//

#ifndef __Demo__ActorAction__
#define __Demo__ActorAction__

#include "cocoa/CCGeometry.h"
#include <set>

namespace Game
{
	class ActorProp;
	struct ENAction
	{
		enum Type
		{
			enNone,
			enAction_Move,
			enAction_Attack,
			enAction_Stop,
			Count,
		};
	};
	class IAction;
	struct ENInterrupt
	{
		enum Type
		{
			enFollow,	//正常添加到后面，当前执行完毕再执行
			enInterupt,	//打断当前动作，添加新动作
			enInsert,	//插入新动作，当前动作延后
		};
		static const Type Interrupt[ENAction::Count/*原动作*/][ENAction::Count/*新加入动作*/];

		static Type Check(ENAction::Type oldAction, ENAction::Type newAction);
	};
	class IAction
	{
	public:
		virtual ENAction::Type GetType(void) const = 0;

		IAction(void);
		virtual ~IAction(void);
		virtual void OnEnter(ActorProp *prop){}
		virtual void OnExit(ActorProp *prop){}
		virtual void OnInterrupt(ActorProp *prop){}
		//返回值表示是否结束
		virtual bool Tick(float dt, ActorProp *prop) { return true; }
	private:
		static std::set<IAction*> m_record;
	};

	//移动
	class MoveAction
		:public IAction
	{
	public:
		virtual ENAction::Type GetType(void) const { return ENAction::enAction_Move; }

		MoveAction(const cocos2d::CCPoint &pos);
		virtual void OnEnter(ActorProp *prop);
		virtual void OnInterrupt(ActorProp *prop);
		virtual void OnExit(ActorProp *prop);
		virtual bool Tick(float dt, ActorProp *prop);
	protected:
		cocos2d::CCPoint m_pos;
		cocos2d::CCPoint m_startPos;
		cocos2d::CCPoint m_direction;
	};

	//攻击
	class AttackAction
		:public MoveAction
	{
	public:
		virtual ENAction::Type GetType(void) const { return ENAction::enAction_Attack; }

		AttackAction(ActorProp *prop);
		
		virtual void OnExit(ActorProp *prop);
		virtual void OnInterrupt(ActorProp *prop);
		virtual bool Tick(float dt, ActorProp *prop);
	protected:
		int m_targetID;
		bool m_fired;
		float m_fireTime;
	};

	//停止
	class StopAction
		:public IAction
	{
		virtual ENAction::Type GetType(void) const { return ENAction::enAction_Stop; }
		virtual void OnEnter(ActorProp *prop);
	};
}

#endif /* defined(__Demo__ActorAction__) */
