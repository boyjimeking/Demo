//
//  Client.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#include "Client.h"
#include "../../CSProtocol/CSPipeline.h"
#include "WorldManager.h"
#include "Actors/ActorsControl.h"
#include "Actors/ActorProp.h"
#include "Terrain/TerrainProp.h"
#include "support/CCPointExtension.h"
#include "../CSProtocol/CSMessageType.h"


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
			case GetMessageType(CSChangeTarget_S2C):
				MoveActor(message);
				break;
			case GetMessageType(CSChangeActorEquip_S2C):
				ChangeActorEquip(message);
				break;
			case GetMessageType(CSAttackTarget_S2C):
				ProcessCSAttackTarget_S2C(message);
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
    	CSInitScene_S2C *innerMessage = reinterpret_cast<CSInitScene_S2C*>(message);
    	Game::WorldManager::Instance()->InitSceneByFile(innerMessage->m_sceneName);
    }
	void Client::InitMainActor(IMessage *message)
	{
    	CSInitMainActor_S2C *innerMessage = reinterpret_cast<CSInitMainActor_S2C*>(message);
    	Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->GetMainActor();
    	if (NULL == actor)
    	{
    		Game::WorldManager::Instance()->GetActorsControl()->CreateActor(ENActorType::enMain, innerMessage->m_mainActorID, innerMessage->m_x, innerMessage->m_y);
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
			Game::WorldManager::Instance()->GetActorsControl()->CreateActor(ENActorType::enMonster, innerMessage->m_actorID, innerMessage->m_x, innerMessage->m_y);
		}
		else
		{
			actor->SetPosition(ccp(innerMessage->m_x, innerMessage->m_y));
		}
	}
	void Client::MoveActor(IMessage *message)
	{
		CSChangeTarget_S2C *innerMessage = reinterpret_cast<CSChangeTarget_S2C*>(message);
		Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(innerMessage->m_actorID);
		if (NULL != actor)
		{
			actor->MoveTo(ccp(innerMessage->m_x, innerMessage->m_y));
		}
	}

	void Client::ChangeActorEquip( IMessage *message )
	{
		CSChangeActorEquip_S2C *innerMessage = reinterpret_cast<CSChangeActorEquip_S2C*>(message);
		Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(innerMessage->m_actorID);
		if (NULL != actor)
		{
			actor->ChangeEquip((ENEquipType::Decl)innerMessage->m_equipType, innerMessage->m_equipName);
		}
	}

	void Client::Attack( int targetID )
	{
		CSAttackTarget_C2S message;
		message.m_actorID = Game::WorldManager::Instance()->GetActorsControl()->GetMainActor()->GetID();
		message.m_targetID = targetID;
		message.Build(GetMessageType(CSAttackTarget_C2S), message.m_actorID, sizeof(CSAttackTarget_C2S));
		Send(&message);
	}

	void Client::ProcessCSAttackTarget_S2C( IMessage *message )
	{
		CSAttackTarget_S2C *innerMessage = reinterpret_cast<CSAttackTarget_S2C*>(message);
		Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(innerMessage->m_actorID);
		Game::ActorProp *target = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(innerMessage->m_targetID);
		if (NULL == actor || NULL == target)
		{
			return;
		}
		actor->Attack(target);
	}

}