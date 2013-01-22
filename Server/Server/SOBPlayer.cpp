//
//  Player.cpp
//  Server
//
//  Created by xiangyu on 13-1-6.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//
#include <assert.h>
#include "SOBPlayer.h"
#include "SOBNpc.h"
#include "../../Demo/Tools/StreamHelper.h"
#include "../../Demo/Comm/CommDef.h"
#include "../../Demo/Comm/NetMessage.h"
#include "Tools.h"
#include "ISimulateLayer.h"

CPlayer::TPlayerMap CPlayer::m_playerMap;

CPlayer::CPlayer(CGameAccount* pAccount):
m_pAccount(pAccount)
{
    m_battleInfo.m_HP = 5;
    m_battleInfo.m_maxHP = 5;
    m_battleInfo.m_isAlive = true;
}

CPlayer::~CPlayer(void)
{
    m_playerMap.erase(GetID());
    m_observers.erase(GetID());
}

bool CPlayer::Init(void)
{
    SetID(GetLayer()->GeneratorId(enCPlayer));
    
    //initalize battle info
    m_battleInfo.m_HP = 5;
    m_battleInfo.m_maxHP = 5;
    m_battleInfo.m_isAlive = true;
    
    //actor initialize
    SetX(12.54f);
    SetY(6.66f);

    return true;
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

CPlayer* CPlayer::FindPlayer(u32 id)
{
    TPlayerMap::iterator it = m_playerMap.find(id);
    if(it == m_playerMap.end())
    {
        return 0;
    }
    
    return it->second;
}

void CPlayer::UpdateAll(u32 elps)
{
    for(TPlayerMap::iterator it = m_playerMap.begin(); it != m_playerMap.end(); ++it)
    {
        it->second->Update(elps);
    }
}

void CPlayer::ChangeEquip( void )
{
    TMsgChangeActorEquip_S2C msg;
    msg.m_actorID = GetID();
    msg.m_equipType = ENEquipType::enWeapon;
    strcpy(msg.m_equipName, "MainWeapon.ava");
    SendToClient(msg);
}

void CPlayer::Update(u32 elps)
{
    
}

bool CPlayer::Login(NetMessage* pMsg)
{
    dprint(Lg_Debug, "Login:%d\n",pMsg->GetType());
    MSG_PTR_CVT(p, TMsgLogin, pMsg);
    
    if(strcmp(p->m_userName, "111") != 0 && strcmp(p->m_password, "111") != 0)
    {
        dprint(Lg_Debug, "User(%s) Login failed!\n", p->m_userName);
        return false;
    }
    m_pAccount->m_username = p->m_userName;
    m_pAccount->m_password = p->m_password;
    
    if(Init() == false)
    {
        dprint(Lg_Debug, "The Player(%d) failed to initialize!\n", GetID());
        return false;
    }
    GetLayer()->PushObject(this);
    m_observers.insert(GetID());
    m_playerMap[GetID()] = this;
    
    //initialize the client
    TMsgInitScene_S2C msg;
    msg.m_sceneID = 1;
    strcpy(msg.m_sceneName, "Demo.pkm");
    SendToClient(msg);
    
    SycInfo();
    ChangeEquip();
    
    //syc npc
    CNpc::SycAll(this);
    
    return true;
}

bool CPlayer::AttackTarget_C2S(NetMessage* pMsg)
{
    dprint(Lg_Debug, "AttackTarget_C2S:%d\n", pMsg->GetType());
    MSG_PTR_CVT(p, TMsgAttackTarget_C2S, pMsg);
    
    ISimulateObject* obj = GetLayer()->LookupObject(p->m_targetID);
    OBJ_PTR_CVT(pUnit, IUnit, obj);
    if(!pUnit)
    {
        return false;
    }
    pUnit->BeAttacked(GetID());
    
    return true;
}
