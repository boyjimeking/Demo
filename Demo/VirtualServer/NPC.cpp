#include "NPC.h"
#include "CSProtocol/CSMessageDef.h"
#include "GameServer.h"

namespace Server
{
	_Def_Simulate(NPC);
	NPC::NPC(void)
	{

	}

	NPC::~NPC(void)
	{

	}

	void NPC::Tick( float dt )
	{
		float changedTime = 5.0f;
		if (m_totalTime < 0.000001f)
		{
			ChangeTarget();
			m_totalTime = 1;
		}
		m_totalTime += dt;
		if (m_totalTime > changedTime)
		{
			m_totalTime = rand() / RAND_MAX * changedTime;
		}
	}
	void NPC::ChangeTarget(void)
	{
		CSChangeTarget_S2C message;
		message.m_actorID = GetID();
		message.m_x = GameServer::RandX();
		message.m_y = GameServer::RandY();
		message.Build(GetMessageType(CSChangeTarget_S2C), GetID(), sizeof(CSChangeTarget_S2C));
		Send(&message);
	}
}