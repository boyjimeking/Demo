#include "AIControl.h"
#include <stddef.h>
#include "AIState.h"
#include "NPC.h"

namespace Server
{
	AIControl::AIControl(void)
		:m_currentState(ENNPCAIState::enError)
	{
		m_state[ENNPCAIState::enPatrol] = new AIPatrol;
		m_state[ENNPCAIState::enAttack] = new AIAttack;
		m_state[ENNPCAIState::enDead] = new AIDead;
	}

	AIControl::~AIControl(void)
	{
		for (int index = 0; index < ENNPCAIState::Count; ++index)
		{
			delete m_state[index];
			m_state[index] = NULL;
		}
	}

	void AIControl::ChangeState(NPC::Ptr npc, ENNPCAIState::Decl type)
	{
		if (type == m_currentState)
		{
			return;
		}
		if (ENNPCAIState::enError != m_currentState)
		{
			m_state[m_currentState]->OnExit(npc);
		}
		m_currentState = type;
		m_state[m_currentState]->OnEnter(npc);
	}

	void AIControl::Tick(NPC::Ptr npc, float dt)
	{
		if (ENNPCAIState::enError == m_currentState)
		{
			ChangeState(npc, ENNPCAIState::enPatrol);
		}
		m_state[m_currentState]->Tick(npc, dt);
	}

}