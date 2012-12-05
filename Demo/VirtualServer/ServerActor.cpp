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

namespace Net
{
	int ServerActor::Count = 0;
	ServerActor::ServerActor(void)
	:m_id(++ServerActor::Count)
	,m_x(0.0f)
	,m_y(0.0f)
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
}