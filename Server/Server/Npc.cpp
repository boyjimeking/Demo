//
//  Npc.cpp
//  Server
//
//  Created by xiangyu on 13-1-7.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#include <assert.h>
#include "Npc.h"
#include "Player.h"
#include "../../Demo/Comm/NetMessage.h"
#include "AIControl.h"
#include "Tools.h"
#include "GameServer.h"
#include "ILayer.h"

CNpc::TNpcMap CNpc::m_npcMap;

CNpc::CNpc():
m_control(new AIControl)
{
    m_battleInfo.m_HP = 5;
    m_battleInfo.m_maxHP = 5;
    m_battleInfo.m_isAlive = true;
}

CNpc::~CNpc()
{
}


bool CNpc::Init(void)
{
    SetID(GetLayer()->GeneratorId(enCNpc));
    SetX(CGameServer::RandX());
    SetY(CGameServer::RandY());
    
    //initialize battle info
    m_battleInfo.m_HP = 5;
    m_battleInfo.m_maxHP = 5;
    m_battleInfo.m_isAlive = true;
    
    return true;
}

void CNpc::SycInfo( CPlayer *player )
{
    TMsgInitNPC_S2C msg;
    msg.m_actorID = GetID();
    msg.m_npcStaticID = 0;
    msg.m_x = GetX();
    msg.m_y = GetY();
    msg.m_battleInfo.Set(m_battleInfo);
    player->SendToClient(msg);
}

void CNpc::SycAll(CPlayer *player)
{
    TNpcMap::iterator it = m_npcMap.begin();
    while(it != m_npcMap.end())
    {
        it->second->SycInfo(player);
        ++it;
    }
}

void CNpc::UpdateAll(u32 elps)
{
    for(TNpcMap::iterator it = m_npcMap.begin(); it != m_npcMap.end(); ++it)
    {
        it->second->Update(elps);
    }
}

void CNpc::Update(u32 elps)
{
    m_control->Tick(*this, elps);
}

CNpc* CNpc::FindNpc(u32 id)
{
    TNpcMap::iterator it = m_npcMap.find(id);
    if(it == m_npcMap.end())
    {
        return NULL;
    }
    
    return it->second;
}

void CNpc::BeAttacked( int targetID )
{
    IUnit::BeAttacked(targetID);
    if (m_battleInfo.m_isAlive)
    {
        SetTarget(targetID);
        GetControl()->ChangeState(*this, ENNPCAIState::enAttack);
    }
}

void CNpc::Dead( void )
{
    m_battleInfo.m_isAlive = false;
    GetControl()->ChangeState(*this, ENNPCAIState::enDead);
}
