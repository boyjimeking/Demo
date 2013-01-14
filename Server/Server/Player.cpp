//
//  Player.cpp
//  Server
//
//  Created by xiangyu on 13-1-6.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//
#include <assert.h>
#include "Player.h"
#include "Npc.h"
#include "../../Demo/Tools/StreamHelper.h"
#include "../../Demo/Comm/CommDef.h"
#include "../../Demo/Comm/NetMessage.h"
#include "Tools.h"

CPlayer::TPlayerMap CPlayer::m_playerMap;
u32 CPlayer::m_nIdGenerator = 10000;

CPlayer::CPlayer(u32 id, CGameAccount* pAccount):IUnit(id),
m_pAccount(pAccount)
{
    ++m_nIdGenerator;
     m_battleInfo.m_HP = 5;
    m_battleInfo.m_maxHP = 5;
    m_battleInfo.m_isAlive = true;
}

CPlayer::~CPlayer(void)
{
    TPlayerMap::iterator it = m_playerMap.find(m_nId);
    assert(it != m_playerMap.end());
    delete it->second;
    m_playerMap.erase(it);
}

CPlayer * CPlayer::CreateObj(u32 id, CGameAccount* pAccount)
{
    if(m_playerMap.find(id) != m_playerMap.end())
        return 0;
    
    CPlayer* p = new CPlayer(id, pAccount);
    if(!p->Init())
    {
        delete p;
        return 0;
    }
    m_playerMap[id] = p;
    
    return p;
}

bool CPlayer::Init(void)
{
    //initalize battle info
    m_battleInfo.m_HP = 5;
    m_battleInfo.m_maxHP = 5;
    m_battleInfo.m_isAlive = true;
    m_observers.insert(m_nId);
    
    return true;
}

CPlayer* CPlayer::FindPlayer(u32 id)
{
    TPlayerMap::iterator it = m_playerMap.find(id);
    if(it == m_playerMap.end())
    {
        return 0;
    }
    
    return it->second;
}

void CPlayer::SycInfo( void )
{
    TMsgInitPlayer_S2C msg;
    msg.m_actorID = GetID();
    msg.m_x = GetX();
    msg.m_y = GetY();
    msg.m_battleInfo.Set(m_battleInfo);
    SendToClient(msg);
}

void CPlayer::ChangeEquip( void )
{
    TMsgChangeActorEquip_S2C msg;
    msg.m_actorID = GetID();
    msg.m_equipType = ENEquipType::enWeapon;
    strcpy(msg.m_equipName, "MainWeapon.ava");
    SendToClient(msg);
}

void CPlayer::UpdateAll(u32 elps)
{
    for(TPlayerMap::iterator it = m_playerMap.begin(); it != m_playerMap.end(); ++it)
    {
        it->second->Update(elps);
    }
}

void CPlayer::Update(u32 elps)
{
    
}

void CPlayer::AttackTarget_C2S( NetMessage *pMsg )
{
    printf("AttackTarget_C2S:%d\n",pMsg->GetType());
    MSG_PTR_CVT(p, TMsgAttackTarget_C2S, pMsg);
    
    IUnit* pUnit = IUnit::FindUnit(p->m_targetID);
    if(!pUnit)
    {
        return ;
    }
    pUnit->BeAttacked(m_nId);
}
