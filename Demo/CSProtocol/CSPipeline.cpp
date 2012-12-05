//
//  CSPipeline.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#include "CSPipeline.h"
#include "stddef.h"
#include "../VirtualServer/Server.h"
#include "../GameFramework/Client/Client.h"

namespace Net
{
	CSPipeline* CSPipeline::Instance(void)
	{
		static CSPipeline *_ins = new CSPipeline;
		return _ins;
	}
	CSPipeline::CSPipeline(void)
	:m_client(NULL)
	,m_server(new Server)
	{

	}
	CSPipeline::~CSPipeline()
	{
		delete m_server;
	}

	void CSPipeline::AttachClient(Client *client)
	{
		m_client = client;
	}
	void CSPipeline::SendToServer(IMessage *message)
	{
		m_server->Receive(message);
	}
	void CSPipeline::SendToClient(IMessage *message)
	{
		m_client->Receive(message);
	}
	void CSPipeline::Init(void)
	{
		m_server->Init();
	}
	void CSPipeline::Tick(float dt)
	{
		m_server->Tick(dt);
	}
}