//
//  Server.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#ifndef __Demo__Server__
#define __Demo__Server__

#include <map>
#include "ServerActor.h"

namespace Net
{
	struct IMessage;
	class ServerActor;
    class Server
    {
    public:
    	Server(void);
    	~Server(void);
    	void Receive(IMessage *message);
    	void Send(IMessage *message) const;

    	void Init(void);

    	void Tick(float dt);
    	
    	static int RandX(void);
    	static int RandY(void);

		ServerActor::Ptr LookupActor(int id);
    private:
    private:
    	typedef std::map<int, ServerActor::Ptr> ServerActorMap;
    	ServerActorMap m_serverActorMap;

    public:
		static float Width;
		static float Height;
		static float GridSize;
		static float TranScale;//一米多少点
    };
}

#endif /* defined(__Demo__Server__) */
