//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\VirtualServer
//	created:	2012-12-26
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef AIControl_h__
#define AIControl_h__

#include "NPC.h"

namespace Server
{
	struct ENNPCAIState
	{
		enum Decl
		{
			enError = -1,
			enPatrol,
			enAttack,
			enDead,

			Count,
		};
	};
	class AIState;
	class NPC;
	class AIControl
	{
	public:
		AIControl(void);
		virtual ~AIControl(void);

		void Tick(NPC::Ptr npc, float dt);

		void ChangeState(NPC::Ptr npc, ENNPCAIState::Decl type);
	protected:

	private:
		ENNPCAIState::Decl m_currentState;
		AIState *m_state[ENNPCAIState::Count];
	};
}

#endif // AIControl_h__
