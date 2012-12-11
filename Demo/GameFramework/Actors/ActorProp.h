//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/ActorManager/ActorProp.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef ActorProp_h__
#define ActorProp_h__

#include "../Base/INotifier.h"
#include "cocoa/CCGeometry.h"
#include "../Base/GlobalDef.h"
#include <list>
#include "ActorAction.h"

namespace Game
{
	class ActorEntity;
	class PhysicalObj;
	class IAction;
	/*
	 *	角色属性类，用于记录并控制角色的各项属性
	 */
	class ActorProp
		:public INotifier
	{
	public:
		ActorProp(ENActorType::Decl type, int id);
		virtual ~ActorProp(void);

		int GetID(void) const { return m_id; }
		ENActorType::Decl GetType(void) const { return m_type; }
		const cocos2d::CCPoint& GetPosition(void) const { return m_position; }
		float GetSpeed(void) const { return m_speed; }

		void Init(void);
		ActorEntity* Create(void);
		void Release(void);

		void MoveTo(const cocos2d::CCPoint &pos);
		void Stop(void);
		void Attack(ActorProp *target);

		void SetPosition(const cocos2d::CCPoint &pos);

		void Tick(float dt);

		void AddAction(IAction *action);
		void AddFollowAction(IAction *action);
	protected:
		cocos2d::CCPoint m_position;
		int m_id;
		ENActorType::Decl m_type;
		float m_speed;
	private:
		IAction *m_currentAction;
		IAction *m_nextAction;
		void SwitchNext(void);
	};
}

#endif // ActorProp_h__
