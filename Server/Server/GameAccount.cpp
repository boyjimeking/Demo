//
//  GameAccount.cpp
//  server
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#include <string.h>
#include "GameAccount.h"
#include "Player.h"
#include "Npc.h"
#include "Tools.h"

CGameAccount::TAccountMap CGameAccount::m_accounts;
int CGameAccount::m_nIdGenerator = 0;

CGameAccount::CGameAccount(SessionConnect* pConn):
m_pPlayer(new CPlayer(this))
{
    m_pConn = pConn;
    m_accounts[m_nIdGenerator++] = this;
    
}

CGameAccount::~CGameAccount()
{
    delete m_pPlayer;
}

