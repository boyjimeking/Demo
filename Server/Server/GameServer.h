//
//  Server.h
//  server
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#ifndef __server__Server__
#define __server__Server__

#define __CLIENT_MSG_DEFINITION__

#include "../../Demo/Comm/CommDef.h"
#include "../../Demo/Comm/NetMessage.h"
#include "GameAccount.h"

class CGameServer{
public:
    //message handlers
    #define _SE_En_Decl_V_(name,value,check1,check2,check3) \
    bool name(CGameAccount* pAccount, NetMessage* pMsg){\
    return pAccount->name(pMsg);\
    }
#include "../../Demo/Comm/ClientMsgDef.h"

    
    static CGameServer* Instance(void)
    {
        static CGameServer* inst= 0;
        if(!inst)
        {
            inst=new CGameServer;
        }
        return inst;
    }
    bool Init(void);
    void Update(u32 elps);
    
    static float Width;
    static float Height;
    static float GridSize;
    static float TranScale;//一米多少点
 
    static int RandX(void);
    static int RandY(void);
    

};

#endif /* defined(__server__Server__) */
