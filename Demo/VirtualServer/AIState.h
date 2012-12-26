//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\VirtualServer
//	created:	2012-12-26
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef AIState_h__
#define AIState_h__

#include "NPC.h"

namespace Server
{
	class NPC;
	class AIState
	{
	public:
		AIState(void);
		virtual ~AIState(void);

		virtual void Tick(NPC::Ptr npc, float dt){}
		virtual void OnEnter(NPC::Ptr npc){}
		virtual void OnExit(NPC::Ptr npc){}
	protected:

	private:

	};

	//巡逻
	class AIPatrol
		:public AIState
	{
	public:
		virtual void Tick( NPC::Ptr npc, float dt );
		virtual void OnEnter( NPC::Ptr npc );
		virtual void OnExit( NPC::Ptr npc );
	private:
		void ChangeTarget(NPC::Ptr npc);
		float m_totalTime;
	};
	//攻击
	class AIAttack
		:public AIState
	{
	public:
		virtual void Tick( NPC::Ptr npc, float dt );
		virtual void OnEnter( NPC::Ptr npc );
		virtual void OnExit( NPC::Ptr npc );
	private:
		void SendAttack(NPC::Ptr npc);
		float m_nextAttack;
	};
	//死亡
	class AIDead
		:public AIState
	{
	public:
		virtual void Tick( NPC::Ptr npc, float dt );
		virtual void OnEnter( NPC::Ptr npc );
		virtual void OnExit( NPC::Ptr npc );
	private:
	};
}

#endif // AIState_h__
