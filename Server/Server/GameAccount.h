//
//  GameAccount.h
//  server
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#ifndef __server__GameAccount__
#define __server__GameAccount__

#include <vector>
#include <string.h>
#include "../../Demo/Comm/CommDef.h"
#include "../../Demo/Comm/CSession.h"

class CGameAccount;
class CPlayer;
typedef Net::CSession<CGameAccount> TSSession;
typedef Net::NetConnect<TSSession::_Sender, TSSession::_FastMutex>	SessionConnect;

class CGameAccount{
public:
    typedef std::map<int, CGameAccount*> TAccountMap;
    CGameAccount(SessionConnect* pConn);
    ~CGameAccount();
    

    
    void SendToClient(NetMessage& msg)
    {
        assert(m_pConn);
        m_pConn->SendMsg(&msg);
    }

    CPlayer* GetPlayer(void) { return m_pPlayer;}
    //
    static int      m_nIdGenerator;
    std::string     m_username;
    std::string     m_password;
    
private:
    int             m_nAccountId;
    CPlayer*        m_pPlayer;
    SessionConnect* m_pConn;
    static TAccountMap m_accounts;
};

#endif /* defined(__server__GameAccount__) */