#include "IActor.h"
#include "../CSProtocol/CSMessageDef.h"
#include "Base/GlobalDef.h"
#include "../CSProtocol/ActorBattleInfo.h"

namespace Server
{
	_Def_Simulate(IActor);

	IActor::IActor(void)
		:m_x(0.0f)
		,m_y(0.0f)
		,m_battleInfo(new ActorBattleInfo)
	{

	}

	IActor::~IActor(void)
	{
		delete m_battleInfo;
	}

	void IActor::Process( IMessage *message )
	{
		switch (message->GetType())
		{
		default:
			ISimulateObject::Process(message);
			break;
		}
	}

	void IActor::SycPosition(void)
	{
		CSSycActor_S2C message;
		message.m_actorID = GetID();
		message.m_x = GetX();
		message.m_y = GetY();
		message.Build(GetMessageType(CSSycActor_S2C), GetID(), sizeof(CSSycActor_S2C));
		Send(&message);
	}
	void IActor::ChangeEquip( void )
	{
		CSChangeActorEquip_S2C message;
		message.m_actorID = GetID();
		message.m_equipType = ENEquipType::enWeapon;
		strcpy(message.m_equipName, "MainWeapon.ava");
		message.Build(GetMessageType(CSChangeActorEquip_S2C), GetID(), sizeof(CSChangeActorEquip_S2C));
		Send(&message);
	}

	void IActor::Attack( int targetID )
	{

	}

	void IActor::SycBattleInfo( void )
	{
		
	}

	void IActor::SycInfo( void )
	{
		
	}

	void IActor::Dead( void )
	{
		GetBattleInfo()->SetAlive(false);
	}

	void IActor::Tick( float dt )
	{
		
	}

	void IActor::BeAttacked( int targetID )
	{
		this->GetBattleInfo()->SetHP(this->GetBattleInfo()->GetHP() - 1);
		CSBeAttack_S2C message;
		message.m_actorID = GetID();
		message.m_hpChanged = -1;
		message.Build(GetMessageType(CSBeAttack_S2C), GetID(), sizeof(CSBeAttack_S2C));
		Send(&message);

		if (this->GetBattleInfo()->GetHP() <= 0)
		{
			this->Dead();
		}
	}

}