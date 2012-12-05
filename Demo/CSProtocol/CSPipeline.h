//
//  CSPipeline.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#ifndef __Demo__CSPipeline__
#define __Demo__CSPipeline__

namespace Net
{
	class Client;
	class Server;
	struct IMessage;

	class CSPipeline
	{
	public:
		static CSPipeline* Instance(void);
		CSPipeline(void);
		~CSPipeline();

		void AttachClient(Client *client);

		void SendToServer(IMessage *message);
		void SendToClient(IMessage *message);

		void Init(void);

		void Tick(float dt);
	
	private:
		Client *m_client;
		Server *m_server;
	};
}

#endif /* defined(__Demo__CSPipeline__) */
