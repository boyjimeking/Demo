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
    CGameAccount(SessionConnect* pConn):
    m_pPlayer(0)
    {
        m_pConn = pConn;
        m_accounts[m_nIdGenerator++] = this;
        
    }
    
    //handle message
    bool Login(NetMessage* pMsg);
    bool AttackTarget_C2S(NetMessage* pMsg);
    
    void SendToClient(NetMessage& msg)
    {
        assert(m_pConn);
        m_pConn->SendMsg(&msg);
    }

    CPlayer* GetPlayer(void) { return m_pPlayer;}
    //
    static int      m_nIdGenerator;
    
private:
    int             m_nAccountId;
    CPlayer*        m_pPlayer;
    std::string     m_username;
    std::string     m_password;
    SessionConnect* m_pConn;
    static TAccountMap m_accounts;
};

#endif /* defined(__server__GameAccount__) */
