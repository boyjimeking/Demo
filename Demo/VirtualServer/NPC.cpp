#include "NPC.h"
#include "CSProtocol/CSMessageDef.h"
#include "GameServer.h"
#include "Tools/StreamHelper.h"
#include "CSProtocol/ActorBattleInfo.h"
#include "AIControl.h"

namespace Server
{
	_Def_Simulate(NPC);
	NPC::NPC(void)
		:m_control(new AIControl)
		,m_target(0)
	{

	}

	NPC::~NPC(void)
	{

	}

	void NPC::Tick( float dt )
	{
		m_control->Tick(boost::static_pointer_cast<NPC>(shared_from_this()), dt);
	}


	void NPC::SycInfo( void )
	{
		CSInitNPC_S2C message;
		message.m_actorID = GetID();
		message.m_npcStaticID = 0;
		message.m_x = GetX();
		message.m_y = GetY();
		Tools::StreamHelper stream(message.m_data, CSInitPlayer_S2C::DataMaxLength);
		GetBattleInfo()->Write(&stream);
		message.m_dataLength = stream.Size();
		message.Build(GetMessageType(CSInitNPC_S2C), GetID(), sizeof(CSInitNPC_S2C));
		Send(&message);
	}

	void NPC::Dead( void )
	{
		IActor::Dead();
		GetControl()->ChangeState(boost::static_pointer_cast<NPC>(shared_from_this()), ENNPCAIState::enDead);
	}

}