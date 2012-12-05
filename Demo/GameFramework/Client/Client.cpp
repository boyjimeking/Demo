//
//  Client.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#include "Client.h"
#include "CSPipeline.h"
#include "WorldManager.h"
#include "Actors/ActorsControl.h"
#include "Terrain/TerrainProp.h"


namespace Net
{
	Client::Client(void)
	{
		CSPipeline::Instance()->AttachClient(this);
	}
    Client::~Client(void)
    {

    }
	void Client::Receive(IMessage *message)
	{
		switch (message->GetType())
		{
			case GetMessageType(CSInit_S2C):
				Init(message);
				break;
			default:
				//消息类型错误
				break;
		}
	}
    void Client::Send(IMessage *message)
    {
    	CSPipeline::Instance()->SendToServer(message);
    }

    void Client::Init(IMessage *message)
    {
    	CSInit_S2C *innerMessage = reinterpret_cast<CSInit_S2C*>(message);
    	Game::WorldManager::Instance()->GetActorsControl()->CreateActor(innerMessage->m_mainActorID, true);
    	Game::WorldManager::Instance()->GetTerrain()->Load("TestTerrain", "terrain");
    }
}