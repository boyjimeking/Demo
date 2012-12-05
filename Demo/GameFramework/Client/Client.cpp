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
#include "Actors/ActorProp.h"
#include "Terrain/TerrainProp.h"
#include "support/CCPointExtension.h"


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
			case GetMessageType(CSInitScene_S2C):
				InitScene(message);
				break;
			case GetMessageType(CSInitMainActor_S2C):
				InitMainActor(message);
				break;
			case GetMessageType(CSSycActor_S2C):
				SycActor(message);
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

    void Client::InitScene(IMessage *message)
    {
    	//CSInitScene_S2C *innerMessage = reinterpret_cast<CSInitScene_S2C*>(message);
    	Game::WorldManager::Instance()->GetTerrain()->Load("TestTerrain", "terrain");
    }
	void Client::InitMainActor(IMessage *message)
	{
    	CSInitMainActor_S2C *innerMessage = reinterpret_cast<CSInitMainActor_S2C*>(message);
    	Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->GetMainActor();
    	if (NULL == actor)
    	{
    		Game::WorldManager::Instance()->GetActorsControl()->CreateActor(innerMessage->m_mainActorID, innerMessage->m_x, innerMessage->m_y, true);
    	}
		else
		{
			actor->SetPosition(ccp(innerMessage->m_x, innerMessage->m_y));
		}
	}
	void Client::SycActor(IMessage *message)
	{
		CSSycActor_S2C *innerMessage = reinterpret_cast<CSSycActor_S2C*>(message);
		Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(innerMessage->m_actorID);
		if (NULL == actor)
		{
			Game::WorldManager::Instance()->GetActorsControl()->CreateActor(innerMessage->m_actorID, innerMessage->m_x, innerMessage->m_y);
		}
		else
		{
			actor->SetPosition(ccp(innerMessage->m_x, innerMessage->m_y));
		}
	}
}