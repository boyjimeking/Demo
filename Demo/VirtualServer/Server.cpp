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
#include "MainActor.h"

namespace Net
{
    const int Server::Width = 2760 / 2;
    const int Server::Height = 1540 / 2;

    Server::Server(void)
    {

    }
    Server::~Server(void)
    {
        
    }
    void Server::Receive(IMessage *message)
    {
        if (0 != message->GetSenderID())
        {
            ServerActorMap::iterator it = m_serverActorMap.find(message->GetSenderID());
            if (m_serverActorMap.end() != it)
            {
                it->second->Receive(message);
            }
            else
            {
                //查无此人
            }
            return;
        }
    	switch (message->GetType())
    	{
    		default:
    			break;
    	}
    }
    void Server::Send(IMessage *message) const
    {
    	CSPipeline::Instance()->SendToClient(message);
    }
    void Server::Init(void)
    {
        {
            CSInitScene_S2C message;
            message.m_sceneID = 1;
            message.Build(GetMessageType(CSInitScene_S2C), 0, sizeof(CSInitScene_S2C));
            Send(&message);
        }
        {
            ServerActor::Ptr actor = ServerActor::Ptr(new MainActor);
            m_serverActorMap.insert(std::make_pair(actor->GetID(), actor));

            actor->SetX(RandX());
            actor->SetY(RandY());

            actor->SycPosition();
        }
        for (int index = 0; index < 30; ++index)
        {
            ServerActor::Ptr actor = ServerActor::CreateObj();
            m_serverActorMap.insert(std::make_pair(actor->GetID(), actor));

            actor->SetX(RandX());
            actor->SetY(RandY());

            actor->SycPosition();
        }
    }
    void Server::Tick(float dt)
    {
        for (ServerActorMap::iterator it = m_serverActorMap.begin(); m_serverActorMap.end() != it; ++it)
        {
            it->second->Tick(dt);
        }
    }
    int Server::RandX(void)
    {
        return (float)rand() / (float)RAND_MAX * Width - Width / 2;
    }
    int Server::RandY(void)
    {
        return (float)rand() / (float)RAND_MAX * Height - Height / 2;
    }
}