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

bool CGameAccount::Login(NetMessage* pMsg)
{
    dprint(Lg_Debug, "Login:%d\n",pMsg->GetType());
    MSG_PTR_CVT(p, TMsgLogin, pMsg);
    
    if(strcmp(p->m_userName, "111") != 0 && strcmp(p->m_password, "111") != 0)
    {
        dprint(Lg_Debug, "User(%s) Login failed!\n", p->m_userName);
        return false;
    }
    m_username = p->m_userName;
    m_password = p->m_password;
    
    //create an actor
    CPlayer *player = CPlayer::CreateObj(CPlayer::m_nIdGenerator, this);
    if(!p)
    {
        dprint(Lg_Debug, "Create a player (%d) failed!\n", CPlayer::m_nIdGenerator);
        return false;
    }
    //initialize the client
    TMsgInitScene_S2C msg;
    msg.m_sceneID = 1;
    strcpy(msg.m_sceneName, "Demo.pkm");
    SendToClient(msg);
    
    //actor initialize
    player->SetX(12.54f);
    player->SetY(6.66f);
    player->SycInfo();
    player->ChangeEquip();
   
    //syc npc
    CNpc::SycAll(player);
    
    m_pPlayer = player;
    
    return true;
}

bool CGameAccount::AttackTarget_C2S(NetMessage* pMsg)
{
    dprint(Lg_Debug, "AttackTarget_C2S:%d\n", pMsg->GetType());
    MSG_PTR_CVT(p, TMsgAttackTarget_C2S, pMsg);

    m_pPlayer->AttackTarget_C2S(pMsg);

    return true;
}

