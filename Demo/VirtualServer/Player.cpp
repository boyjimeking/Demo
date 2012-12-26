#include "Player.h"
#include "CSProtocol/CSMessageDef.h"

namespace Server
{
	_Def_Simulate(Player);
	Player::Player(void)
	{

	}

	Player::~Player(void)
	{

	}

	void Player::SycPosition(void)
	{
		CSInitMainActor_S2C message;
		message.m_mainActorID = GetID();
		message.m_x = GetX();
		message.m_y = GetY();
		message.Build(GetMessageType(CSInitMainActor_S2C), GetID(), sizeof(CSInitMainActor_S2C));
		Send(&message);
	}
}