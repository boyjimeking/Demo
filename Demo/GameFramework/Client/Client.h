//
//  Client.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#ifndef __Demo__Client__
#define __Demo__Client__

#include "CSMessageDef.h"

namespace Net
{
    class Client
    {
    public:
    	Client(void);
    	~Client(void);

    	void Receive(IMessage *message);
    	void Send(IMessage *message);
    public:

    private:
    	void InitScene(IMessage *message);
    	void InitMainActor(IMessage *message);
        void SycActor(IMessage *message);
        void MoveActor(IMessage *message);
    };
}

#endif /* defined(__Demo__Client__) */
