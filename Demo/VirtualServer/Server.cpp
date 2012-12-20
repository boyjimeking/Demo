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
#include "../CCFileUtils.h"
#include "Tools/Scene.h"

namespace Net
{
	float Server::Width = 384.0f;
	float Server::Height = 192.0f;
	float Server::GridSize = 0.5f;
	float Server::TranScale = 10.0f;//一米多少点

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
		const char *fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("scene.bin");
		unsigned long size = 0;
		unsigned char *buff = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(fullPath, "rb", &size);
		Tools::Scene scene;
		scene.Read(buff, size);
		delete[] buff;
		Width = scene.GetWidth();
		Height = scene.GetHeight();
		GridSize = scene.GetGridSize();
		TranScale = scene.GetTransScale();

        {
            CSInitScene_S2C message;
            message.m_sceneID = 1;
            strcpy(message.m_sceneName, "scene.bin");
            message.Build(GetMessageType(CSInitScene_S2C), 0, sizeof(CSInitScene_S2C));
            Send(&message);
        }
        {
            ServerActor::Ptr actor = ServerActor::Ptr(new MainActor);
            m_serverActorMap.insert(std::make_pair(actor->GetID(), actor));

            actor->SetX(0);
            actor->SetY(0);

            actor->SycPosition();
        }
        for (int index = 0; index < 20; ++index)
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
        return (float)rand() / (float)RAND_MAX * Width;
    }
    int Server::RandY(void)
    {
        return (float)rand() / (float)RAND_MAX * Height;
    }

}