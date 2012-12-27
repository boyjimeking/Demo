//
//  Client.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#ifndef __Demo__Client__
#define __Demo__Client__

#include "../../CSProtocol/CSMessageDef.h"

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
		void Attack(int targetID);
    private:
		void InitScene(IMessage *message);
		void ProcessCSInitPlayer_S2C(IMessage *message);
		void ProcessCSInitNPC_S2C(IMessage *message);
        void SycActor(IMessage *message);
        void MoveActor(IMessage *message);
		void ChangeActorEquip(IMessage *message);
		void ProcessCSAttackTarget_S2C(IMessage *message);
		void ProcessCSDead_S2C(IMessage *message);
		void ProcessCSBeAttack_S2C(IMessage *message);
    };
}

#endif /* defined(__Demo__Client__) */
