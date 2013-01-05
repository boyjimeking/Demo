#include "GameServer.h"
#include "../CSProtocol/CSPipeline.h"
#include "../CSProtocol/CSMessageDef.h"
#include "IActor.h"
#include "../CCFileUtils.h"
#include "../Tools/Scene.h"
#include "Player.h"
#include "NPC.h"

namespace Server
{
	float GameServer::Width = 384.0f;
	float GameServer::Height = 192.0f;
	float GameServer::GridSize = 0.5f;
	float GameServer::TranScale = 10.0f;//一米多少点
	GameServer::GameServer(void)
	{

	}

	GameServer::~GameServer(void)
	{

	}

	void GameServer::Send( IMessage *message ) const
	{
		Net::CSPipeline::Instance()->SendToClient(message);
	}

	void GameServer::Process( IMessage *message )
	{
		switch (message->GetType())
		{
		default:
			ISimulateLayer::Receive(message);
			break;
		}
	}

	void GameServer::Init( void )
	{
		srand((unsigned int)this);

		const char *fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("Demo.pkm");
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
			strcpy(message.m_sceneName, "Demo.pkm");
			message.Build(GetMessageType(CSInitScene_S2C), 0, sizeof(CSInitScene_S2C));
			Send(&message);
		}
		{
			IActor::Ptr actor = Player::CreateObject();
			PushObject(actor);

			actor->SetX(12.54f);
			actor->SetY(6.66f);

			actor->SycInfo();
			actor->ChangeEquip();
		}
		for (int index = 0; index < 100; ++index)
		{
			IActor::Ptr actor = NPC::CreateObject();
			PushObject(actor);

			actor->SetX(21.8f);
			actor->SetY(10.9f);

			actor->SycInfo();
		}
	}

	int GameServer::RandX(void)
	{
		return (float)rand() / (float)RAND_MAX * 5.0f - 2.5f + 21.8f;
	}
	int GameServer::RandY(void)
	{
		return (float)rand() / (float)RAND_MAX * 5.0f - 2.5f + 10.9f;
	}

}