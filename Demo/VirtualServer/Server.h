//
//  Server.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#ifndef __Demo__Server__
#define __Demo__Server__

namespace Net
{
	struct IMessage;
    class Server
    {
    public:
    	void Receive(IMessage *message);
    	void Send(IMessage *message);

    	void Init(void);
    private:
    };
}

#endif /* defined(__Demo__Server__) */
