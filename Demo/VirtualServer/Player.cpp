#include "Player.h"
#include "../CSProtocol/CSMessageDef.h"
#include "../Tools/StreamHelper.h"
#include "../CSProtocol/ActorBattleInfo.h"
#include "ISimulateLayer.h"
#include "NPC.h"
#include "AIControl.h"

namespace Server
{
	_Def_Simulate(Player);
	Player::Player(void)
	{

	}

	Player::~Player(void)
	{

	}

	void Player::Process( IMessage *message )
	{
		switch (message->GetType())
		{
		case GetMessageType(CSAttackTarget_C2S):
			ProcessCSAttackTarget_C2S(message);
			break;
		default:
			IActor::Process(message);
			break;
		}
	}

	void Player::SycInfo( void )
	{
		CSInitPlayer_S2C message;
		message.m_actorID = GetID();
		message.m_x = GetX();
		message.m_y = GetY();
		StreamHelper stream(message.m_data, CSInitPlayer_S2C::DataMaxLength);
		GetBattleInfo()->Write(&stream);
		message.m_dataLength = stream.Size();
		message.Build(GetMessageType(CSInitPlayer_S2C), GetID(), sizeof(CSInitPlayer_S2C));
		Send(&message);
	}

	void Player::ProcessCSAttackTarget_C2S( IMessage *message )
	{
		CSAttackTarget_C2S *innerMessage = reinterpret_cast<CSAttackTarget_C2S*>(message);
		ISimulateObject::Ptr obj = GetSimulate()->LookupObject(innerMessage->m_targetID);
		if (!obj || !obj->IsKindof(_Get_SimulateType(IActor)))
		{
			return;
		}
		IActor::Ptr target = boost::static_pointer_cast<IActor>(obj);
		target->BeAttacked(GetID());
	}


}