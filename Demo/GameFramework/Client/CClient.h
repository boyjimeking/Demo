//
//  Client.h
//  client
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#ifndef __Demo__Client__H__
#define __Demo__Client__H__

#define __SERVER_MSG_DEFINITION__
#include "../../Comm/NetMessage.h"

class CClient{
public:
    CClient();
    
    //message handlers
    bool InitScene_S2C(NetMessage* pMsg);
    bool InitPlayer_S2C(NetMessage* pMsg);
    bool InitNPC_S2C(NetMessage* pMsg);
    bool ChangeActorEquip_S2C(NetMessage* pMsg);
    bool SycActor_S2C(NetMessage* pMsg);
    bool MoveTo_S2C(NetMessage* pMsg);
    bool AttackTarget_S2C(NetMessage* pMsg);
    bool Dead_S2C(NetMessage* pMsg);
    bool BeAttack_S2C(NetMessage* pMsg);
    
    //
    bool Login(const char*username, const char*password);
    void Attack( int targetID );
    
    //
    void SendMsg(NetMessage& msg);
    
    //properties
    bool IsLogined(void) { return m_bIsLogined;}
private:
    bool m_bIsLogined;
};

#endif //__Demo__Client__H__
