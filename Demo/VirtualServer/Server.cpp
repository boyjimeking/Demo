//
//  Server.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#include "Server.h"
#include "../CSProtocol/CSMessageDef.h"
#include "../CSProtocol/CSPipeline.h"
namespace Net
{
    void Server::Receive(IMessage *message)
    {
    	switch (message->GetType())
    	{
    		default:
    			break;
    	}
    }
    void Server::Send(IMessage *message)
    {
    	CSPipeline::Instance()->SendToClient(message);
    }
    void Server::Init(void)
    {
    	CSInit_S2C message;
        message.m_mainActorID = 1;
        message.m_sceneID = 1;
        message.Build(GetMessageType(CSInit_S2C), 0, sizeof(CSInit_S2C));
        Send(&message);
    }
}