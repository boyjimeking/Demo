//
//  ServerActor.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#include "ServerActor.h"
#include "../CSProtocol/CSMessageDef.h"
#include "../CSProtocol/CSPipeline.h"
#include "Server.h"
#include "Base/GlobalDef.h"

namespace Net
{
	int ServerActor::Count = 0;
	ServerActor::ServerActor(void)
	:m_id(++ServerActor::Count)
	,m_x(0.0f)
	,m_y(0.0f)
    ,m_totalTime(0.0f)
	,m_server(NULL)
	,m_isAttacking(false)
	{

	}
	ServerActor::~ServerActor(void)
	{
		
	}

	void ServerActor::Receive(IMessage *message)
	{
		switch (message->GetType())
    	{
    		default:
    			break;
    	}
	}
    void ServerActor::Send(IMessage *message)
    {
    	CSPipeline::Instance()->SendToClient(message);
    }

    ServerActor::Ptr ServerActor::CreateObj(void)
    {
    	return ServerActor::Ptr(new ServerActor);
    }
    void ServerActor::Tick(float dt)
    {
		float changedTime = 5.0f;
		if (m_isAttacking)
		{
			changedTime = 15.0f;
		}
        if (m_totalTime < 0.000001f)
        {
			if (!m_isAttacking)
			{
				ChangeTarget();
			}
            m_totalTime = 1;
			m_isAttacking = false;
        }
        m_totalTime += dt;
        if (m_totalTime > changedTime)
        {
            m_totalTime = rand() / RAND_MAX * changedTime;
        }
    }
    void ServerActor::SycPosition(void)
    {
    	CSSycActor_S2C message;
    	message.m_actorID = GetID();
    	message.m_x = GetX();
    	message.m_y = GetY();
    	message.Build(GetMessageType(CSSycActor_S2C), GetID(), sizeof(CSSycActor_S2C));
    	Send(&message);
    }
    void ServerActor::ChangeTarget(void)
    {
        CSChangeTarget_S2C message;
        message.m_actorID = GetID();
        message.m_x = Server::RandX();
        message.m_y = Server::RandY();
        message.Build(GetMessageType(CSChangeTarget_S2C), GetID(), sizeof(CSChangeTarget_S2C));
        Send(&message);
    }
	void ServerActor::ChangeEquip( void )
	{
		CSChangeActorEquip_S2C message;
		message.m_actorID = GetID();
		message.m_equipType = ENEquipType::enWeapon;
		strcpy(message.m_equipName, "MainWeapon.ava");
		message.Build(GetMessageType(CSChangeActorEquip_S2C), GetID(), sizeof(CSChangeActorEquip_S2C));
		Send(&message);
	}

	void ServerActor::Attack( int targetID )
	{
		ServerActor::Ptr target = GetServer()->LookupActor(targetID);
		if (target)
		{
			target->SetAttacking(true);
		}

		CSAttackTarget_S2C message;
		message.m_actorID = targetID;
		message.m_targetID = GetID();
		message.Build(GetMessageType(CSAttackTarget_S2C), GetID(), sizeof(CSAttackTarget_S2C));
		Send(&message);
	}

	void ServerActor::SetAttacking( bool isTrue )
	{
		m_isAttacking = isTrue;
	}

}