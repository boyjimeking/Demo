#include "AIState.h"
#include <stdlib.h>
#include "../CSProtocol/CSMessageDef.h"
#include "NPC.h"
#include "GameServer.h"

namespace Server
{
	AIState::AIState(void)
	{

	}

	AIState::~AIState(void)
	{

	}

	void AIPatrol::Tick( NPC::Ptr npc, float dt )
	{
		float changedTime = 5.0f;
		if (m_totalTime < 0.000001f)
		{
			ChangeTarget(npc);
			m_totalTime = 1;
		}
		m_totalTime += dt;
		if (m_totalTime > changedTime)
		{
			m_totalTime = rand() / RAND_MAX * changedTime;
		}
	}

	void AIPatrol::OnEnter( NPC::Ptr npc )
	{
		m_totalTime = 0.0f;
	}

	void AIPatrol::OnExit( NPC::Ptr npc )
	{
		
	}
	void AIPatrol::ChangeTarget(NPC::Ptr npc)
	{
		CSMoveTo_S2C message;
		message.m_actorID = npc->GetID();
		message.m_x = GameServer::RandX();
		message.m_y = GameServer::RandY();
		message.Build(GetMessageType(CSMoveTo_S2C), npc->GetID(), sizeof(CSMoveTo_S2C));
		npc->Send(&message);
	}

	void AIAttack::Tick( NPC::Ptr npc, float dt )
	{
		m_nextAttack -= dt;
		if (m_nextAttack <= 0.0f)
		{
			SendAttack(npc);
			m_nextAttack = 5.0f;
		}
	}

	void AIAttack::OnEnter( NPC::Ptr npc )
	{
		m_nextAttack = 0.0f;
	}

	void AIAttack::OnExit( NPC::Ptr npc )
	{

	}

	void AIAttack::SendAttack( NPC::Ptr npc )
	{
		CSAttackTarget_S2C message;
		message.m_actorID = npc->GetID();
		message.m_targetID = npc->GetTarget();
		message.Build(GetMessageType(CSAttackTarget_S2C), npc->GetID(), sizeof(CSAttackTarget_S2C));
		npc->Send(&message);
	}


	void AIDead::OnEnter( NPC::Ptr npc )
	{
		CSDead_S2C message;
		message.m_actorID = npc->GetID();
		message.Build(GetMessageType(CSDead_S2C), npc->GetID(), sizeof(CSDead_S2C));
		npc->Send(&message);
	}

	void AIDead::OnExit( NPC::Ptr npc )
	{

	}

	void AIDead::Tick( NPC::Ptr npc, float dt )
	{

	}

}