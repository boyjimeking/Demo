//
//  MainActor.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#include "MainActor.h"
#include "../CSProtocol/CSMessageDef.h"
#include "Server.h"

namespace Net
{
    void MainActor::SycPosition(void)
    {
    	CSInitMainActor_S2C message;
        message.m_mainActorID = GetID();
        message.m_x = GetX();
        message.m_y = GetY();
        message.Build(GetMessageType(CSInitMainActor_S2C), GetID(), sizeof(CSInitMainActor_S2C));
        Send(&message);
    }

	void MainActor::Receive( IMessage *message )
	{
		switch (message->GetType())
		{
		case GetMessageType(CSAttackTarget_C2S):
			ProcessCSAttackTarget_C2S(message);
			break;
		default:
			ServerActor::Receive(message);
			break;
		}
	}

	void MainActor::ProcessCSAttackTarget_C2S( IMessage *message )
	{
		CSAttackTarget_C2S *innerMessage = reinterpret_cast<CSAttackTarget_C2S*>(message);
		Attack(innerMessage->m_targetID);
	}

}